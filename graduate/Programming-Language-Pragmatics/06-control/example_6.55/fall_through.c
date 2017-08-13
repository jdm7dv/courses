/* Example 6.55 */

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {
    char c;
    enum {upper, lower, unknown} letter_case = lower;
    char *enum_names[] = {"upper", "lower", "unknown"};

    if (argc != 2) {
        printf("usage: fall_through key\n");
        exit(1);
    }
    c = argv[1][0];

    switch (c) {
        case 'A' :
            letter_case = upper;
        case 'a' :
            printf("Got an 'A' or 'a'\n");
            break;
        case 'B' :
            letter_case = upper;
        case 'b' :
            printf("Got a 'B' or 'b'\n");
            break;
        case 'C' :
            letter_case = upper;
        case 'c' :
            printf("Got a 'C' or 'c'\n");
            break;
        default :
            letter_case = unknown;
    }
    printf("It was %s case\n", enum_names[letter_case]);
}
