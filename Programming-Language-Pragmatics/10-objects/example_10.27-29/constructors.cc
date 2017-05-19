// Example 10.27, 10.28, 10.29

#include <iostream>
#include <string>
using std::cout;
using std::string;

class foo {
public:
    int val;

    void set(int v) { val = v; }
    int get() { return val; }

    foo() {
        cout << "\tfoo default constructor : " << this << "\n";
    }
    foo(int v) : val(v) {
        cout << "\tfoo int constructor : " << this << "\n";
    }
    foo(const foo& other) : val(other.val) {
        cout << "\tfoo copy constructor : " << this << "(" << &other << ")\n";
    }
    foo(foo&& other) : val(std::move(other.val)) {
        cout << "\tfoo move constructor : " << this << "(" << &other << ")\n";
    }
    foo(int v, char) : val(v) {     // 2nd parameter ignored
        cout << "\tfoo int, char constructor : " << this << "\n";
    }
    ~foo() {
        cout << "\tfoo destructor : " << this << "\n";
    }
    foo& operator=(const foo& other) {
        cout << "\tfoo copy assignment : " << this << "(" << &other << ")\n";
        val = other.val;
        return *this;
    }
    foo operator+(const foo& other) {
        cout << "\tfoo operator+ :" << this << "(" << &other << ")\n";
        // foo t(val + other.val);
        foo t(*this);
        t.val += other.val;
        return t;
    }
    foo& operator+=(const foo& other) {
        cout << "\tfoo operator+= :" << this << "(" << &other << ")\n";
        val += other.val;
        return *this;
    }
};

foo g;      // global; default constructor called at program start-up

class my_string : public string {
public:
    my_string(const char* s) : string(s) {
        cout << "\tstring constructor\n";
    }
    ~my_string() {
        cout << "\tstring destructor\n";
    }
};

my_string operator+(const my_string& l, const my_string& r) {
    return my_string(operator+((const string&)l, (const string&)r).c_str());
}

int main() {
    cout << "foo a:\n";
    foo a;              // foo::foo()

    cout << "foo b(10, 'x'):\n";
    foo b(10, 'x');     // foo::foo(int, char)
    cout << "foo c{10, 'x'}:\n";
    foo c{10, 'x'};     // alternative syntax

    cout << "foo d(a):\n";
    foo d(a);           // foo::foo(foo&)
    cout << "foo e{a}:\n";
    foo e{a};           // alternative syntax

    cout << "foo f = a:\n";
    foo f = a;          // also foo::foo(foo&)

    cout << "foo g; g = a:\n";
    foo g;
    g = a;              // foo::operator=(foo&)

    cout << "string length\n";
    cout << string("hi, mom").length() << "\n";     // 7

    cout << "concatenated string length\n";
    my_string s("first");               // calls constructor
    my_string t("second");              // calls constructor
    cout << (s + t).length() << "\n";   // calls constructor for temporary
                                        // and then destructs it

    cout << "end of body\n";
    // destructors called here
}
