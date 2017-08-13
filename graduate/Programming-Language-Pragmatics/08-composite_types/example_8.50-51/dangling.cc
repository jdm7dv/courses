/* Examples 8.50 and 8.51 */

#include <iostream>
using std::cout;

int i = 3;
int *p = &i;
int *q;

void foo() { int n = 5;  p = &n; }
void bar() { int n = 7; }

int main() {
    cout << *p << "\n";     // prints 3
    foo();
    bar();                  // may overwrite space where p points
    cout << *p << "\n";     // undefined behavior: n is no longer live

    int *p = new int;
    *p = 3;
    cout << *p << "\n";     // prints 3
    delete p;
    int *q = new int;
    *q = 5;                 // may overwrite space where p points
    cout << *p << "\n";     // undefined behavior: *p has been reclaimed
}
