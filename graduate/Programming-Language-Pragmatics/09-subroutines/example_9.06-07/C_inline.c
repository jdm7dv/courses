/* Example 9.6 */

#include <stdio.h>

#define MAX(a,b) ((a) > (b) ? (a) : (b))

static inline int max(int a, int b) { return a > b ? a : b; }

int main() {
    int x = 10;
    int y = 20;

    printf("%d\n", max(x++, y++));
    printf("%d %d\n", x, y);

    printf("%d\n", MAX(x++, y++));
    printf("%d %d\n", x, y);
}
