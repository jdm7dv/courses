/* Examples 9.13 and 9.14 */

#include <stdio.h>

void swap(int *a, int *b) { int t = *a; *a = *b; *b = t; }

typedef struct {
    int A[1000];
} huge_record;

void append_to_log(const huge_record* r) {
    /* r->A[0]++;   not allowed! */
    r = 0;      /* ok: r is not const, the record it points to is const */
}

int main() {
    int v1 = 2;
    int v2 = 3;
    printf("%d %d\n", v1, v2);
    swap(&v1, &v2);
    printf("%d %d\n", v1, v2);

    huge_record R;
    append_to_log(&R);
}
