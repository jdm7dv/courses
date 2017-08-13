/* Example 1.4 (Figure 1.2) */

#include <stdio.h>

int gcd(int a, int b) {
    while (a != b) {
        if (a > b) a = a - b;
        else b = b - a;
    }
    return a;
}

int main()
{
    int i, j;

    scanf("%d %d", &i, &j);

    printf("%d\n", gcd(i, j));
}
