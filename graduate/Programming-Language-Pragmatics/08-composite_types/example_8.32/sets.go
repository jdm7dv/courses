// Example 8.32
// compile and run with "go run sets.go"

package main

import "fmt"

func main() {
    my_set := make(map[int]bool)    // mapping from int to bool
    my_set[2] = true                // inserts <3, true> in mapping
    my_set[3] = true
    my_set[5] = true
    delete(my_set, 3)               // removes <i, true>, if present
          // reclaims the space; my_set[3] = false wouldn't do that
    if my_set[2] {
        fmt.Println("2 is present");    // yup
    }
    if my_set[3] {
        fmt.Println("3 is present");    // nope
    }
    if my_set[5] {
        fmt.Println("5 is present");    // yup
    }
}
