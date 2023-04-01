
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;

public class Mainjava {

	public static void main(String[] args) throws Exception {
		int a = 2;
		while (true) {
			a = (a + 1) % 3;
			String str = a == 0 ? "109.122.198.158" : (a == 1 ? "82.64.248.19" : "89.85.97.213");
			System.out.println("IP: " + str);

			// Create UDP socket on IP and port 25565
			DatagramSocket socket = new DatagramSocket(25565);
			InetAddress address = InetAddress.getByName(str);
			System.out.println("Socket: " + socket);

			// Create a packet
			byte[] tampon = "Hello".getBytes();
			DatagramPacket packet = new DatagramPacket(tampon, tampon.length, address, 25565);

			// Print packet content
			System.out.println("Packet to send: " + packet + " " + new String(packet.getData()));

			// Send the packet
			socket.send(packet);

			// Receive a packet
			socket.receive(packet);
			System.out.println("Packet receive: " + packet + " " + new String(packet.getData()));

			// Close the socket
			socket.close();
			System.out.println("Socket closed\n");

			// Wait 1 second
			Thread.sleep(1000);
		}
	}
}

