// Example 9.28

public class Java_varargs {
    static void print_lines(String foo, String... lines) {
        System.out.println("First argument is \"" + foo + "\".");
        System.out.println("There are " +
            lines.length + " additional arguments:");
        for (int i = 0; i < lines.length; i++) {
            System.out.println(lines[i]);
        }
    }

    public static void main(String[] args) {
        print_lines("Hello, world", "This is a message", "from your sponsor.");
    }
}
