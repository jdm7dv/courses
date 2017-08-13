/* Examples 3.43 and 3.44 */

#include <stdio.h>

#define LINE_LEN 80
#define DIVIDES(a,n) (!((n) % (a)))
    /* true iff n has zero remainder modulo a */
#define SWAP(a,b) {int t = (a); (a) = (b); (b) = t;}
#define MAX(a,b) ((a) > (b) ? (a) : (b))

int main() {
    int y = 2;
    int z = 3;

    printf("%d %d\n", y, z);
    SWAP(y,z);
    printf("%d %d\n", y, z);

    int x = 15;
    if (DIVIDES(y + z, x)) {
        printf("%d divides %d\n", y + z, x);
    } else {
        printf("%d does not divide %d\n", y + z, x);
    }

    printf("%d %d\n", x, y);
    z = MAX(x++, y++);
    printf("%d %d %d -- oops!\n", x, y, z);
}
