/* Exercise 9.23 (Figure 9.6) */

/* NB: Depending on your compiler and system, you may need to type ^Z
   many times before you see erratic behavior. */

#include <signal.h>
#include <stdio.h>
#include <string.h>

char* days[7] = {"Sunday", "Monday", "Tuesday",
                "Wednesday", "Thursday", "Friday", "Saturday"};
char today[10];

void handler(int n) {
    printf(" %s\n", today);
}

int main() {
    signal(SIGTSTP, handler);
    for(int n = 0; ; n++) {
        strcpy(today, days[n%7]);
    }
}
