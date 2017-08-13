/* Example 6.86 */

#include <stdio.h>

int fib(int n) {
    int f1 = 1; int f2 = 1;
    int i;
    for (i = 2; i <= n; i++) {
        int temp = f1 + f2;
        f1 = f2; f2 = temp;
    }
    return f2;
}

int main() {
    printf("30th Fibonacci number: %d\n", fib(30));
}
