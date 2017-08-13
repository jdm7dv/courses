// Example 16.23
// Elicits an "unchecked or unsafe operations" warning from the
// compiler, but runs correctly.

import static java.lang.System.out;
import java.lang.reflect.Method;
import java.util.Stack;

public class Invoking {
    public static void main(String[] args) {
        Stack s = new Stack();
        s.push(new Integer(3));
        try {
            Object u = s;
            Method uMethods[] = u.getClass().getMethods();
            Method method1 = uMethods[1];
            Object rtn = method1.invoke(u);     // u.pop()
            out.println(rtn.getClass().getName());
            out.println(((Integer) rtn).intValue());
        } catch(java.lang.reflect.InvocationTargetException ex) {
            out.println("oops: " + ex.getMessage());
        } catch(java.lang.IllegalAccessException ex) {
            out.println("oops: " + ex.getMessage());
        }
    }
}
