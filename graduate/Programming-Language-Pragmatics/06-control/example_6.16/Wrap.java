// Example 6.16
// In modern Java, object ht would be generic.  This code is still
// valid, but the compiler generates a warning about "unchecked or
// unsafe operations."

import java.io.*;
import java.util.Hashtable;

public class Wrap {

public static void main(String args[])
{
    Hashtable ht = new Hashtable();

    Integer N = new Integer(13);        // Integer is a "wrapper" class
    ht.put(N, new Integer(31));
    Integer M = (Integer) ht.get(N);
    int m = M.intValue();

    System.out.println(m);              // prints 31
}

};
