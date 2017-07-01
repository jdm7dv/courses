// Example 6.68 (Figure 6.6)

import java.util.Iterator;
import java.util.Stack;
import java.util.NoSuchElementException;

class TreeNode<T> implements Iterable<T> {
    TreeNode<T> left;
    TreeNode<T> right;
    T val;

    public Iterator<T> iterator() {
        return new TreeIterator(this);
    }

    TreeNode(TreeNode<T> l, TreeNode<T> r, T v) {
        left = l; right = r; val = v;
    }

    TreeNode(T v) {
        left = null; right = null; val = v;
    }

    private class TreeIterator implements Iterator<T> {
        private Stack<TreeNode<T>> s = new Stack<TreeNode<T>>();

        TreeIterator(TreeNode<T> n) {
            s.push(n);
        }

        public boolean hasNext() {
            return !s.empty();
        }

        public T next() {
            if (!hasNext()) {
                throw new NoSuchElementException();
            }
            TreeNode<T> n = s.pop();
            if (n.right != null) {
                s.push(n.right);
            }
            if (n.left != null) {
                s.push(n.left);
            }
            return n.val;
        }

        public void remove() {
            throw new UnsupportedOperationException();
        }
    }

    public void print() {
        System.out.println(val.toString());
    }
}

public class Tree {
    public static void main(String args[]) {
        TreeNode<Integer> a = new TreeNode<Integer>(1);
        TreeNode<Integer> f = new TreeNode<Integer>(6);
        TreeNode<Integer> c = new TreeNode<Integer>(f, null, 3);
        TreeNode<Integer> d = new TreeNode<Integer>(4);
        TreeNode<Integer> b = new TreeNode<Integer>(c, d, 2);
        TreeNode<Integer> e = new TreeNode<Integer>(a, b, 5);
        for (Iterator<Integer> it = e.iterator(); it.hasNext();) {
            Integer i = it.next();
            System.out.println(i);
        }
        System.out.println("");
        for (Integer i : e) {
            System.out.println(i);
        }
    }
}
