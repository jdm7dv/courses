// Example 10.62

#include <iostream>
using std::cout;

class person {
public:
    virtual void print_stats() {
        cout << "call to person::print_stats()\n";
    }
};

class system_user {
public:
    virtual void print_stats() {
        cout << "call to system_user::print_stats()\n";
    }
};

class person_interface : public person {
public:
    virtual void print_person_stats() = 0;
    void print_stats() { print_person_stats(); }
        // overrides person::print_stats
};

class system_user_interface : public system_user {
public:
    virtual void print_user_stats() = 0;
    void print_stats() { print_user_stats(); }
        // overrides system_user::print_stats
};

class student : public person_interface, public system_user_interface {
public:
    void print_person_stats() {
        cout << "call to student::print_person_stats()\n";
    }
    void print_user_stats() {
        cout << "call to student::print_user_stats()\n";
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

    s.print_stats();            // student::print_stats()
                                // person::print_stats()
                                // system_user::print_stats()

    cout << "\n";
    s.print_person_stats();     // student::print_person_stats()

    cout << "\n";
    s.print_user_stats();       // student::print_user_stats()

    cout << "\n";
    x->print_stats();           // student::print_stats()
                                // person::print_stats()
                                // system_user::print_stats()

    cout << "\n";
    y->print_stats();           // student::print_stats()
                                // person::print_stats()
                                // system_user::print_stats()
}
