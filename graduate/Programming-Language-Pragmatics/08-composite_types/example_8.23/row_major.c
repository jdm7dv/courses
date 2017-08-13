/* Example 8.23 */

#define N 100
int A[N][N];

int main() {
    int i, j;

    /* fast: */
    for (i = 0; i < N; i++) {       /* rows */
        for (j = 0; j < N; j++) {   /* columns */
            A[i][j] = i * j;
        }
    }

    /* slow: */
    for (j = 0; j < N; j++) {       /* columns */
        for (i = 0; i < N; i++) {   /* rows */
            A[i][j] = i * j;
        }
    }
}
