// Examples 7.61, 7.62, and 7.63 (Figure 7.7)

interface Chooser<T> {                          // generic
    public Boolean better(T a, T b);
}

/*
interface Chooser {                             // erased
    public Boolean better(Object a, Object b);
}
*/

class Arbiter<T> {                              // generic
    T bestSoFar;
    Chooser<? super T> comp;

    public Arbiter(Chooser<? super T> c) {
        comp = c;
    }
    public void consider(T t) {
        if (bestSoFar == null || comp.better(t, bestSoFar)) bestSoFar = t;
    }
    public T best() {
        return bestSoFar;
    }
}

/*
class Arbiter {                                 // erased
    Object bestSoFar;
    Chooser comp;

    public Arbiter(Chooser c) {
        comp = c;
    }
    public void consider(Object t) {
        if (bestSoFar == null || comp.better(t, bestSoFar)) bestSoFar = t;
    }
    public Object best() {
        return bestSoFar;
    }
}
*/

class CaseSensitive implements Chooser {
    public Boolean better(Object a, Object b) {
        return ((String) a).compareTo((String) b) < 1;
    }
}

class CaseInsensitive implements Chooser {
    public Boolean better(Object a, Object b) {
        return a.toString().compareToIgnoreCase(b.toString()) < 1;
    }
}

public class Erasure {
    public static void main(String args[]) {
        Arbiter csNames = new Arbiter(new CaseSensitive());
        csNames.consider(new String("Apple"));
        csNames.consider(new String("aardvark"));
        System.out.println(csNames.best());         // Apple

        Arbiter ciNames = new Arbiter(new CaseInsensitive());
        ciNames.consider(new String("Apple"));
        ciNames.consider(new String("aardvark"));
        System.out.println(ciNames.best());         // aardvark

        Arbiter<String> csNamesGeneric = new Arbiter<String>(new CaseSensitive());
        Arbiter alias = csNamesGeneric;         // elicits unchecked warning
        alias.consider(new String("Apple"));
        alias.consider(new Integer(3));         // unsafe; will lead to
                                                // dynamic type clash error
        // Arbiter<int> bad;
            // must be instantiated with a reference (class) type
    }
}
