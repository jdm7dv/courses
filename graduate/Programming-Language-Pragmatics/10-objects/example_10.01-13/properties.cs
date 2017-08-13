// Example 10.7

using System;

class list_node {
    // ...
    int val;                // val (lower case 'v') is private
    public int Val {
        get {               // presence of get accessor and optional
            return val;     // set accessor means that Val is a property
        }
        set {
            val = value;    // value is a keyword: argument to set
        }
    }
    // ...
}

public class properties {
    public static void Main(String[] args)
    {
        list_node n;
        // ...
        n = new list_node();
        // ...
        n.Val = 3;          // implicit call to set method
        int a = n.Val;      // implicit call to get method

        Console.WriteLine(a);
    }
}
