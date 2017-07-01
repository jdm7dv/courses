/* Examples 8.59, 8.61, and 8.62 */

#include <stdio.h>

typedef struct element {
    char name[2];
    int atomic_number;
    double atomic_weight;
    _Bool metallic;
    _Bool naturally_occurring;
    union {
        struct {
            char *source;
                /* textual description of principal commercial source */
            double prevalence;
                /* fraction, by weight, of Earth's crust */
        } natural_info;
        double lifetime;
            /* half-life in seconds of most stable known isotope */
    } extra_fields;
} element;

typedef struct element2 {
    char name[2];
    int atomic_number;
    double atomic_weight;
    _Bool metallic;
    _Bool naturally_occurring;
    union {
        struct {
            char *source;
            double prevalence;
        };
        double lifetime;
    };
} element2;

int main() {
    element copper;
    copper.name[0] = 'C';
    copper.name[1] = 'u';
    copper.naturally_occurring = 1;
    copper.extra_fields.natural_info.source
        = "elemental form and smelting from ore";

    element2 copper2;
    copper2.source = "various ores";

    union {
        int i;
        double d;
    } u;
    u.d = 3.14159;
    printf("%d\n", u.i);    /* bad news */
}
