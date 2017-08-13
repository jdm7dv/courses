// Example 13.9

using System;
using System.Threading.Tasks;

public class ParFor {
    public static void Main(string[] args) {
        Parallel.For(0, 3, i => {
            Console.WriteLine("Thread " + i + " here");
        });
    }
}
