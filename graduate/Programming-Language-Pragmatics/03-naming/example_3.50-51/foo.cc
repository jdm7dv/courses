// Examples C-3.50 and C-3.51

#include <iostream>
using std::cout;

#include "foo.h"

class foo::foo_type_1 {         // full definition, outside namespace
    public:
    int a, b;
};

namespace foo {                 // definitions inside namespace

    foo_type_1 *foo_func_1(int a, int b) {
        foo_type_1 *x = new foo_type_1;
        x->a = a;
        x->b = b;
        return x;
    }

    void foo_func_3(foo_type_1 *x) {
        cout << x->a << " " << x->b << "\n";
    }
}

void foo::foo_func_2(foo::foo_type_1 &x, int a, int b) {
    x.a = a;
    x.b = b;
}
