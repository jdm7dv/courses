// Example 13.64 (Figure 13.25)

package main

type bdata struct {
    n int   // or whatever
}

func producer(buf chan bdata, done chan bool) {
    for i := 0; i < 10; i++ {
        buf <- bdata{i}
    }
    done <- true
}

func consumer(buf chan bdata , done chan bool) {
    for i := 0; i < 10; i++ {
        println((<-buf).n)
    }
    done <- true
}

const SIZE = 3
type buffer struct {
    full_slots, next_full, next_empty int
    buf [SIZE]bdata
    insert_c chan bdata
    remove_c chan chan bdata
}
func manager(b *buffer) {
    var ic chan bdata = b.insert_c
    var rc chan chan bdata = nil
    for {
        select {  // at least one of ic and rc will always be non-nil
          case d := <-ic:       // := means "declare and initialize"
            b.buf[b.next_empty] = d
            b.next_empty = (b.next_empty + 1) % SIZE
            b.full_slots++
            rc = b.remove_c     // there is definitely data to remove
            if b.full_slots == SIZE { ic = nil }
          case c := <-rc:
            c <- b.buf[b.next_full]
            b.next_full = (b.next_full + 1) % SIZE
            b.full_slots--
            ic = b.insert_c     // there is definitely space to fill
            if b.full_slots == 0 { rc = nil }
        }
    }
}
func make_buffer() (b *buffer) {    // return value has name 'b'
    b = new(buffer)
    b.full_slots = 0
    b.next_full = 0
    b.next_empty = 0
    b.insert_c = make(chan bdata)
    b.remove_c = make(chan chan bdata)
    go manager(b)               // create active manager thread
    return
}
func (b *buffer) insert(e bdata) {
    b.insert_c <- e             // send data to manager
}
func (b *buffer) remove() bdata {
    var c = make(chan bdata)
    b.remove_c <- c             // send temporary channel to manager
    return <-c                  // receive and return response
}

func producer2(b *buffer, done chan bool) {
    for i := 0; i < 10; i++ {
        b.insert(bdata{i})
    }
    done <- true
}

func consumer2(b *buffer, done chan bool) {
    for i := 0; i < 10; i++ {
        println(b.remove().n)
    }
    done <- true
}

func main() {
    var buf = make(chan bdata, 3)       // bounded buffer is a channel
    var done = make(chan bool, 2)       // to signal completion
    go producer(buf, done)
    go consumer(buf, done)
    <-done
    <-done

    var b = make_buffer()
    go producer2(b, done)
    go consumer2(b, done)
    <-done
    <-done
}
