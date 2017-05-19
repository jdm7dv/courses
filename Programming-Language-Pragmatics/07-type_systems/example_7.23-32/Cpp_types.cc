// Example 7.29

#include <iostream>
using std::cout;
using std::hex;  using std::dec;        // IO manipulators

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
    double d = 3.14159;
    int n = static_cast<int>(d);
    cout << n << "\n";

    double* p = &d;
    long m = reinterpret_cast<long>(p);
    cout << "0x" << hex << n << dec << "\n";

    bar b;
    b.bar_val = 123;
    foo *fp = &b;
    // n = fp->bar_val;                     // error
    n = dynamic_cast<bar*>(fp)->bar_val;
    cout << n << "\n";
}
