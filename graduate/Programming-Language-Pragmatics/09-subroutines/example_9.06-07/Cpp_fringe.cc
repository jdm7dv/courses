// Example 9.7

#include <iostream>
using std::cout;
#include <string>
using std::string;

struct bin_tree {
    string val;
    bin_tree *left;
    bin_tree *right;
};

string fringe(bin_tree *t) {
    // assume both children are nil or neither is
    if (t->left == 0) return t->val;
    return fringe(t->left) + fringe(t->right);
}

int main() {
    bin_tree A, B, C, D, E;
    A.val = "(root) ";
    B.val = "(L child) ";
    C.val = "(R child) ";
    D.val = "(L grandchild) ";
    E.val = "(R grandchild) ";
    A.left = &B;
    A.right = &C;
    B.left = &D;
    B.right = &E;
    D.left = D.right = E.left = E.right = C.left = C.right = 0;
    cout << fringe(&A) << "\n";
}
