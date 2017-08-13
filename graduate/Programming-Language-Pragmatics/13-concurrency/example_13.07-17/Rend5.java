// Example 13.17

// Runs only on Java 5 and later.
// Note that an Executor waits indefinitely for new tasks.  This program,
// therefore, does not terminate.  If you want termination, use the more
// detailed ExecutorService interface, which supports the shutdown() method.
// Calls to use this interface appear in comments below.

import java.util.concurrent.*;
import java.util.concurrent.ExecutorService.*;

class image_renderer implements Runnable {
    int id;
    image_renderer(int arg) {id = arg;}
    public void run () {
        System.out.println("task " + id + " running");
    }
}

public class Rend5 {
    public static void main(String args[]) {
//      ExecutorService pool = Executors.newFixedThreadPool(4);
        Executor pool = Executors.newFixedThreadPool(4);
        for (int i = 0; i < 10; i++) {
            pool.execute(new image_renderer(i));
        }
//      pool.shutdown();
    }
}
