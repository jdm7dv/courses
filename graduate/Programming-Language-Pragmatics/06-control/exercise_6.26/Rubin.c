/* Exercise 6.26 */

#include <stdio.h>

#define n 10

int A[n][n] = {
    1, 2, 3, 4, 5, 6, 7, 8, 9, 0,       /* row 0 */
    1, 2, 3, 4, 5, 6, 7, 8, 9, 0,
    1, 2, 3, 4, 5, 6, 7, 8, 9, 0,
    1, 2, 3, 4, 5, 6, 7, 8, 9, 0,
    1, 2, 3, 4, 5, 6, 7, 8, 9, 0,
    1, 2, 3, 4, 5, 6, 7, 8, 9, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0,       /* row 6 */
    1, 2, 3, 4, 5, 6, 7, 8, 9, 0,
    1, 2, 3, 4, 5, 6, 7, 8, 9, 0,
    1, 2, 3, 4, 5, 6, 7, 8, 9, 0,
};

int main() {
    int first_zero_row = -1;        /* none */
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (A[i][j]) goto next;
        }
        first_zero_row = i;
        break;
    next: ;
    }
    printf("row %d\n", i);
}
