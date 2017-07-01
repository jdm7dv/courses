// Examples C-3.50 and C-3.51
// Note that this file neither needs nor sees the definition of
// foo_type_1.

#include "foo.h"

void bar1() {
    foo::foo_type_1 *f = foo::foo_func_1(2, 3);
    foo::foo_func_3(f);
}

void bar2() {
    using foo::foo_type_1;
    using foo::foo_func_1;
    using foo::foo_func_3;
    foo_type_1 *f = foo_func_1(4, 5);
    foo_func_3(f);
}

void bar3() {
    using namespace foo;
    foo_type_1 *f = foo_func_1(6, 7);
    foo_func_3(f);
}

int main() {
    bar1();
    bar2();
    bar3();
}
