/* Examples 7.10 and 7.12 */

#include <stdio.h>

enum weekday {sun, mon, tue, wed, thu, fri, sat};

typedef int weekday2;
const weekday2 sun2 = 0, mon2 = 1, tue2 = 2,
               wed2 = 3, thu2 = 4, fri2 = 5, sat2 = 6;

/* The (insignificant) difference between these is that
    'weekday' is an enum tag; 'weekday2' is a type name. */

enum arm_special_regs {fp = 7, sp = 13, lr = 14, pc = 15};

int main() {
    printf("%d %d %d\n", mon, mon2, fp);
}
