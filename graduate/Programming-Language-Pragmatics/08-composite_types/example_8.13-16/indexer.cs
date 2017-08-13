// Sidebar 8.3

// This code demonstrates overloading of [].
// Note that the library Hashtable class uses subscript (indexer)
// notation itself.

using System;
using System.Collections;

class directory {
    Hashtable table;                        // from standard library
    public directory() {                    // constructor
        table = new Hashtable();
    }
    public string this[string name] {       // indexer method
        get {
            return (string) table[name];
        }
        set {
            table[name] = value;            // value is implicitly
        }                                   // a parameter of set
    }
}

public class indexer
{
    public static void Main(String[] args)
    {
        directory d = new directory();

        d["Jane Doe"] = "234-5678";
        Console.WriteLine(d["Jane Doe"]);
    }
}
