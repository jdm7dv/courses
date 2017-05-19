// Example 13.58

// In "real world" code the server and client would be separate programs,
// typically running on separate machines.  For the sake of simplicity we
// make them separate threads in a single program here.

import java.net.*;
import java.io.*;

class server extends Thread {
    // no constructor needed for this trivial example
    public static final int serverBufLen = 30;
    public static final int serverPort = 2345;
        // "well known number" for service
    public void run() {
        byte buf[] = new byte[serverBufLen];
        try {
            ServerSocket my_server_socket = new ServerSocket(serverPort);
            Socket client_connection = my_server_socket.accept();
            BufferedReader in =
                new BufferedReader(new InputStreamReader(
                                client_connection.getInputStream()));
                // getInputStream returns an InputStream, from which
                // one can read bytes.  InputStreamReader is a converter
                // from byte streams to character streams.  BufferedReader
                // provides efficient line-at-a-time access.
            PrintStream out =
                new PrintStream(client_connection.getOutputStream());

            System.out.println(in.readLine());
            out.println("Hi yourself\n");

        } catch (IOException e) {
            System.out.println("IO Exception on receive\n");
        }
    }
}

class client extends Thread {
    // no constructor needed for this trivial example
    public void run() {
        try {
            Socket server_connection =
                new Socket(InetAddress.getLocalHost(), server.serverPort);
            PrintStream out =
                new PrintStream(server_connection.getOutputStream());
            BufferedReader in =
                new BufferedReader(new InputStreamReader(
                                server_connection.getInputStream()));

            out.println("Hi, Mom\n");
            System.out.println(in.readLine());

        } catch (UnknownHostException e) {
            System.out.println("Can't identify localhost\n");
        } catch (IOException e) {
            System.out.println("IO Exception on send\n");
        }
    }
}

public class TCP {

    public static void main(String args[]) {
        server s = new server();
        client c = new client();
        s.start();
        c.start();
    }
}
