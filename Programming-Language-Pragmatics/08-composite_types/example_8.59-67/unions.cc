// Example 8.61

#include <iostream>
using std::cout;

void foo() {
    union {
        int a;
        int b;
    };
    b = 0;
    a = 3;
    cout << b << "\n";
}

int main() {
    foo();
}
