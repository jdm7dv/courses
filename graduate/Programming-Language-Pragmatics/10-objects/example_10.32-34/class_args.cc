// Examples 10.32, 10.33, and 10.34

#include <iostream>
using std::cout;

class list_node {
    list_node* prev;
    list_node* next;
    list_node* head_node;
public:
    int val;
    list_node(int v) : prev(this), next(this), head_node(this), val(v) {
        // empty body -- nothing else to do
    }
    list_node() : list_node(0) { }      // forward to (int) constructor
    list_node* predecessor();
    list_node* successor();
    int singleton();
    void insert_before(list_node* new_node);
    void remove();
    ~list_node();
};

class bar {
    int c;
public:
    bar(int c0) : c(c0) {
        cout << "call to bar(int)\n";
    }
};

class mem1_t {
    int a;
    double x;
public:
    mem1_t() {
        a = 0;  x = 0.0;
        cout << "call to mem1_t()\n";
    }
    mem1_t(int a0, double x0) : a(a0), x(x0) {
        cout << "call to mem1_t(int, double)\n";
    }
    mem1_t& operator=(mem1_t o) {
        a = o.a;  x = o.x;
        cout << "call to mem1_t::operator=(mem1_t)\n";
        return *this;
    }
};

class mem2_t {
    int b;
    double y;
public:
    mem2_t() {
        b = 0;  y = 0.0;
        cout << "call to mem2_t()\n";
    }
    mem2_t(int b0, double y0) : b(b0), y(y0) {
        cout << "call to mem2_t(int, double)\n";
    }
    mem2_t& operator=(mem2_t o) {
        b = o.b;  y = o.y;
        cout << "call to mem2_t::operator=(mem2_t)\n";
        return *this;
    }
};

class foo : bar {
    mem1_t member1;
    mem2_t member2;
    // Note differing order of argument types in following two
    // constructors.  Resulting overloading allows us to test both.
public:
    foo(int a0, int b0, double x0, double y0, int c0) : bar(c0) {
        member1 = mem1_t(a0, x0);
        member2 = mem2_t(b0, y0);
        cout << "call to foo(int, int, double, double, int)\n";
    }
    foo(double x0, double y0, int a0, int b0, int c0) : bar(c0),
        member1(a0, x0), member2(b0, y0) {
        cout << "call to foo(double, double, int, int, int)\n";
    }
};

int main() {
    foo f1(3, 4, 5.0, 6.0, 7);
    cout << "\n";
    foo f2(5.0, 6.0, 3, 4, 7);
}
