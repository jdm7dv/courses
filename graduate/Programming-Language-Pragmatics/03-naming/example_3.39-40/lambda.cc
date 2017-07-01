// Examples 3.39 and 3.40
// May need to be compiled with --std=c++11

#include <vector>
using std::vector;
#include <iostream>
using std::cout;

int main() {
    vector<int> V = { 10, 20, 30, 40, 50, 60 };
    for_each (V.begin(), V.end(),
        [](int e) { if (e < 50) cout << e << " "; }
    );
    cout << "\n";

    int k = 3;
    [=](int e) { if (e < k) cout << e << " "; } (2);  // prints 2

    auto f = [=](int e){ if (e < k) cout << e << " "; };
    k = 10;
    f(4);  // does not print, even though k has changed.

    [&](int e) { if (e < k) cout << e << " "; } (2);  // prints 2

    auto g = [&](int e) { if (e < k) cout << e << " "; };
    k = 20;
    g(15);  // prints 15

    int j = 3;
    auto h = [j, &k](int e) {
        // capture j's value and a reference to k,
        // so they can be used in here
        if (j < e && e < k) cout << "yes\n";
        else cout << "no\n";
    };
    cout << "\n";
    h(10);  // prints "yes"
    j = 20;
    h(10);  // prints "yes"
    k = 5;
    h(10);  // prints "no"
}
