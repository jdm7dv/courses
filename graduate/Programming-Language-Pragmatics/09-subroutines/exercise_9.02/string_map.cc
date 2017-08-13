// Exercise 9.2

#include <iostream>
using std::cout;
#include <string>
using std::string;

class string_map {
    string cached_key;
    string cached_val;
    const string complex_lookup(const string key) {
        return key;
    }
public:
    const string operator[](const string key) {
        if (key == cached_key) return cached_val + "_cached";
        string rtn_val = complex_lookup(key);
        cached_key = key;
        cached_val = rtn_val;
        return rtn_val;
    }
};

int main() {
    string_map M;
    string abc = M["abc"];
    cout << M["abc"] << "\n";
    cout << M["bcd"] << "\n";
    cout << M["bcd"] << "\n";
}
