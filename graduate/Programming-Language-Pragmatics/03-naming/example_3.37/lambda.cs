// Example 3.37

using System;

delegate int IntFunc(int i);

public class Lambda {

    static IntFunc PlusY(int y) {
        return i => i + y;
    }

    public static void Main(String[] args)
    {
        IntFunc h = PlusY(2);
        Console.WriteLine(h(3));
    }
}
