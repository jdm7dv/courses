// Examples 10.37, 10.38, 10.40, and 10.43

#include <iostream>
using std::cout;

class person {
public:
    void print_mailing_label() {
        cout << "call to person::print_mailing_label()\n";
    }
    virtual void vprint_mailing_label() {
        cout << "call to person::vprint_mailing_label()\n";
    }
    virtual void aprint_mailing_label() = 0;        // abstract
};

class student : public person {
public:
    void print_mailing_label() {
        cout << "call to student::print_mailing_label()\n";
    }
    virtual void vprint_mailing_label() {
        cout << "call to student::vprint_mailing_label()\n";
    }
    virtual void aprint_mailing_label() {};
        // program won't compile without a definition
};

class professor : public person {
public:
    void print_mailing_label() {
        cout << "call to professor::print_mailing_label()\n";
    }
    virtual void vprint_mailing_label() {
        cout << "call to professor::vprint_mailing_label()\n";
    }
    virtual void aprint_mailing_label() {};
        // program won't compile without a definition
};

int main() {
    student s;
    professor p;

    person *x = &s;
    person *y = &p;

    s.print_mailing_label();    // student::print_mailing_label(s)
    s.vprint_mailing_label();   // student::vprint_mailing_label(s)
    p.print_mailing_label();    // professor::print_mailing_label(p)
    p.vprint_mailing_label();   // professor::vprint_mailing_label(p)

    cout << "\n";

    x->print_mailing_label();    // person::print_mailing_label(x)
    x->vprint_mailing_label();   // student::vprint_mailing_label(x)
    y->print_mailing_label();    // person::print_mailing_label(y)
    y->vprint_mailing_label();   // professor::vprint_mailing_label(y)
}
