// Examples 9.53, 9.54, and 9.55

import javafx.application.Application;
import javafx.application.Platform;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

// The Counter class is given a window and a label.
// It maintains an internal counter, which it increments once a second,
// and displays on the given label in the given window.
//
class Counter extends Thread {
    volatile Boolean running = true;
    Label myLabel;

    public Counter(Label l) {
        myLabel = l;
    }

    public void run() {
        int n = 0;
        while(true) {
            final int m = n;
            Platform.runLater(new Runnable() {
                public void run() {
                    myLabel.setText(Integer.toString(m));
                }
            });
            try {
                sleep(1000);   // milliseconds
            } catch(InterruptedException e) {};
            if (running) n++;
        }
    }

    public void pauseMe() {
        running = false;
    }

    public void resumeMe() {
        running = true;
    }
}

// Class Events, derived from Application, contains a label and two
// buttons.  The label houses a Counter (see above).
// The two buttons pause and resume the counter.
// In the code here, the pause button is created in the style of Example
// 8.61; the resume button is created in the style of Example 8.62.
//
public class Events extends Application {
    public static void main(String[] args) {
        launch(args);
    }

    Counter countThread;

    class PauseListener implements EventHandler<ActionEvent> {
        public void handle(ActionEvent e) {
            countThread.pauseMe();
        }
    }

    public void start(Stage stg) {
        stg.setTitle("Event demo");
        stg.setOnCloseRequest(e -> {
            System.exit(0);
        });

        Label countLabel = new Label("0");

        Button pauseButton = new Button();
        pauseButton.setText("pause");
        pauseButton.setOnAction(new PauseListener());

        Button resumeButton = new Button();
        resumeButton.setText("resume");
        // The following also works; commented out in favor of the
        // subsequent lambda expression-based version.
        /*
        resumeButton.setOnAction(new EventHandler<ActionEvent>() {
            public void handle(ActionEvent e) {
                countThread.resumeMe();
            }
        });
        */
        resumeButton.setOnAction(e -> {
            countThread.resumeMe();
        });

        VBox root = new VBox();
        root.getChildren().add(pauseButton);
        root.getChildren().add(resumeButton);
        root.getChildren().add(countLabel);
        stg.setScene(new Scene(root, 300, 300));
        stg.show();

        // create worker thread to do the counting:
        countThread = new Counter(countLabel);
        countThread.start();
    }
}
