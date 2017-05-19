// Example 9.19
// Compile with g++ --std=c++11 rvalues.cc obj.cc

#include <iostream>
using std::cout;
using std::hex;

#include "obj.h"

bool test() { return true; }

obj bar(obj other) {
    cout << "inside bar\n";
    return other;
}

int main() {
    cout << "\nA: ";
    obj o1;                     // calls zero-arg constructor

    cout << "\nB: ";
    obj o2 = o1;                // calls const ref copy constructor

    cout << "\nC: ";
    obj o3 = foo("hi mom");
        // Most compilers won't actually use the rvalue constructor for
        // this example, despite what the book suggests.  A smart compiler
        // will optimize instead, and arrange for foo to construct
        // directly into o3 (using the char* constructor), leveraging
        // the fact that the caller has passed o3's address as a hidden
        // parameter.  This optimization is allowed but not required by
        // the language standard.

    cout << "\nD: ";
    obj o4 = bar(foo("take that!"));
        // In this messier example, the compiler probably can't optimize
        // away the temporary.  It passes, as the hidden parameter to
        // foo, the address of the temporary that it plans subsequently
        // to pass as argument to bar.  Foo constructs that temporary in
        // place using the char* constructor.  Bar, for its part, knows
        // that 'other' is about to go out of scope, so it uses the
        // rvalue ref constructor to build o4 in place, after which it
        // calls the destructor on 'other'.  Note that because the
        // compiler arranged for the argument to bar to be constructed
        // in place, and because it knows that bar will destruct its
        // (by-value) argument, code here in main doesn't have to
        // destruct it.

    cout << "\nE: ";
    o1 = foo("hi mom");
        // Because the '=' sign here is assignment rather than initialization,
        // the compiler has to pass the address of a temporary to foo.
        // As above, foo constructs that temporary in place using the char*
        // constructor.  Back here in the caller, we use the rvalue
        // assignment operator to move the result into o1, and then call
        // the destructor on the temporary.

    cout << "\nF: ";
    obj o5 = std::move(o4);     // calls rvalue ref copy constructor

    cout << "\nNB: &o1 = " << &o1 << "; &o2 = " << &o2 << ";";
    cout << "\n    &o3 = " << &o3 << "; &o4 = " << &o4 << ";";
    cout << "\n    &o5 = " << &o3 << "\n";

    cout << "\ncleanup:\n";
    // Destructors for all five objects called at end of scope.
    // Note that o4, which we std::move-d into o5, no longer has a payload.
}
