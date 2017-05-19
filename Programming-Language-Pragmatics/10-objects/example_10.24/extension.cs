// Example 10.24

using System;

static class AddToString {
    public static int toInt(this string s) {
        return int.Parse(s);
    }
    public static int toInt2(string s) {            // no 'this'
        return int.Parse(s);
    }
}

public class Extension {
    public static void Main(string[] args) {
        string myString = "12345";
        int n = myString.toInt();
        Console.WriteLine(n);

        int m = AddToString.toInt2(myString);
        Console.WriteLine(m);
    }
}
