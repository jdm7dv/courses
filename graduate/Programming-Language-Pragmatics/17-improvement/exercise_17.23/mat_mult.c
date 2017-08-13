/* Exercise 17.23 */

#include <stdio.h>

#define N 2

int A[N][N] = {
    {2, 3},
    {5, 1}
};
int B[N][N] = {
    {1, 2},
    {3, 4}
};
int C[N][N];

int main() {
    int i, j, k;
    int n = N;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            C[i][j] = 0;
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            for (k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d\t", C[i][j]);
        }
        printf("\n");
    }
}
