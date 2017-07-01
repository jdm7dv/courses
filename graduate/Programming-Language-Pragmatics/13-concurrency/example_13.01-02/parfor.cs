// Examples 13.1 and 13.2

using System;
using System.Threading.Tasks;

public class ParFor {
    static int zero_count = 0;
    public static int foo(int n) {
        int rtn = n - 1;
        if (rtn == 0) zero_count++;
        return rtn;
    }
    public static void Main(string[] args) {
        int[] A = new int[100];

        for (int i = 0; i < 100; i++) {             // initialization
            A[i] = i % 10 + 1;
        }
        Parallel.For(0, 100, i => { A[i] = foo(A[i]); } );
        Console.WriteLine(zero_count);
    }
}
