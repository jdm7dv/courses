// Example 7.55

#include <iostream>
using std::cout;
#include <string>
using std::string;

template<typename T>
class chooser {
public:
    virtual bool operator()(const T& a, const T& b) = 0;
};

template<typename T, typename C>
class arbiter {
    T* best_so_far;
    C comp;
public:
    arbiter() { best_so_far = nullptr; }
    void consider(T* t) {
        if (!best_so_far || comp(*t, *best_so_far)) best_so_far = t;
    }
    T* best() {
        return best_so_far;
    }
};

class case_sensitive : chooser<string> {
public:
    bool operator()(const string& a, const string& b) { return a < b; }
};

class case_insensitive : chooser<string> {
public:
    bool operator()(const string& a, const string& b) {
        string::const_iterator ai = a.begin();
        string::const_iterator bi = b.begin();
        while (ai != a.end() && bi != b.end()) {
            if (toupper(*ai) < toupper (*bi)) return 1;
            if (toupper(*bi) < toupper (*ai)) return 0;
            ++ai;  ++bi;
        }
        return bi != b.end();
    }
};

class foo {
public:
    bool operator()(const string& a, const unsigned int b)
        // wrong type for second parameter, from arbiter's point of view
        { return a.length() < b; }
};

int main() {
    arbiter<string, case_sensitive> cs_names;
    cs_names.consider(new string("Apple"));
    cs_names.consider(new string("aardvark"));
    cout << *cs_names.best() << "\n";           // Apple

    arbiter<string, case_insensitive> ci_names;
    ci_names.consider(new string("Apple"));
    ci_names.consider(new string("aardvark"));
    cout << *ci_names.best() << "\n";           // aardvark


/*  Uncomment the lines below to see error message.

    arbiter<string, foo> oops;
    oops.consider(new string("Apple"));      // static error
*/
}
