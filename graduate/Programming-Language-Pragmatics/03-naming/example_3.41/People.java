// Example 3.41

import java.util.Comparator;
import java.util.Arrays;

class AgeComparator implements Comparator<Person> {
   public int compare(Person p1, Person p2) {
       return Integer.compare(p1.age, p2.age);
   }
}

class Person {
    public String name;
    public int age;
    public Person(String n, int a) { name = n; age = a; }
    public void Print() { System.out.println(name + " " + age); }
};

public class People {
    public static void main(String[] args) {
        Person[] People = new Person[3];
        People[0] = new Person("Alice", 20);
        People[1] = new Person("Bob", 18);
        People[2] = new Person("Carol", 19);

        Arrays.sort(People, new AgeComparator());

        for (Person p : People) {
            p.Print();
        }
    }
}

