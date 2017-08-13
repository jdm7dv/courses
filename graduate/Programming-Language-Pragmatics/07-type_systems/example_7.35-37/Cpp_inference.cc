// Examples 7.36 and 7.37

#include<list>
#include<algorithm>
#include<typeinfo>
#include<iostream>
using std::list;
using std::sort;
using std::cout;

template<typename A, typename B>
void print_sum(A a, B b) {
    cout << typeid(a + b).name() << " " << a + b << "\n";
}

int main() {
    auto reduce = [](list<int> L, int f(int, int), int s) {
            // the initial value of s should be the identity element for f
            for (auto e : L) {
                s = f(e, s);
            }
            return s;
        };
    list<int> nums;
    for (int i = 1; i <= 10; i++) {
        nums.push_back(i);
    }

    int sum = reduce(nums, [](int a, int b) {return a+b;}, 0);
    int product = reduce(nums, [](int a, int b) {return a*b;}, 1);

    cout << sum << " " << product << "\n";

    double x = 4.3;
    int n = x;          // truncates
    print_sum(x, x);    // real-number output ('d')
    print_sum(n, n);    // integer output ('i')
    print_sum(x, n);    // real-number output ('d')
}
