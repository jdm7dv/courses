// Example 7.32

import java.util.*;         // library containing Stack container class

class Foo {
    int n;                  // placeholder
}

public class Java_types {

public static void main(String args[])
{
    Stack myStack = new Stack();    // raw type in Java 5
    String s = "Hi, Mom";
    Foo f = new Foo();      // f is of user-defined class type Foo

    myStack.push(s);
    myStack.push(f);        // we can push any kind of object on a stack
        // Note, however, that uses of non-generic containers are deprecated.
        // These push-es will elicit "unsafe" warnings from the compiler.

    s = (String) myStack.pop();
        // type cast is required, and will generate an exception at run
        // time, since element at top-of-stack is not a string
}
}
