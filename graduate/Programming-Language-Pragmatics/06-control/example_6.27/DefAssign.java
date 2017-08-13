// Example 6.27

import java.io.*;
import java.lang.Integer;

public class DefAssign {
    final static int j = 3;
    public static void main(String args[]) {
        int i;
        int j = Integer.decode(args[1]).intValue();

        if (j > 0) {
            i = 2;
        }
        //                                 no assignments to j in here
        if (j > 0) {
            System.out.println(i);      // disallowed by definite assignment
        }
    }
};
