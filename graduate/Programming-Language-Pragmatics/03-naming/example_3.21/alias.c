// Example 3.21

#include "stdio.h"

extern int* get_ptr(int* p);

int main() {
    int a, b, *p, *q;
    int x = 10;
    p = get_ptr(&x);
    q = get_ptr(&x);
    // Compiler has no way to tell if p and q point at the same object.

    a = *p;     // 10
    *q = 3;
    b = *p;     // 3

    printf("%d, %d\n", a, b);
}
