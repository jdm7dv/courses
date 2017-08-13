// Example 16.39

class Node<T> {
    public T val;
    public Node<T> next;
}

public class Reflect {
    public static void main(String[] args) {
        Node<Integer> n = new Node<Integer>();

        System.out.println(n.getClass().toString());
    }
}
