// Example 10.22

class Outer {
    int n;
    class Inner {
        public void bar() { n = 1; }
    }
    Inner i;
    Outer() { i = new Inner(); }    // constructor
    public void foo() {
        n = 0;
        System.out.println(n);      // prints 0
        i.bar();
        System.out.println(n);      // prints 1
    }
}

public class Nested {
    public static void main(String[] args) {
        Outer o = new Outer();
        o.foo();
    }
}
