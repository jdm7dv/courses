// Example 6.17

import java.io.*;
import java.util.Hashtable;

public class Wrap2 {
    public static void main(String args[]) {
        Hashtable ht = new Hashtable();
            // In modern Java all library collections (containers) are generic,
            // and must hold objects of only one type (or its descendants).
            // Variable ht, however, is a "raw" type, declared without
            // generic arguments, so the compiler doesn't know what that
            // type is.

        ht.put(13, 31);
            // This statement produces an "unchecked" warning.  Because the
            // compiler does not know the type of objects held in ht, it can't
            // tell whether the Integers we're passing in are of the correct
            // type.  The program does, however, perform correctly.
        int m = (Integer) ht.get(13);

        System.out.println(m);              // prints 31
    }
};
