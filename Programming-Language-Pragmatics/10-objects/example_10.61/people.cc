// Example 10.61

#include <iostream>
using std::cout;

class person {
public:
    void print_mailing_label() {
        cout << "call to person::print_mailing_label()\n";
    }
    void print_stats() {
        cout << "call to person::print_stats()\n";
    }
};

class system_user {
public:
    void print_stats() {
        cout << "call to system_user::print_stats()\n";
    }
};

class student : public person, public system_user {
public:
    void print_mailing_label() {
        cout << "call to student::print_mailing_label()\n";
    }
    void print_stats() {
        cout << "call to student::print_stats()\n";
        person::print_stats();
        system_user::print_stats();
    }
};

int main() {
    student s;

    person *x = &s;
    system_user *y = &s;

    s.print_mailing_label();    // student::print_mailing_label(s)
    cout << "\n";
    s.print_stats();            // student::print_stats(s)
                                // person::print_stats(s)
                                // system_user::print_stats(s)
    cout << "\n";
    x->print_mailing_label();   // person::print_mailing_label(s)
    cout << "\n";
    x->print_stats();           // person::print_stats(s)
    cout << "\n";
    y->print_stats();           // student::print_stats(s)
}
