// Example 16.18
// Elicits "unchecked or unsafe operations" warning from the compiler,
// but runs correctly.

import java.util.LinkedList;

class Q extends LinkedList {
    public void enqueue (Object o) {
        add(o);
        System.out.println("Enqueued a " + o.getClass().getName());
    }
    public Object dequeue () {
        Object rtn = remove();
        System.out.println("Dequeued a " + rtn.getClass().getName());
        return rtn;
    }
}

public class MyQueue {
    public static void main(String[] args) {
        Q q = new Q();
        q.enqueue(new Integer(3));
        q.enqueue(q);
        Object o = q.dequeue();
        o = q.dequeue();
    }
}
