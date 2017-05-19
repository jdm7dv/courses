/* Example 8.11 */

#include <stdio.h>
#include <stdint.h>

int main() {
    struct {
        int i;
        double d;
        _Bool b;
    } S;
    union {
        int i;
        double d;
        _Bool b;
    } U;
    printf("%lu %lu %lu\n", (uintptr_t) &S.i, (uintptr_t) &S.d,
                            (uintptr_t) &S.b);  /* all different */
    printf("%lu %lu %lu\n", (uintptr_t) &U.i, (uintptr_t) &U.d,
                            (uintptr_t) &U.b);  /* all the same */
}
