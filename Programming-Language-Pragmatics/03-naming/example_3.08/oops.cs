// Example 3.8

class A
{
    const int N = 10;

    void foo() {
        const int M = N;
            // static semantic error
        const int N = 20;
            // mcs complains here: "A local variable `N' cannot be used
            // before it is declared. Consider renaming the local
            // variable when it hides the member `A.N'"
    }

    public static void Main(string[] args) {
        Console.WriteLine("nothing to see here");
    }
}
