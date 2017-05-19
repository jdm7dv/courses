// Exercise 7.17

#include <list>
using std::list;

#include <iostream>
using std::cout;

class foo {
    int a;
};

class bar : public foo {
    int b;
};

static void print_all(list<foo*> &L) {
    cout << L.size();     // this is just a placeholder
};

int main() {
    list<foo*> LF;
    list<bar*> LB;

    print_all(LF);        // works fine
    print_all(LB);        // static semantic error
}
