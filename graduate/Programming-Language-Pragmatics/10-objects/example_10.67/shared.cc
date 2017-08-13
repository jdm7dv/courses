// Example 10.67

#include <iostream>
using std::cout;

class A {
public:
    virtual void f() { cout << "A's f\n"; }
    virtual void g() { cout << "A's g\n"; }
    virtual void h() { cout << "A's h\n"; }
};
      
class B : public virtual A {
public:
    virtual void f() { cout << "B's f\n"; }
    virtual void g() { cout << "B's g\n"; }
        // overridden only by B
};

class C : public virtual A {
public:
    virtual void f() { cout << "C's f\n"; }
        // overridden by both B and C
};

class D : public B, public C {
public:
    virtual void f() { cout << "D's f\n"; }
        // without this declaration, D's definition is invalid,
        // because there is no unique final f()
    void h() {
        f();                // D's f
        B::f();             // B's f
        g();                // B's g (not A's)
    }
};

int main() {
    D d;
    d.h();
}
