// Examples 3.14 - 3.16 (Figures 3.6 - 3.8)
// Simple pseudo random number generator, to illustrate modules.
// Uses linear congruential method -- not very good!

#include <time.h>
#include <iostream>
using std::cout;

namespace rand_mod {
    unsigned int seed = time(0);    // initialize from current time of day
    const unsigned int a = 48271;
    const unsigned int m = 0x7fffffff;

    void set_seed(unsigned int s) {
        seed = s;
    }
    unsigned int rand_int() {
        return seed = (a * seed) % m;
    }
}

namespace rand_mgr {
    const unsigned int a = 48271;
    const unsigned int m = 0x7fffffff;

    typedef struct {
        unsigned int seed;
    } generator;

    generator* create() {
        generator* g = new generator;
        g->seed = time(0);
        return g;
    }
    void set_seed(generator* g, unsigned int s) {
        g->seed = s;
    }
    unsigned int rand_int(generator* g) {
        return g->seed = (a * g->seed) % m;
    }
}

class rand_gen {
    unsigned int seed = time(0);
    const unsigned int a = 48271;
    const unsigned int m = 0x7fffffff;

public:
    void set_seed(unsigned int s) {
        seed = s;
    }

    unsigned int rand_int() {
        return seed = (a * seed) % m;
    }
};

int main() {
    {
        using rand_mod::rand_int;
        int r = rand_int();
        cout << r << "\n";
    }
    {
        using namespace rand_mod;
        set_seed(12345);
        // NB: The following call is the only one in this file that will
        // produce a different result.  All the others use the same
        // initial seed.
        int r = rand_int();
        cout << r << "\n";
    }
    {
        using rand_mgr::generator;
        generator *g1 = rand_mgr::create();
        generator *g2 = rand_mgr::create();
    
        using rand_mgr::rand_int;
        int r1 = rand_int(g1);
        int r2 = rand_int(g2);
        cout << r1 << " " << r2 << "\n";
    }
    rand_gen *g = new rand_gen();
    int r = g->rand_int();
    cout << r << "\n";
}
