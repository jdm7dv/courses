/* Example 9.23 */

#include <stdio.h>

void apply_to_A(int (*f)(int), int A[], int A_size)
{
    int i;
    for (i = 0; i < A_size; i++) A[i] = f(A[i]);
}

int print(int i) {
    printf("%d\n", i);
    return i;
}

int main() {
    int B[6] = {5, 6, 7, 8, 9, 10};

    apply_to_A(print, B, 6);
}
