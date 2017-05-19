// Example 13.15

// Java 2 compliant.  Also runs under Java 5 and following, but users of
// the more recent language versions are encouraged to use Executors
// rather than creating threads explicitly.

import java.lang.Thread.*;

class image_renderer extends Thread {
    int id;
    image_renderer(int arg) {id = arg;}
    public void run() {
        System.out.println("task " + id + " running");
    }
}

public class Rend2 {
    public static void main(String args[]) {
        image_renderer rends[] = new image_renderer[10];
        for (int i = 0; i < 10; i++) {
            rends[i] = new image_renderer(i);
        }
        for (int i = 0; i < 10; i++) {
            rends[i].start();
        }
        for (int i = 0; i < 10; i++) {
            try {
                rends[i].join();
            } catch (InterruptedException e) {
                // join() may throw this if another thread kicks us
                // while we're waiting for a child to complete
            }
        }
    }
}
