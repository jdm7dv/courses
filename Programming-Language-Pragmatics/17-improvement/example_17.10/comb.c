/* Example 17.10 */

#include <stdio.h>
#include <stdlib.h>

void combinations(int n, int *A) {
    int i, t;
    A[0] = 1;
    A[n] = 1;
    t = 1;
    for (i = 1; i <= n/2; i++) {
        t = (t * (n+1-i)) / i;
        A[i] = t;
        A[n-i] = t;
    }
}

int A[256];

int main(int argc, char **argv) {
    int n = atoi(argv[1]);          /* number of rows to print */
    int i, j;
    
    for (i = 0; i <= n; i++) {
        combinations(i, A);
        for (j = 0; j<=i; j++) {
            printf("%d\t", A[j]);
        }
        printf("\n");
    }
}
