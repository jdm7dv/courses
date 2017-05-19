// Example 6.17, fully generic version

import java.io.*;
import java.util.Hashtable;

public class Wrap2_generic {
    public static void main(String args[]) {
        Hashtable<Integer, Integer> ht = new Hashtable<Integer, Integer>();
            // As printed in the textbook and realized in file Wrap2.java,
            // this program generates a compile-time "unchecked" warning at
            // the call to "put" on the following line.  By specifying generic
            // parameters in the declaration, however, we give the compiler
            // the information it needs to verify type correctness at
            // compile time.

        ht.put(13, 31);
        int m = ht.get(13);
            // Because we specified that ht is a collection of Integers, we
            // don't need the cast here that we needed in the version in the
            // text.

        System.out.println(m);              // prints 31
    }
};
