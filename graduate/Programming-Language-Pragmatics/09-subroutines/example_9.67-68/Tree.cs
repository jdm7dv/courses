// Example 9.67

using System;
using System.Collections;

class TreeNode : IEnumerable {
    TreeNode left;
    TreeNode right;
    object val;

    public IEnumerator GetEnumerator() {
        return new TreeEnumerator(this);
    }

    public TreeNode(TreeNode l, TreeNode r, object v) {
        left = l; right = r; val = v;
    }

    public TreeNode(object v) {
        left = null; right = null; val = v;
    }

    class TreeEnumerator : IEnumerator {
        private Stack s;
        private TreeNode cur;
        private TreeNode orig;

        public TreeEnumerator(TreeNode n) {
            s = new Stack();
            cur = orig = n;
            if (n != null) {
                s.Push(n);
            }
        }

        public bool MoveNext() {
            if (cur == null || s.Count <= 0) {
                return false;
            }
            TreeNode n = (TreeNode) s.Pop();
            if (n.right != null) {
                s.Push(n.right);
            }
            if (n.left != null) {
                s.Push(n.left);
            }
            cur = n;
            return true;
        }

        public object Current {
            get {
                return cur.val;
            }
        }

        public void Reset() {
            cur = orig;
        }
    }

    public void print() {
        Console.WriteLine(val.ToString());
    }
}

public class Tree {
    public static void Main(string[] args) {
        TreeNode a = new TreeNode('a');
        TreeNode f = new TreeNode('f');
        TreeNode c = new TreeNode(f, null, 'c');
        TreeNode d = new TreeNode('d');
        TreeNode b = new TreeNode(c, d, 'b');
        TreeNode myTree = new TreeNode(a, b, 'e');

        for (IEnumerator i = myTree.GetEnumerator(); i.MoveNext();) {
            object o = i.Current;
            Console.WriteLine(o.ToString());
        }

        Console.WriteLine("");

        // Alternative syntax:
        foreach (object o in myTree) {
            Console.WriteLine(o.ToString());
        }
    }
}
