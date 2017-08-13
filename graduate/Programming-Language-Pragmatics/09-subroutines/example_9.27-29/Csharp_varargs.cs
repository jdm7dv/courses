// Example 9.29

using System;

public class Csharp_varargs
{
    static void print_lines(String foo, params String[] lines) {
        Console.WriteLine("First argument is \"" + foo + "\".");
        Console.WriteLine("There are " +
            lines.Length + " additional arguments:");
        for (int i = 0; i < lines.Length; i++) {
            Console.WriteLine(lines[i]);
        }
    }

    public static void Main(String[] args)
    {
        print_lines("Hello, world",
                    "This is a message",
                    "from your sponsor.");
        Console.WriteLine("");
        print_lines("Just one line");
    }
}
