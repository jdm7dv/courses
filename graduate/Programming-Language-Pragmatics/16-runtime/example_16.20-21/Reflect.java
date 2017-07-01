// Examples 16.20 and 16.21

class Foo {}

public class Reflect {
    public static void main(String[] args) {
        int[] A = new int[10];
        System.out.println(A.getClass().getName());
        String[] C = new String[10];
        System.out.println(C.getClass().getName());
        Foo[][] D = new Foo[10][10];
        System.out.println(D.getClass().getName());

        System.out.println("");

        Object o = new Object();
        System.out.println(o.getClass().getName());
        System.out.println(Object.class.getName());

        System.out.println("");

        try {
            Class stringClass = Class.forName("java.lang.String");
            Class intArrayClass = Class.forName("[I");
            Class intClass = Integer.TYPE;
            System.out.println(stringClass.getName());
            System.out.println(intArrayClass.getName());
            System.out.println(intClass.getName());
        } catch(java.lang.ClassNotFoundException ex) {
            System.out.println("oops: " + ex.getMessage());
        }
    }
}
