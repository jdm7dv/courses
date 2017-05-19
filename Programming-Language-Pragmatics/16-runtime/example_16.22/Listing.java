// Example 16.22 (Figure 16.4)

import static java.lang.System.out;
import java.lang.reflect.Method;
import java.lang.reflect.Modifier;

public class Listing {
    public static void listMethods(String s)
            throws java.lang.ClassNotFoundException {
        Class c = Class.forName(s);     // throws if class not found
        for (Method m : c.getDeclaredMethods()) {
            out.print(Modifier.toString(m.getModifiers()) + " ");
            out.print(m.getReturnType().getName() + " ");
            out.print(m.getName() + "(");
            boolean first = true;
            for (Class p : m.getParameterTypes()) {
                if (!first) out.print(", ");
                first = false;
                out.print(p.getName());
            }
            out.println(") ");
        }
    }

    public static void main(String[] args) {
        try {
            listMethods("java.lang.reflect.AccessibleObject");
        } catch(java.lang.ClassNotFoundException ex) {
            out.println("oops: " + ex.getMessage());
        }
    }
}
