/* Examples 6.20-6.24 */

#include <stdio.h>

int plus7(int i) { return i + 7; }

void update(int A[], int index_fn(int n)) {
    int i, j;
    /* calculate i */       i = 20;
    j = index_fn(i);
    A[j] = A[j] + 1;
}

void update2(int A[], int index_fn(int n)) {
    int i, j;
    /* calculate i */       i = 20;
    j = index_fn(i);
    A[index_fn(i)] += 1;
}

void update3(int A[], int index_fn(int n)) {
    int i, j;
    /* calculate i */       i = 20;
    j = index_fn(i);
    A[index_fn(i)]++;
}

void update4(int A[], int index_fn(int n)) {
    int i, j;
    /* calculate i */       i = 20;
    j = index_fn(i);
    ++A[index_fn(i)];
}

#define N 100

int main() {
    int a = 3;
    int e = 4;
    struct {
        struct {
            int d;
        } c[10];
    } b;
    int A[N];

    b.c[3].d = 5;

    printf ("a is %d; b.c[3].d is %d\n", a, b.c[3].d);
    fflush(stdout);

    a = a + 1;
    b.c[3].d = b.c[3].d * e;

    printf ("a is %d; b.c[3].d is %d\n", a, b.c[3].d);
    fflush(stdout);

    a += 1;
    b.c[3].d *= e;

    printf ("a is %d; b.c[3].d is %d\n", a, b.c[3].d);
    fflush(stdout);

    A[27] = 1;
    update(A, plus7);
    printf("%d\n", A[27]);
    fflush(stdout);

    update2(A, plus7);
    printf("%d\n", A[27]);
    fflush(stdout);

    update3(A, plus7);
    printf("%d\n", A[27]);
    fflush(stdout);

    update4(A, plus7);
    printf("%d\n", A[27]);
    fflush(stdout);

    {
        int i, s;
        int *p, *q, *t1, *t2;
        int b = -1;
        int B[N];

        for (i = 0; i < N; i++) { B[i] = -i; }

        for (i = 0; i < N; i++) { A[i] = i; }
        i = 3;
        p = &A[7];
        q = &B[7];
        A[i--] = b;
        *p++ = *q++;
        for (i = 0; i < 10; i++) printf("%d  ", A[i]);
        printf("\n");
        fflush(stdout);

            /* alternatively: */
            for (i = 0; i < N; i++) { A[i] = i; }
            i = 3;
            p = &A[7];
            q = &B[7];
            A[s = i, i -= 1, s] = b;
            *(t1 = p, p += 1, t1) = *(t2 = q, q += 1, t2);
            for (i = 0; i < 10; i++) printf("%d  ", A[i]);
            printf("\n");
            fflush(stdout);

        for (i = 0; i < N; i++) { A[i] = i; }
        i = 3;
        p = &A[7];
        q = &B[7];
        A[--i] = b;
        *(++p) = *(++q);
        for (i = 0; i < 10; i++) printf("%d  ", A[i]);
        printf("\n");
        fflush(stdout);

            /* alternatively: */
            for (i = 0; i < N; i++) { A[i] = i; }
            i = 3;
            p = &A[7];
            q = &B[7];
            A[i -= 1] = b;
            *(p += 1) = *(q += 1);
            for (i = 0; i < 10; i++) printf("%d  ", A[i]);
            printf("\n");
            fflush(stdout);
    }
}
