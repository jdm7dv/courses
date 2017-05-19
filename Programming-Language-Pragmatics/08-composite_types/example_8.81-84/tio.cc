// Examples 8.81, 8.82, 8.83, and 8.84

#include <iostream>
using std::cout;
using std::ostream;
using std::oct;
using std::ios;

#include <iomanip>
using std::setw;
using std::setiosflags;
using std::setprecision;

int main() {
    ostream &my_stream = cout;
    const char *s = "hi, mom\n";
    my_stream << s;

    int n = 3;
    my_stream << s << n;
    my_stream << "\n";

    /*  Example 7.140 is not quite correct as written.  In actuality,
        a << b can be an abbreviation for either a.operator<<(b) or
        operator<<(a, b).  It turns out that in the C++ standard
        library, there is an overloaded non-member function with the
        prototype ostream& operator<<(ostream&, char*) and a member
        function with the prototype ostream::operator<<(void*).
        The former is a better match for overload resolution, so
        "my_stream << s << n" is actually equivalent to the following:
     */
    operator<<(my_stream, s).operator<<(n);
    my_stream << "\n";

    /*  If we force the use of the member function by using member syntax,
        the compiler coerces the char* to void*, and prints (in hex) the
        address that it contains, rather than the string at that address:
     */
    (my_stream.operator<<(s)).operator<<(n);
        // prints 0x1234abcd3 for some address 0x1234abcd
    my_stream << "\n";

    n = 123;
    my_stream << oct << n;

    my_stream << setw(20) << s << setw(10) << n;
    my_stream << "\n";

    {
        char s[20] = "abcde";
        int n = 3;
        double r[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        int i;

        my_stream << setw(20) << s << setw(10) << n;
        my_stream << "\n";
        for (i = 0; i < 10; i++)
            my_stream << setiosflags(ios::fixed)
                << setw(8) << setprecision(2) << r[i];
        my_stream << "\n";

        ios::fmtflags old_flags =
            my_stream.flags(my_stream.flags() | ios::fixed);
        int old_precision = my_stream.precision(2);
        for (i = 0; i < 10; i++) my_stream << setw(8) << r[i];
        my_stream.flags(old_flags);
        my_stream.precision(old_precision);
    }
}
