// Example 7.52

using System;

public class Csharp_sorting {

    static void sort<T>(T[] A) where T : IComparable {
        for (int i = 1; i < A.Length; i++) {
            int j = i;  T t = A[i];
            for (; j > 0; j--) {
                if (t.CompareTo(A[j-1]) >= 0) break;
                A[j] = A[j-1];
            }
            A[j] = t;
        }
    }

    public static void Main(String[] args)
    {
        int[] myArray = new int[20];
        for (int i = 0; i < 20; i+= 2) {
            myArray[19 - i/2] = i;
        }
        for (int i = 1; i < 20; i+= 2) {
            myArray[9 - i/2] = i;
        }
        for (int i = 0; i < myArray.Length; i++) {
            Console.Write(myArray[i] + " ");
        }
        Console.WriteLine("");

        sort(myArray);

        for (int i = 0; i < myArray.Length; i++) {
            Console.Write(myArray[i] + " ");
        }
        Console.WriteLine("");
    }
}
