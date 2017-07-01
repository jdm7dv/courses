// Example 7.69

using System;

delegate bool Chooser<T>(T a, T b);

class Arbiter<T> {
    T bestSoFar;
    Chooser<T> comp;
    bool initialized;

    public Arbiter(Chooser<T> c) {
        comp = c;
        bestSoFar = default(T);
        initialized = false;
    }
    public void Consider(T t) {
        if (!initialized || comp(t, bestSoFar)) bestSoFar = t;
        initialized = true;
    }
    public T Best() {
        return bestSoFar;
    }
}

public class SimpleBest {
    static bool CaseSensitive(String a, String b) {
        return String.CompareOrdinal(a, b) < 1;
    }
    static bool CaseInsensitive(Object a, Object b) {
        return String.Compare(a.ToString(), b.ToString(), false) < 1;
    }
    static bool LessThan(double a, double b) {
        return a < b;
    }
    public static void Main(String[] args) {
        Arbiter<String> csNames =
            new Arbiter<String>(new Chooser<String>(CaseSensitive));
        csNames.Consider("Apple");
        csNames.Consider("aardvark");
        Console.WriteLine(csNames.Best());      // Apple

        Arbiter<String> ciNames =
            new Arbiter<String>(new Chooser<String>(CaseInsensitive));
        ciNames.Consider("Apple");
        ciNames.Consider("aardvark");
        Console.WriteLine(ciNames.Best());      // aardvark

        // Note that the CLI virtual machine is aware of CSharp generics --
        // reflection works:
        Console.WriteLine(csNames.GetType().ToString());
    }
}
