// Example 9.68 (Figure 9.12)

using System.Collections;
using System;

class IterTestObj {

    static IEnumerable FromToBy(int fromVal, int toVal, int byAmt) {
        return new FromToByImpl(fromVal, toVal, byAmt);
    }
    class FromToByImpl : IEnumerator, IEnumerable {
        enum State {starting, goingUp, goingDown, done}
        int i, tv, ba;
        State s;

        public FromToByImpl(int fromVal, int toVal, int byAmt) {
            i = fromVal; tv = toVal; ba = byAmt;
            s = State.starting;
        }
        public IEnumerator GetEnumerator() {
            return this;
        }
        public object Current {
            get { return i; }
        }
        public bool MoveNext() {
            switch (s) {
                case State.starting :
                    if (ba >= 0) {
                        if (i <= tv) { s = State.goingUp;  return true; }
                        else { s = State.done;  return false; }
                    } else {
                        if (i >= tv) { s = State.goingDown;  return true; }
                        else { s = State.done;  return false; }
                    }
                case State.goingUp :
                    i += ba;
                    if (i <= tv) return true;
                    else { s = State.done;  return false; }
                case State.goingDown :
                    i += ba;
                    if (i >= tv) return true;
                    else { s = State.done;  return false; }
                default: // for completeness
                case State.done : return false;
            }
        }
        public void Reset() {
            s = State.starting;
        }
    }

    static void Main()
    {
        foreach (int n in FromToBy(1, 10, 2)) {
            Console.WriteLine(n);
            // 1 3 5 7 9
        }
        Console.WriteLine("--");
        foreach (int n in FromToBy(20, 1, -3)) {
            Console.WriteLine(n);
            // 20 17 14 11 8 5 2
        }
        Console.WriteLine("--");
        foreach (int n in FromToBy(2, 2, -3)) {
            Console.WriteLine(n);
            // 2
        }
        Console.WriteLine("--");
        foreach (int n in FromToBy(2, 1, 1)) {
            Console.WriteLine(n);
            // (nothing)
        }
    }
}
