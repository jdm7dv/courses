/* Examples 6.36 and 6.37 */

#include <stdlib.h>
#include <stdio.h>

typedef struct list_node {
    int key;
    struct list_node *next;
} list_node;

int main() {

    int val;
    list_node *my_list = (list_node *) malloc(sizeof(list_node));
    list_node *p;

    my_list->key = 1;
    my_list->next = (list_node *) malloc(sizeof(list_node));
    my_list->next->key = 2;
    my_list->next->next = 0;

    p = my_list;
    val = 3;
    while (p && p->key != val) 
        p = p->next;                        /* no problem */

    printf("%p\n", p);

    const int MAX = 10;
    int A[MAX];                             /* indices from 0 to 9 */
    int foo = 3;
    int i = 7;
    A[i] = 10;

    if (i >= 0 && i < MAX && A[i] > foo) {
        printf("ok\n");
    }

    double n = 1.0;
    double d = 0.0;
    double threshold = 1.0;
    if (d == 0 || n/d < threshold) {
        printf("also ok\n");
    }

    p = my_list;
    while ((p != 0) & (p->key != val))      /* note use of bitwise & */
        p = p->next;                        /* crashes if run */

    printf("%p\n", p);
}
