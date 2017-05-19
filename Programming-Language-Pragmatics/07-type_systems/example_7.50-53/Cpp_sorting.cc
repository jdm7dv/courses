// Example 7.53

#include <iostream>

template<typename T>
void sort(T A[], int A_size) {
    for (int i = 1; i < A_size; i++) {
        int j = i;  T t = A[i];
        for (; j > 0; j--) {
            if (t >= A[j-1]) break;
            A[j] = A[j-1];
        }
        A[j] = t;
    }
}

int ints[20] =
    {19, 17, 15, 13, 11, 9, 7, 5, 3, 1,
     18, 16, 14, 12, 10, 8, 6, 4, 2, 0};

const char *strings[16] =
    {"now", "is", "the", "time", "for", "all", "good", "folk",
    "to", "come", "to", "the", "aid", "of", "the", "party"};

int main () {
    for (int i = 0; i < 20; i++)  printf("%d ", ints[i]);
    printf("\n");
    sort(ints, 20);
    for (int i = 0; i < 20; i++)  printf("%d ", ints[i]);
    printf("\n");

    for (int i = 0; i < 16; i++)  printf("%s ", strings[i]);
    printf("\n");
    sort(strings, 16);     // oops!  sorting by address
    for (int i = 0; i < 16; i++)  printf("%s ", strings[i]);
    printf("\n");
}
