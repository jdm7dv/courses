/* Examples 8.78, 8.79, and 8.80 */

#include <stdio.h>
#include <string.h>

char s[20] = "abcdefghijklmnopqrs";
int n = 3;
double r[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

int main() {
    int i;

    FILE *my_file = fopen("out", "w");
    /* should check to make sure fopen worked */

    fprintf(my_file, "%20s%10d", s, n);
    for (i = 0; i < 10; i++) fprintf(my_file, "%8.2f", r[i]);
    fprintf(my_file, "\n");

    {
        char *fmt = "%s score and %d years ago\n";
        strcpy(s, "four");      /* copy "four" into s */
        n = 20;
        fprintf(my_file, fmt, s, n);
    }

    fprintf(my_file, "%d%%\n", 25);     /* prints "25%" */

    fscanf(stdin, "%19s %d %lf", s, &n, &r[0]);
    printf("%s %d %g\n", s, n, r[0]);
}
