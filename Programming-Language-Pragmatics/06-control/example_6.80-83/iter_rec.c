/* Examples 6.80 through 6.83 */

#include <stdio.h>

int square(int i) {
    return i * i;
}

typedef int (*int_func) (int);
int summation(int_func f, int low, int high) {
    /* assume low <= high */
    int total = 0;
    int i;
    for (i = low; i <= high; i++) {
        total += f(i);
    }
    return total;
}

int gcd(int a, int b) {
    /* assume a, b > 0 */
    if (a == b) return a;
    else if (a > b) return gcd(a-b, b);
    else return gcd(a, b-a);
}

int summation2(int_func f, int low, int high) {
    /* assume low <= high */
    if (low == high) return f(low);
    else return f(low) + summation(f, low+1, high);
}

int gcd2(int a, int b) {
    /* assume a, b > 0 */
    while (a != b) {
        if (a > b) a = a-b;
        else b = b-a;
    }
    return a;
}

int gcd3(int a, int b) {
    /* assume a, b > 0 */
start:
    if (a == b) return a;
    else if (a > b) {
        a = a-b;  goto start;
    } else {
        b = b-a;  goto start;
    }
}

int main () {
    printf("iterative sum of squares from 1 to 10: %d\n",
            summation(square, 1, 10));
    printf("recursive gcd of 24 and 40: %d\n", gcd(24, 40));
    printf("recursive sum of squares from 1 to 10: %d\n",
            summation2(square, 1, 10));
    printf("iterative gcd of 24 and 40: %d\n", gcd2(24, 40));
    printf("tail-recursive gcd of 24 and 40: %d\n", gcd3(24, 40));
}
