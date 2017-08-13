// Examples 9.51 and 9.52
// Under mono, must be compiled with "mcs Events.cs -pkg:gtk-sharp-2.0"
// On my Mac, also required the addition of several dll-s to mono's config file.
// See http://stackoverflow.com/questions/13885454/mono-on-osx-couldnt-find-gtksharpglue-2-dll

using System;
using System.Threading;
using Gtk;

// The Counter class is given a window and a label.
// It maintains an internal counter, which it increments once a second,
// and displays on the given label in the given window.
//
class Counter {
    volatile bool running = true;
    Label myLabel;
    public Counter(Window w, Label l) {
        myLabel = l;
        myLabel.Text = "0";
    }
    public void Run() {
        int n = 0;
        while(true) {
            myLabel.Text = n.ToString();
            Thread.Sleep(1000);             // milliseconds
            if (running) n++;
        }
    }
    public void Pause() {
        running = false;
    }
    public void Resume() {
        running = true;
    }
}

// Class Demo, derived from Window, contains a label and two buttons.
// The label houses a Counter (see above).
// The two buttons pause and resume the counter.
// In the code here, the pause button is created in the style of Example
// 8.59; the resume button is created in the style of Example 8.60.
//
class Demo : Window {
    Thread myThread;
    Counter myCount;

    void Paused(object sender, EventArgs a) {
        myCount.Pause();
    }

    public Demo(string title) : base(title) {
        Resize(240,120);

        // Handler for window deletion
        DeleteEvent += delegate(object sender, DeleteEventArgs a) {
            myThread.Abort();
            myThread.Join();
            Application.Quit();
            a.RetVal = true;        // not strictly required
        };

        Label myLabel = new Label();
        Button pauseButton = new Button("pause");
        pauseButton.Clicked += new EventHandler(Paused);

        Button resumeButton = new Button("resume");
        resumeButton.Clicked += delegate(object sender, EventArgs a) {
            myCount.Resume();
        };

        // Window layout
        VBox myBox = new VBox();
        myBox.PackStart(myLabel, false, false, 10);
        myBox.PackStart(pauseButton, false, false, 10);
        myBox.PackStart(resumeButton, false, false, 10);
        Add(myBox);     // Add to window

        myCount = new Counter(this, myLabel);

        // create worker thread to do the counting:
        myThread = new Thread(new ThreadStart(myCount.Run));
        myThread.Start();
    }
}

public class Events {
    public static void Main() {
        Application.Init();

        Demo myWin = new Demo("Event demo");
        myWin.ShowAll();

        Application.Run();      // become an event handler thread
    }
}
