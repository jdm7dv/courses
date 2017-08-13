// Example 16.39

using System;

class Node<T> {
    public T val;
    public Node<T> next;
}

public class Reflect {
    public static void Main(string[] args) {
        Node<int> n = new Node<int>();
        n.val = 3;  n.next = n;  // suppress "never assigned to" warnings

        Console.WriteLine(n.GetType().ToString());
    }
}
