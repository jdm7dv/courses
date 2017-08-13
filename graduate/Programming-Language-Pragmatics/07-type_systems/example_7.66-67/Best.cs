// Examples 7.66 and 7.67 (Figure 7.8)

using System;

interface Chooser<in T> {
    bool better(T a, T b);
}

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
        if (!initialized || comp.better(t, bestSoFar)) bestSoFar = t;
        initialized = true;
    }
    public T Best() {
        return bestSoFar;
    }
}

class CaseSensitive : Chooser<String> {
    public bool better(String a, String b) {
        return String.CompareOrdinal(a, b) < 1;
    }
}

class CaseInsensitive : Chooser<Object> {
    public bool better(Object a, Object b) {
        return String.Compare(a.ToString(), b.ToString(), false) < 1;
    }
}

public class Best {
    public static void Main(String[] args)
    {
        Arbiter<String> csNames = new Arbiter<String>(new CaseSensitive());
        csNames.Consider("Apple");
        csNames.Consider("aardvark");
        Console.WriteLine(csNames.Best());      // Apple

        Arbiter<String> ciNames = new Arbiter<String>(new CaseInsensitive());
        ciNames.Consider("Apple");
        ciNames.Consider("aardvark");
        Console.WriteLine(ciNames.Best());      // aardvark

        Arbiter<int> OKinCsharp;
    }
}
