// Example 13.57

// In "real world" code the server and client would be separate programs,
// typically running on separate machines.  For the sake of simplicity we
// make them separate threads in a single program here.

// Note that UDP delivery is not guaranteed, though the fact that
// everything is local makes it pretty likely in this example.  In more
// realistic code the server would need to send an acknowledgment.  The
// client would wait for that acknowledgment, and resend if it didn't
// arrive within a reasonable amount of time.

import java.net.*;
import java.io.IOException;

class server extends Thread {
    // no constructor needed for this trivial example
    public static final int serverBufLen = 30;
    public static final int serverPort = 2345;
        // "well known number" for service
    public void run() {
        byte buf[] = new byte[serverBufLen];
        try {
            DatagramSocket my_socket = new DatagramSocket(serverPort);
            DatagramPacket my_msg = new DatagramPacket(buf, serverBufLen);
            my_socket.receive(my_msg);
            String s = new String(buf);
            System.out.println(s);
        } catch (SocketException e) {
            System.out.println("Could not open server socket\n");
        } catch (IOException e) {
            System.out.println("IO Exception on receive\n");
        }
    }
}

class client extends Thread {
    // no constructor needed for this trivial example
    public void run() {
        try {
            byte buf[] = {'H', 'i', ',', ' ', 'M', 'o', 'm', '\n', 0};
            InetAddress addr = InetAddress.getLocalHost();
            int port = server.serverPort;
            DatagramSocket my_socket = new DatagramSocket();
            DatagramPacket my_msg = new DatagramPacket(buf, 9, addr, port);
            my_socket.send(my_msg);
        } catch (UnknownHostException e) {
            System.out.println("Can't identify localhost\n");
        } catch (SocketException e) {
            System.out.println("Could not open client socket\n");
        } catch (IOException e) {
            System.out.println("IO Exception on send\n");
        }
    }
}

public class UDP {

    public static void main(String args[]) {
        server s = new server();
        client c = new client();
        s.start();
        c.start();
    }
}
