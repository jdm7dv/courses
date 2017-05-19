// Examples 9.35, 9.36, 9.37, 9.39, and 9.40

#include <iostream>
#include <string>
#include <exception>
using std::cout;
using std::string;
using std::exception;

class my_error {
public:
    my_error(string s) : explanation(s) {}
    string explanation;
};

class some_other_error {};

bool something_unexpected = true;

void foo() {
    // ...
    if (something_unexpected)
        throw my_error("oops!");
    // ...
}

typedef string item;

class duplicate_in_set {
public:
    item dup;       // element that was inserted twice
    duplicate_in_set(item d) : dup(d) { }
};

// NB: exception objects are not required to be derived from class
// 'exception,' but it is customary to make them so.

class io_error : public exception {
public:
    string description;
    io_error(string s) throw() : description(s) { }
    virtual ~io_error() throw() { }
    // NB: the 'throw()' clauses are required here to avoid warnings
    // about lack of conformity with the 'exception' base class.
};
class end_of_file : public io_error {
public:
    end_of_file() : io_error("end of file") { }
};

void do_io(int e) {
    switch(e) {
        case 1 :
            throw end_of_file();
            break;
        case 2 :
            throw io_error("no response from server");
            break;
        case 3 :
            throw exception();
            break;
    }
}

int main() {
    try {
        // ...
        if (something_unexpected)
            throw my_error("oops!");
        // ...
        cout << "everything's ok\n";
        // ...
    } catch (my_error e) {
        cout << e.explanation << "\n";
    }

    try {
        // ...
        try {
            // ...
            if (something_unexpected)
                throw my_error("oops!");
            // ...
            cout << "everything's ok\n";
            // ...
        } catch (some_other_error e1) {
            cout << "not this one" << "\n";
        }
        // ...
    } catch (my_error e) {
        cout << e.explanation << "\n";
    }

    try {
        // ...
        foo();
        // ...
        cout << "everything's ok\n";
        // ...
    } catch (my_error e) {
        cout << e.explanation << "\n";
    }

    try {
        // ...
        string d = "string that was inserted twice";
        if (something_unexpected)
            throw duplicate_in_set(d);
        // ...
        cout << "everything's ok\n";
        // ...
    } catch (duplicate_in_set e) {
        cout << "found duplicate: " << e.dup << "\n";
    }

    for (int i = 1; i <= 3; i++) {
        try {                   // try to read from file
            // potentially complicated sequence of operations
            // involving many calls to stream I/O routines
            do_io(i);
            cout << "everything's ok\n";
        } catch(end_of_file e1) {
            cout << "caught end_of_file\n";
        } catch(io_error e2) {
            // handler for any io_error other than end_of_file
            cout << "caught io_error: " << e2.description << "\n";
        } catch(...) {
            // handler for any exception not previously named
            // (in this case, the triple-dot ellipsis is a valid C++ token;
            // it does not indicate missing code)
            cout << "caught something else\n";
        }
    }
}
