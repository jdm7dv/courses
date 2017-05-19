// Example 16.40 (Figure 16.7)

using System;

public class LLset {
    node head;
    class node {
        public int val;
        public node next;
    }
    public LLset() {                // constructor
        head = new node();          // head node contains no real data
        head.next = null;
    }
    public void insert(int v) {
        node n = head;
        while (n.next != null
                && n.next.val < v) {
            n = n.next;
        }
        if (n.next == null
                || n.next.val > v) {
            node t = new node();
            t.val = v;
            t.next = n.next;
            n.next = t;
        } // else v is already in set
    }
    public static void Main(string[] args) {
        LLset S = new LLset();
        S.insert(3);
        S.insert(11);
        S.insert(7);
        S.insert(3);
        node n = S.head.next;
        while (n != null) {
            Console.WriteLine(n.val);
            n = n.next;
        }
    }
}
