/* Examples 8.1, 8.2, and 8.3 */

typedef struct element {
    char name[2];
    int atomic_number;
    double atomic_weight;
    _Bool metallic;
} element;

typedef struct ore {
    char name[30];
    struct {
        char name[2];
        int atomic_number;
        double atomic_weight;
        _Bool metallic;
    } element_yielded;
} ore;

typedef struct ore2 {
    char name[30];
    struct element element_yielded;
} ore2;

int main() {
    element copper;
    static const double AN = 6.022e23;     /* Avogadro's number */

    element my_element;
    double atoms, mass;
    ore malachite1;
    ore2 malachite2;

    copper.name[0] = 'C';  copper.name[1] = 'u';
    atoms = mass / copper.atomic_weight * AN;
    my_element = copper;

    malachite1.element_yielded.metallic = 1;
    malachite2.element_yielded = copper;
        // no analogous assignment for malachite1
}
