// Example 3.4 (Figure 3.3)

#include <stdio.h>

/*
    Place into *s a new name beginning with the letter 'L' and
    continuing with the ASCII representation of a unique integer.
    Parameter s is assumed to point to space large enough to hold any
    such name; for the short ints used here, 7 characters suffice.
*/
void label_name (char *s) {
    static short int n;         /* C guarantees that static locals
                                    are initialized to zero */
    sprintf (s, "L%d\0", ++n);  /* "print" formatted output to s */
}

int main () {
    char a[10], b[10], c[10];
    label_name (a);
    label_name (b);
    label_name (c);

    printf ("%s\n%s\n%s\n", a, b, c);
}
