// Example 3.20

#include <iostream>
using std::cout;

double sum, sum_of_squares;

void accumulate(double& x) {    // x passed by reference
    sum += x;
    sum_of_squares += x * x;
}

int main() {
    sum = sum_of_squares = 0.0;
    double one = 1.0;
    double two = 2.0;
    double three = 3.0;

    accumulate(one);
    cout << sum << " " << sum_of_squares << "\n";
    accumulate(two);
    cout << sum << " " << sum_of_squares << "\n";
    accumulate(three);
    cout << sum << " " << sum_of_squares << "\n";

    // At this point sum is 6 and sum_of_squares is 14.
    // The programmer probably intends the following line to set sum to 12
    // and sum_of_squares to 14 + 6*6 = 50, but it doesn't.

    accumulate(sum);
    cout << sum << " " << sum_of_squares << "\n";
}
