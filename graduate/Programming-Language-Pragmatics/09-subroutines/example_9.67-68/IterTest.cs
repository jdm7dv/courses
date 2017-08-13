// Example 9.68

using System.Collections;
using System;

class IterTest {

    static IEnumerable FromToBy(int fromVal, int toVal, int byAmt)
    {
        if (byAmt >= 0) {
            for (int i = fromVal; i <= toVal; i += byAmt) {
                yield return i;
            }
        } else {
            for (int i = fromVal; i >= toVal; i += byAmt) {
                yield return i;
            }
        }
    }

    static void Main()
    {
        foreach (int n in FromToBy(1, 10, 2)) {
            Console.WriteLine(n);
        }
    }
}
