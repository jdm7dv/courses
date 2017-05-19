// Examples C-3.52 and C-3.53
// compile with javac -classpath . bar2.java

import foo.foo_type_1;
public class bar2 {
    public static void main(String[] args) {
        foo_type_1 my_first_obj = new foo_type_1();
        System.out.println(my_first_obj.n + 2);
    }
}
