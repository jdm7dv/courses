// Examples C-3.50 and C-3.51
// Because it actually creates foo_type_1 objects, this version
// of main needs a type definition.

#include "foo.h"

namespace foo {
    class foo_type_1 {      // same as in foo.cc
        public:             // note that this equivalence is NOT enforced
        int a, b;
    };
}

void bar1() {
    foo::foo_type_1 my_first_obj;
    foo::foo_func_2(my_first_obj, 2, 3);
    foo::foo_func_3(&my_first_obj);
}

void bar2() {
    using foo::foo_type_1;
    using foo::foo_func_2;
    using foo::foo_func_3;
    foo_type_1 my_first_obj;
    foo_func_2(my_first_obj, 4, 5);
    foo_func_3(&my_first_obj);
}

void bar3() {
    using namespace foo;
    foo_type_1 my_first_obj;
    foo_func_2(my_first_obj, 6, 7);
    foo_func_3(&my_first_obj);
}

int main() {
    bar1();
    bar2();
    bar3();
}
