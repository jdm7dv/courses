/* Example 1.20 */

#include <stdio.h>

int getint() {
    int i;
    scanf("%d", &i);
    return i;
}

void putint(int i) {
    printf("%d\n", i);
}

int main() { 
    int i = getint(), j = getint(); 
    while (i != j) { 
        if (i > j) i = i - j; 
        else j = j - i; 
    } 
    putint(i); 
} 
