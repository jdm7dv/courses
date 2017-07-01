/* Example 8.19 (Figure 8.7) */

void foo(int size) {
    double M[size][size];
    // ...
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            M[i][j] = i * j;
        }
    }
}

int main() {
    foo(50);
}
