// Example 10.66

class A {
    int f1;
};
      
class B : public A {
    int f1;
};

class C : public A {
    int f3;
};

class D : public B, public C {
    int f4;
};

int main() {
    A* a;   B* b;   C* c;   D* d;
    a = d;  // error; ambiguous
    b = d;  // ok
    c = d;  // ok
    a = b;  // ok; a := d's B's A
    a = c;  // ok; a := d's C's A
}
