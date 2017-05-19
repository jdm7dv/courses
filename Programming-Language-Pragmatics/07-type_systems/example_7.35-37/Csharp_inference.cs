// Example 7.35

using System;
using System.Collections.Generic;

public class Csharp_inference {
    public static void Main(string[] args) {
        var i = 123;        // equivalent to int i = 123;
        Console.WriteLine(i);
        var map = new Dictionary<string, int>();
            // equivalent to Dictionary<istring, int> map
            //  = new Dictionary<string, int>();
        map.Add("foo", 3);
        int n;
        map.TryGetValue("foo", out n);
        Console.WriteLine(n);
    }
}
