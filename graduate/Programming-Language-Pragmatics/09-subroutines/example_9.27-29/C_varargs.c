/* Example 9.25 */

#include <stdio.h>
#include <stdarg.h>     /* macros and type definitions */

void print2(char *format, ...)
{
    va_list args;
    va_start(args, format);

    while (*format) {
        switch (*format++) {
            case 'd' : {
                int ip = va_arg(args, int);
                printf("%d\n", ip);
                break;
            }
            case 'c' : {
                int cp = va_arg(args, int);
                    /* chars are promoted to ints by va functions */
                printf("%c\n", cp);
                break;
            }
            case 'f' : {
                double dp = va_arg(args, double);
                printf("%f\n", dp);
                break;
            }
        }
    }
    va_end(args);
}

int main() {
    print2("dfc", 10, 123.456, 'x');
}
