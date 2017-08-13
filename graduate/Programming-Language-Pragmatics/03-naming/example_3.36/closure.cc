// Example 3.36

#include <iostream>
using std::cout;

class int_func {
public:
    virtual int operator()(int i) = 0;
};
class plus_x : public int_func {
    const int x;
public:
    plus_x(int n) : x(n) { }
    virtual int operator()(int i) { return i + x; }
};

int main() {
    plus_x f(2);
    cout << f(3) << "\n";           // prints 5
}
