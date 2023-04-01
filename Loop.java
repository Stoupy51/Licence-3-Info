
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;

public class Loop {

	public static void main(String[] args) throws Exception {
		while (true) {
			String str = "82.64.248.19";
			System.out.println("IP: " + str);

			// Create UDP socket on IP and port 25565
			DatagramSocket socket = new DatagramSocket(25565);
			InetAddress address = InetAddress.getByName(str);
			System.out.println("Socket: " + socket);

			// Create a packet
			byte[] tampon = "Hello".getBytes();
			DatagramPacket packet = new DatagramPacket(tampon, tampon.length, address, 25565);

			// Receive a packet
			socket.receive(packet);
			System.out.println("Packet receive: " + packet + " " + new String(packet.getData()));

			// Resend the to the client
			socket.send(packet);

			// Close the socket
			socket.close();
			System.out.println("Socket closed\n");

			// Wait 1 second
			Thread.sleep(1000);
		}
	}
}

