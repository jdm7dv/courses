/* Examples 8.44 through 8.48, including sidebar 8.7 */

#include <stdio.h>
#include <stdlib.h>

void foo(int a[], int *b,               /* equivalent */
         int *c[], int **d,             /* equivalent -- row pointers */
         int e[][10], int (*f)[10]);    /* equivalent -- contiguous */
      /* int g[][], int (*h)[]             erroneous */

double determinant(int rows, int cols, double M[rows][cols]) {
    int i, j;

    double val = M[i][j];

    double *N;
    val = *(N + (i * cols) + j);    /* backward-compatible equivalent */
    return val;
}

void p1(int *a[]) { }       /* 2D array of ints, row-pointer layout */
void p2(int **a) { }        /* equivalent declaration */

void q1(int m, int a[][m]) { }      /* 2D array, contiguous layout */
void q2(int m, int (*a)[m]) {       /* equivalent declaration */
    printf("%lu\n", sizeof(*a));     /* 4m */
}
void q3(int len) {
    int A[len];
    printf("%lu\n", sizeof(A));
}

// void r1(int a[][]) { }           /* invalid */
// void r1(int m, int a[m][]) { }   /* invalid */

// void r2(int (*a)[]) {        /* invalid */
//     a[2][3] = 4;             /* gcc complains here, though,
// }                            /* not at the function header */

int get_acct_num(FILE *s) {
    char buf[100];
    char *p = buf;
    do {
        /* read from stream s: */
        *p = getc(s);
    } while (*p++ != '\n');
    *p = '\0';
    /* convert ascii to int: */
    return atoi(buf);
}

int main() {
    int n;
    int *a, *p;     /* pointer to integer */
    int b[10];      /* array of 10 integers */
    int c[10][10];  /* 10x10 two-dimensional array */
    int *d[10];     /* row of 10 pointers to integers */

    double *e;          /* pointer to double */
    double (*f)[10];    /* pointer to array of 10 doubles */

    int g[][2] = {{1, 2}, {3, 4}, {5, 6}};  // three rows

    int (*h)[10];

    a = b;          /* make a point to the initial element of b */
    n = a[3];
    n = *(a+3);     /* equivalent to previous line */
    n = b[3];
    n = *(b+3);     /* equivalent to previous line */

    b[3] = 3;
    printf("%d\n", 3[b]);

    a = &b[2];
    p = &b[4];
    printf("a %s p\n", a < p ? "<" : ">=");     /* < */
    printf("p - a = %ld\n", p - a);             /* 4 - 2 = 2 */

    c[2][3] = 4;
    printf("%d %d\n", (*(c+2))[3], *(*(c+2)+3));

    printf("%lu\n", sizeof(g));     /* 3 x 2 x 4  = 24 bytes */

    printf("%lu %lu %lu %lu %lu\n", sizeof(e), sizeof(f), sizeof(*e),
                                    sizeof(*f[0]), sizeof(*f));

    printf("%d\n", get_acct_num(stdin));
        /* feed this more than 100 characters and see what happens! */

    q2(10, h);      /* prints 40 */
    q3(10);         /* prints 40 */
}
