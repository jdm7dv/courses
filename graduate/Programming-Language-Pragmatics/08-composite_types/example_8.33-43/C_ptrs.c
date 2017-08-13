/* Examples 8.36 and 8.37 */

#include <stdio.h>
#include <stdlib.h>

typedef struct chr_tree {
    struct chr_tree *left, *right;
    char val;
} chr_tree;

chr_tree *t, *l, *r;

int main() {
    l = malloc(sizeof(chr_tree));
    l->val = 'Z';
    (*l).val = 'Z';             /* alternative syntax */
    l->left = l->right = 0;
    r = malloc(sizeof(chr_tree));
    r->val = 'W';
    r->left = r->right = 0;
    t = malloc(sizeof(chr_tree));
    t->val = 'Y';
    t->left = l;
    r->right = r;
    r = t;
    l = malloc(sizeof(chr_tree));
    l->val = 'X';
    l->left = l->right = 0;
    t = malloc(sizeof(chr_tree));
    t->val = 'R';
    t->left = l;
    t->right = r;
    
    printf("%c\n", t->right->left->val);    /* Z */
}
