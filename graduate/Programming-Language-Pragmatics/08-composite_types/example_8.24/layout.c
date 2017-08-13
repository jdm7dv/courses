/* Example 8.24 */

#include <stdio.h>

char days1[][10] = {        /* contiguous layout */
    "Sunday", "Monday", "Tuesday",
    "Wednesday", "Thursday",
    "Friday", "Saturday"
};

char *days2[] = {           /* row-pointer layout */
    "Sunday", "Monday", "Tuesday",
    "Wednesday", "Thursday",
    "Friday", "Saturday"
};

int main() {
    /* note identical syntax in the following */

    printf("%s\n", days1[2][3] == 's' ? "yes" : "no");      /* in Tuesday */
    printf("%s\n", days2[2][3] == 's' ? "yes" : "no");      /* in Tuesday */
}
