// Example 16.6

using System;
using System.Linq.Expressions;

public class Expr {
    public static void Main(string[] args) {
        Func<int, int> square_func = x=> x * x;
        int y = square_func(3);

        Expression<Func<int, int>> square_tree = x => x * x;
        var square_func2 = square_tree.Compile();
        int z = square_func2(3);

        Console.WriteLine(y + " " + z);
    }
}
