// Exercise 7.27

#include <list>
using std::list;

#include <iostream>
using std::cout;

template <typename T>
class cloneable_list : public list<T> {
public:
    cloneable_list<T>* clone() {
        auto rtn = new cloneable_list<T>();
        for (auto e : *this) {
            rtn->push_back(e);
        }
        return rtn;
    }
};

int main() {
    cloneable_list<int> L;
    for (int i = 0; i < 10; ++i) {
        L.push_back(i);
    }
    cloneable_list<int>* Lp = L.clone();
    for (auto e : *Lp) {
        cout << e << " ";
    }
    cout << "\n";
}
