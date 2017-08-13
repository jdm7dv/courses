// Example 13.16

using System;
using System.Threading;

class ImageRenderer {
    int id;
    public ImageRenderer(int arg) { id = arg; }
    public void Foo () {        // Foo is compatible with ThreadStart;
                                // its name is not significant
        Console.WriteLine("task " + id + " running");
    }
}

public class Rend {
    public static void Main(String[] args) {
        Thread[] threads = new Thread[10];
        for (int i = 0; i < 10; i++) {
            ImageRenderer rendObj = new ImageRenderer(i);
            threads[i] = new Thread(new ThreadStart(rendObj.Foo));
            threads[i].Start();
        }
        for (int i = 0; i < 10; i++) {
            threads[i].Join();
        }

        Console.WriteLine("");
        for (int i = 0; i < 10; i++) {
            threads[i] = new Thread(delegate() {
                Console.WriteLine("task " + i + " running");
                // NB: There is a race here.  Nothing guarantees that
                // the new thread will read i before the main thread
                // increments it for the next iteration of the loop.
            });
            threads[i].Start();
        }
        for (int i = 0; i < 10; i++) {
            threads[i].Join();
        }
    }
}
