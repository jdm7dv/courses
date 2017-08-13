/* Examples 8.6, 8.8, and 8.9 */

#include <stdio.h>

typedef struct element {
    char name[2];
    int atomic_number;
    double atomic_weight;
    _Bool metallic;
} element;

typedef struct __attribute__ ((__packed__)) element2 {
    char name[2];
    int atomic_number;
    double atomic_weight;
    _Bool metallic;
} element2;

struct T {
    int j;
    int k;
};
struct S {
    int i;
    struct T n;
};

int main() {
    struct S s1;
    struct S s2;
    s1.n.j = 0;
    s2 = s1;
    s2.n.j = 7;

    printf("%d\n", s1.n.j);     /* prints 0 */

    printf("%lu, %lu\n", sizeof(element), sizeof(element2));
                         /* 20 */         /* 15 */
             /* (when compiled with -m32 for 32-bit code) */

    element copper;
    element my_element;

    my_element = copper;        /* ok */
    /* my_element == copper        static error */
}
