// Examples 7.56 and 7.57

#include "arbiter.h"

template<typename T, typename C>
arbiter<T,C>::arbiter() { best_so_far = nullptr; }

template<typename T, typename C>
void arbiter<T,C>::consider(T* t) {
    if (!best_so_far || comp(*t, *best_so_far)) best_so_far = t;
}

template<typename T, typename C>
T* arbiter<T,C>::best() { return best_so_far; }

template class arbiter<string, case_sensitive>;    // force instantiation
template class arbiter<string, case_insensitive>;
