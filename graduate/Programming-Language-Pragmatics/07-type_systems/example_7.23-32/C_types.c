/* Examples 7.27 and 7.30, Sidebar 7.6 */

#include <stdio.h>

int main() {
    float r;
    int n;

    short int s;
    unsigned long int l;
    char c;     /* may be signed or unsigned -- implementation-dependent */
    float f;    /* usually IEEE single-precision */
    double d;   /* usually IEEE double-precision */

    union {
        float r;
        int n;
    } u;

    n = 10;
    r = (float) n;  /* generates code for run-time conversion */
    printf("%d %f\n", n, r);

    r = 10.0;
    n = (int) r;    /* also run-time conversion, with no overflow check */
    printf("%f %d\n", r, n);

    /* Unions can be used to obtain a non-converting type cast;
       this is Exercise 7.9 */

    s = l;  /* l's low-order bits are interpreted as a signed number. */
    l = s;  /* s is sign-extended to the longer length, then
               its bits are interpreted as an unsigned number. */
    s = c;  /* c is either sign-extended or zero-extended to s's length;
               the result is then interpreted as a signed number. */
    f = l;  /* l is converted to floating-point. Since f has fewer
               significant bits, some precision may be lost. */
    d = f;  /* f is converted to the longer format; no precision lost. */
    f = d;   /* d is converted to the shorter format; precision may be lost.
               If d's value cannot be represented in single-precision, the
               result is undefined, but NOT a dynamic semantic error. */

    n = 1234567890;
    r = *((float *) &n);
    printf("%d %f\n", n, r);
}
