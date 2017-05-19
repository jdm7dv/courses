// Examples 7.56 and 7.57

#include <iostream>
using std::cout;
#include "arbiter.h"

int main() {
    arbiter<string, case_sensitive> cs_names;
    cs_names.consider(new string("Apple"));
    cs_names.consider(new string("aardvark"));
    cout << *cs_names.best() << "\n";

    arbiter<string, case_insensitive> ci_names;
    ci_names.consider(new string("Apple"));
    ci_names.consider(new string("aardvark"));
    cout << *ci_names.best() << "\n";
}
