/* Example 6.76 */

#include <stdio.h>

char *line;

char *read_line(FILE *stream) {
    static char buf[100];
    fgets(buf, 100, stream);
    return buf;
}

int main() {
    do {
        line = read_line(stdin);
    } while (line[0] != '$');
}
