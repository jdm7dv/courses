// Example 3.38

using System;

public class Maximum {
    public static void Main(String[] args)
    {
        Func<int, int, int> m = (i, j) => i > j ? i : j;
        Console.WriteLine(m.Invoke(5, 8));
    }
}
