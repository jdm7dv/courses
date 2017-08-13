/* Example 6.33 */

#include <stdio.h>

int main () {
    union {
        float f;
        int i;
    } a, b, c, d, e;

    a.f = 0.1;

/*
    b.i = 0x3dcccccc;
    b.f = -b.f;
*/
    b.i = 0xbdcccccc;

    printf ("a = %x %e\n", a.i, a.f);
    printf ("b = %x %e\n\n", b.i, b.f);

    c.f = (float) (a.f + b.f);
    printf ("a + b = %x %e\n\n", c.i, c.f);

    d.f = (float) (a.f * (float) 10.0);
    e.f = (float) (b.f * (float) 10.0);

    printf ("a*10 = %x %e\n", d.i, d.f);
    printf ("b*10 = %x %e\n\n", e.i, e.f);

    d.f = (float) (a.f + b.f) * (float) 10.0;
    e.f = (float) (a.f * (float) 10.0) + (float) (b.f * (float) 10.0);

    printf ("(a+b)*10 = %x %e\n", d.i, d.f);
    printf ("(a*10) + (b*10) = %x %e\n", e.i, e.f);
}
