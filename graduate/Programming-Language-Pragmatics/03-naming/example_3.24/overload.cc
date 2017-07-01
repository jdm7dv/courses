// Example 3.24 (Figure 3.12)

#include <iostream>
#include <iomanip>
using std::cout;

struct complex {
    double real, imaginary;
};
enum base {dec, bin, oct, hex};

int i = 127;
complex x = {1.0, 1.0};

static void print_num(int n) {
    cout << n << "\n";
}
static void print_num(int n, base b) {
    switch (b) {
        case dec :
            cout << n << "\n";
            break;
        case hex :
            cout << "0x" << std::hex << n << "\n";
            break;
        case oct :
            cout << "0" << std::oct << n << "\n";
            break;
    }
}
static void print_num(complex c) {
    cout << "(" << c.real << ", " << c.imaginary << ")\n";
}

int main() {
    print_num(i);       // uses the first function above
    print_num(i, hex);  // uses the second function above
    print_num(x);       // uses the third function above
}
