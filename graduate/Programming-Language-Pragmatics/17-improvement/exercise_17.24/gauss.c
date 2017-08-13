/* Exercise 17.24 */

#include <stdio.h>

#define N 3

double A[N][N] = {
    {2, 3, 5},
    {5, 1, 3},
    {7, 2, 6}
};

int main() {
    int i, j, k;
    int n = N;

    for (i = 0; i < n-1; i++) {
        for (j = i+1; j < n; j++) {
            for (k = n-1; k >= i; k--) {
                A[j][k] -= A[i][k] * A[j][i] / A[i][i];
            }
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%2.2f\t", A[i][j]);
        }
        printf("\n");
    }
}
