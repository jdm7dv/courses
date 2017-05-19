// Example 3.33

interface IntFunc {
    public int call(int i);
}

class PlusX implements IntFunc {
    final int x;
    PlusX(int n) { x = n; }
    public int call(int i) { return i + x; }
}

public class Closure {
    public static void main(String[] args) {
        IntFunc f = new PlusX(2);
        System.out.println(f.call(3));      // prints 5
    }
}
