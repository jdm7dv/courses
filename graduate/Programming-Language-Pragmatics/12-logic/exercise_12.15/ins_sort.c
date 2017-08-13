/* Exercise 12.15 */

#include <stdio.h>

void insertion_sort(int A[], int N)
{
    int i, j, t;
    for (i = 1; i < N; i++) {
        t = A[i];
        for (j = i; j > 0; j--) {
            if (t >= A[j-1]) break;
            A[j] = A[j-1];
        }
        A[j] = t;
    }
}

int main() {
    int i;
    int A[] = {8, 4, 2, 9, 3, 6, 6, 5};
    insertion_sort(A, 8);
    for (i = 0; i < 8; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}
