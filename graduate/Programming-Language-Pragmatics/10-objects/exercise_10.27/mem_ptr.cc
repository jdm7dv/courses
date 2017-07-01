// Exercise 10.27

#include <iostream>
using std::cout;

class C {
public:
    int a;
    int b;
} c;

int main() {
    int C::*pm = &C::a;

    c.a = 1;
    C* p = &c;
    p->*pm = 3;
    cout << c.a << "\n";
}
