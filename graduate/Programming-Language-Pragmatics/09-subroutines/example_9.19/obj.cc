// Example 9.19

#include "obj.h"

#include <iostream>
using std::cout;
using std::hex;

obj::obj() : payload(new char[1]) {
    cout << "zero-arg constructor" << "\n";
    payload[0] = '\0';
}

obj::obj(const char* p) : payload(new char[strlen(p)+1]) {
    cout << "char* constructor " << hex << this << "\n";
    strcpy(payload, p);
}

obj::obj(const obj& other) : payload(new char[strlen(other.payload)+1]) {
    cout << "const ref copy constructor " << hex
         << this << "(" << &other << ")" << "\n";
    strcpy(payload, other.payload);
}

obj::obj(obj&& other) {
    cout << "rvalue ref copy constructor " << hex
         << this << "(" << &other << ")" << "\n";
    payload = other.payload;
    other.payload = nullptr;
}

obj::~obj() {
    cout << "obj destructor " << hex << this << "; ";
    if (payload) {
        cout << "deleting payload " << hex
            << static_cast<void*>(payload) << "\n";
        delete payload;
    } else {
        cout << "no payload to delete" << "\n";
    }
}

obj& obj::operator=(const obj& other) {
    cout << "const ref assignment operator " << hex
         << this << " = " << &other << "\n";
    delete payload;
    payload = strdup(other.payload);
    return *this;
}

obj& obj::operator=(obj&& other) {
    cout << "rvalue ref assignment operator " << hex
         << this << " = " << &other << "\n";
    delete payload;
    payload = other.payload;
    other.payload = nullptr;
    return *this;
}

obj foo(const char* p) {
    cout << "inside foo\n";
    return obj(p);
}
