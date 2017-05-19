// Examples 9.15, 9.16, 9.17, and 9.18

#include <iostream>
using std::cout;

void swap(int &a, int &b) { int t = a; a = b; b = t; }

struct element {
    const char *name;
    int atomic_number;
    double atomic_weight;
    bool metallic;
};
struct mineral {
    struct {
        element elements[10];
    } chemical_composition;
};

int main() {
    int i;
    int &j = i;

    i = 2;
    j = 3;
    cout << i;          // prints 3

    cout << "\n";

    int a = 1, b = 2, c = 3;
    cout << a << b << c;
    cout << "\n";
    ((cout.operator<<(a)).operator<<(b)).operator<<(c);
    cout << "\n";

    mineral ruby;
    {
        element* e = &ruby.chemical_composition.elements[1];
        e->name = "Al";
        e->atomic_number = 13;
        e->atomic_weight = 26.98154;
        e->metallic = true;
    }
    {
        auto& e = ruby.chemical_composition.elements[1];
        e.name = "Al";
        e.atomic_number = 13;
        e.atomic_weight = 26.98154;
        e.metallic = true;
    }
}
