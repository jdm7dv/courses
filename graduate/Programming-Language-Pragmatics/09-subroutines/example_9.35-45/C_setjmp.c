/* Example 9.45 */

#include <setjmp.h>
#include <stdio.h>

int main() {
    jmp_buf buffer;
    if (!setjmp(buffer)) {
        /* protected code */
        printf("In protected code\n");
        longjmp(buffer, 1);
        printf("After longjmp\n");
    } else {
        /* handler */
        printf("In handler\n");
    }

    for (int i = 1; i <= 2; ++i) {
        switch (setjmp(buffer)) {
          case 0:
            /* protected code */
            printf("In protected code\n");
            longjmp(buffer, i);
            break;
          case 1:
            /* handler 1 */
            printf("In handler 1\n");
            break;
          // ...
          case 2:
            /* handler 2 */
            printf("In handler 2\n");
            break;
        }
    }
}
