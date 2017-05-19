// Exercise 10.21 (Figure 10.8)

interface Pingable {
   public void ping();
}

class Counter implements Pingable {
   int count = 0;
   public void ping() {
       ++count;
   }
   public int val() {
       return count;
   }
}

public class Ping {
   public static void main(String args[]) {
       Counter c = new Counter();
       c.ping();
       c.ping();
       int v = c.val();
       System.out.println(v);
   }
}
