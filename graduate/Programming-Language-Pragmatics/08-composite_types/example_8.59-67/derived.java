// Example 8.67

class Element {
    public String name;
    public int atomic_number;
    public double atomic_weight;
    public boolean metallic;
}
class NaturalElement extends Element {
    public String source;
    public double prevalence;
}
class SyntheticElement extends Element {
    public double lifetime;
}

public class derived {

public static void main(String args[])
{
    NaturalElement ne = new NaturalElement();
    SyntheticElement se = new SyntheticElement();
    Element e = ne;
    // se = e;                  // error
    se = (SyntheticElement) e;  // ok; produces dynamic check

    ne.name = "copper";
    se.name = "plutonium";
    se.lifetime = 24000 * 365 * 24 * 60 * 60;
    // ne.lifetime = 3;     // error
}
}
