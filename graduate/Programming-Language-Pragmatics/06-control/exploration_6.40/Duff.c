/* Exploration 6.40 */

#include <stdio.h>

int A[50] = {50, 24, 58, 42, 19, 37, 38, 40, 29, 60,
               43, 22, 39, 46, 42, 35, 57, 18, 25, 27,
               36, 37, 29, 32, 30, 30, 39, 38, 27, 37,
               41, 43, 28, 53, 57, 52, 40, 39, 41, 43,
               36, 34, 29, 28, 37, 45, 48, 28, 33, 40};
int N = 50;

int main() {
    double sum = 0, squares = 0;
    double average;
    int i;
    int j;

    /* original: */
    sum = 0;
    squares = 0;
    i = 0;
    do {
        sum += A[i]; squares += A[i] * A[i]; i++;
    } while (i < N);
    average = sum/N;
    printf ("%.2f, %f\n", average, squares/N - (average * average));

    /* unrolled: */
    sum = 0;
    squares = 0;
    i = 0; j = N/4;
    do {
        sum += A[i]; squares += A[i] * A[i]; i++;
        sum += A[i]; squares += A[i] * A[i]; i++;
        sum += A[i]; squares += A[i] * A[i]; i++;
        sum += A[i]; squares += A[i] * A[i]; i++;
    } while (--j > 0);
    do {
        sum += A[i]; squares += A[i] * A[i]; i++;
    } while (i < N);
    average = sum/N;
    printf ("%.2f, %f\n", average, squares/N - (average * average));

    /* Duff's device: */
    sum = 0;
    squares = 0;
    i = 0; j = (N+3)/4;
    switch (N%4) {
        case 0: do{ sum += A[i]; squares += A[i] * A[i]; i++;
        case 3:     sum += A[i]; squares += A[i] * A[i]; i++;
        case 2:     sum += A[i]; squares += A[i] * A[i]; i++;
        case 1:     sum += A[i]; squares += A[i] * A[i]; i++;
                } while (--j > 0);
    }
    average = sum/N;
    printf ("%.2f, %f\n", average, squares/N - (average * average));
}
