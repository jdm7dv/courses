// Example 13.51

using System;
using System.Threading.Tasks;

class Product {
    string name;
    int count;

    public Product(string n, int c) { name = n; count = c; }

    string GetDescription() { return name; }
    int GetInventory() { return count; }

    public void PrintInfo() {
        var description = Task.Factory.StartNew(() => GetDescription());
        var numberInStock = Task.Factory.StartNew(() => GetInventory());

        Console.WriteLine("We have " + numberInStock.Result
            + " copies of " + description.Result + " in stock");
    }
}

public class Futures {
    
    public static void Main(string[] args) {
        Product myProduct = new Product("foo", 3);
        myProduct.PrintInfo();
    }
}
