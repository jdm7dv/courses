/* Example 6.77 */

#include <stdio.h>
#include <string.h>

char *line;

char *read_line(FILE *stream) {
    static char buf[100];
    fgets(buf, 100, stream);
    if (feof(stream)) buf[0] = 0;
    return buf;
}

int all_blanks(char *line) {
    while (*line) {
        if (*line != ' ' && *line != '\n') return 0;
        ++line;
    }
    return 1;
}

void consume_line(char *line) {
    printf("%lu chars\n", strlen(line));
}

int main() {
    for (;;) {
        line = read_line(stdin);
        if (all_blanks(line)) break;
        consume_line(line);
    }
}
