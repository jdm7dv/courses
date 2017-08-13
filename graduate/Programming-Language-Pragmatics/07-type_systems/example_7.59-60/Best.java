// Examples 7.59 and 7.60 (Figure 7.6)

interface Chooser<T> {
    public Boolean better(T a, T b);
}

class Arbiter<T> {
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

class CaseSensitive implements Chooser<String> {
    public Boolean better(String a, String b) {
        return a.compareTo(b) < 1;
    }
}

class CaseInsensitive implements Chooser<Object> {
    public Boolean better(Object a, Object b) {
        return a.toString().compareToIgnoreCase(b.toString()) < 1;
    }
}

public class Best {
    public static void main(String args[]) {
        Arbiter<String> csNames = new Arbiter<String>(new CaseSensitive());
        csNames.consider(new String("Apple"));
        csNames.consider(new String("aardvark"));
        System.out.println(csNames.best());         // Apple

        Arbiter<String> ciNames = new Arbiter<String>(new CaseInsensitive());
        ciNames.consider(new String("Apple"));
        ciNames.consider(new String("aardvark"));
        System.out.println(ciNames.best());         // aardvark
    }
}
