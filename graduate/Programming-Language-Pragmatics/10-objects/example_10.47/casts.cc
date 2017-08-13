// Example 10.47

#include <iostream>
using std::cout;
using std::endl;

class foo {
public:
    int foo_val;
    virtual void fn() { }
};
class bar : public foo {
public:
    int bar_val;
};

int main() {
    bar b;
    b.bar_val = 123;
    foo *q = &b;
    bar *s;
    bar *t;

    // int n = q->bar_val;                  // error
    s = dynamic_cast<bar*>(q);              // ok
    t = (bar*) q;                           // dangerous

    cout << s->bar_val << " " << t->bar_val << endl;
}
