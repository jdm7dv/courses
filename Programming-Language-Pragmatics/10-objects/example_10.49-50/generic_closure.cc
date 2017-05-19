// Examples 10.49 and 10.50 (including Figure 10.5)

#include <iostream>
using std::cout;
#include <functional>

template<typename T>
class un_op {
public:
    virtual T operator()(T i) const = 0;
};

class plus_x : public un_op<int> {
    const int x;
public:
    plus_x(int n) : x(n) { }
    virtual int operator()(int i) const { return i + x; }
};

class printer : public un_op<int> {
public:
    virtual int operator()(int i) const { printf(" %d", i); return i; }
};

void foo(un_op<int>& f) {
    cout << f(3) << "\n";
}

void apply_to_A(const un_op<int>& f, int A[], int A_size) {
    int i;
    for (i = 0; i < A_size; i++) A[i] = f(A[i]);
}

typedef int sim_time;
sim_time now() {return 3;}

void schedule_at(std::function<void()> f, const sim_time t) {
    (void) f; (void) t;             // suppress "unused parameter" warnings
    // ...
}

void bar(const int a, const double b, const char c) {
    (void) a; (void) b; (void) c;   // suppress "unused parameter" warnings
    // ...
}

int main() {
    un_op<int>& f = *new plus_x(2);
    cout << f(3) << "\n";

    plus_x g(2);
    foo(g);

    un_op<int>& h = g;
    cout << h(3) << "\n";

    int A[10];
    printer p;
    for (int i = 0; i < 10; i++) { A[i] = i; }
    apply_to_A(p, A, 10);
    printf("\n");
    apply_to_A(plus_x(2), A, 10);
    apply_to_A(p, A, 10);
    printf("\n");

    sim_time delay = 10;
    
    std::function<void()> cf = std::bind(bar, 3, 3.14, 'x');
    schedule_at(cf, now() + delay);
        // at some point in the future, the discrete event system
        // will call cf.operator()(), which will cause a call to
        // bar(3, 3.14, 'x')
}
