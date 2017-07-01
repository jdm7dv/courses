// Example 8.38

class Chr_tree {
    public Chr_tree left, right;
    public char val;
    Chr_tree(char v, Chr_tree l, Chr_tree r) {      // constructor
        val = v;  left = l;  right = r;
    }
}

public class Java_refs {

public static void main(String args[])
{
    Chr_tree t =
        new Chr_tree('R',
            new Chr_tree('X', null, null),
            new Chr_tree('Y',
                new Chr_tree('Z', null, null),
                new Chr_tree('W', null, null)));

    System.out.println(t.right.left.val);       // Z
}
}
