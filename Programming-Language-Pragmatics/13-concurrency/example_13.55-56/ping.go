// Examples 13.55 and 13.56

package main

func producer(c1 chan int) {
    c1 <- 1
    c1 <- 2
    c1 <- 3
}

func consumer(c1 chan int, c2 chan int) {
    println(<-c1)
    println(<-c1)
    var n, ok = <-c1
    println(n, ok)
    c2 <- 0
}

type request struct {
    name string
    reply_to chan string
}

func server(entry chan request) {
    for {
        var req = <-entry
        switch(req.name) {
        case "Alice":
            req.reply_to <- "123-456-7890"
        case "Bob":
            req.reply_to <- "585-234-5678"
        case "":
            return
        default:
            req.reply_to <- "??"
        }
    }
}

func main() {
    var c1 chan int
    c1 = make(chan int)
    var c2 = make(chan int)
    go producer(c1)
    go consumer(c1, c2)
    <-c2    // wait until consumer is done

    var service chan request = make(chan request)
    go server(service)
    var c = make(chan string, 1)
    service <- request{"Alice", c}
    println(<-c)
    service <- request{"", nil}     // tell service to terminate
}
