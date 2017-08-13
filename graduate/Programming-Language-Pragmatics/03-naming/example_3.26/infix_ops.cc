// Example 3.26

#include <iostream>
using std::cout;

class complex {
    double real, imaginary;
public:
    complex(double r, double i) : real(r), imaginary(i) { }
    complex operator+(complex other) {
        return complex(real + other.real, imaginary + other.imaginary);
    }
    void print() {
        cout << "(" << real << ", " << imaginary << ")\n";
    }
};

void print_num(complex c) {
}

int main() {
    complex A(1.0, 2.0);
    complex B(3.0, 4.0);

    complex C = A + B;
    C.print();
}
