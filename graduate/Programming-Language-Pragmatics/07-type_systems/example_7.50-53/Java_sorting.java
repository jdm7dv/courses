// Example 7.51

import java.lang.Comparable;

public class Java_sorting {

    public static <T extends Comparable<T>> void sort(T A[]) {
        for (int i = 1; i < A.length; i++) {
            // A[0..i-1] is sorted
            int j = i;
            T t = A[i];
            for (; j > 0; j--) {
                if (t.compareTo(A[j-1]) >= 0) break;
                A[j] = A[j-1];
            }
            A[j] = t;
            // A[0..i] is sorted
        }
    }

    public static void main(String args[]) {

        Integer[] myArray = new Integer[20];
        for (int i = 0; i < 20; i+= 2) {
            myArray[19 - i/2] = new Integer(i);
        }
        for (int i = 1; i < 20; i+= 2) {
            myArray[9 - i/2] = new Integer(i);
        }
        for (int i = 0; i < myArray.length; i++) {
            System.out.print(myArray[i] + " ");
        }
        System.out.println("");

        sort(myArray);

        for (int i = 0; i < myArray.length; i++) {
            System.out.print(myArray[i] + " ");
        }
        System.out.println("");
    }
}
