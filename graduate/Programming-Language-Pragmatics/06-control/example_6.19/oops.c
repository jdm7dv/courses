/* Example 6.19 */

#include <stdio.h>

int main() {
    int a = 3;
    int b = 4;

    if (a == b) {
        printf("a and b are equal\n");
    }
    if (a = b) {                            /* oops */
        printf("a and b are equal?\n");
    }
}
