// Examples 7.56 and 7.57

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
    arbiter();
    void consider(T* t);
    T* best();
};

#include <string>
using std::string;

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

extern template class arbiter<string, case_sensitive>;    // assume instantiation
extern template class arbiter<string, case_insensitive>;
