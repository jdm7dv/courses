// Example 9.32 (run with "go run rtn.go")

package main

import "fmt"

func A_max(A []int) (rtn int) {
    rtn = A[0]
    for i := 1; i < len(A); i++ {
        if A[i] > rtn { rtn = A[i] }
    }
    return
}

func main() {
    a := []int{3, 5, -2, 8, 6, 0}
    fmt.Println(A_max(a))
}
