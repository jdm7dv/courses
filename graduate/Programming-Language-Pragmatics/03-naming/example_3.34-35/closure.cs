// Examples 3.34 and 3.35

using System;

delegate int IntFunc(int i);

class PlusX {
    int x;
    public PlusX(int n) { x = n; }
    public int call(int i) { return i + x; }
}

public class Closure {

    static int Plus2(int i) { return i + 2; }

    static IntFunc PlusY(int y) {
        return delegate(int i) { return i + y; };
    }
    static IntFunc PlusZ(int z) {
        return i => i + z;
    }

    public static void Main(String[] args)
    {
        IntFunc f = new IntFunc(Plus2);
        Console.WriteLine(f(3));

        IntFunc g = new IntFunc(new PlusX(2).call);
        Console.WriteLine(g(3));
        
        IntFunc h = PlusY(2);
        Console.WriteLine(h(3));

        IntFunc k = PlusZ(2);
        Console.WriteLine(k(3));
    }
}
