
package m_thread;

import src.Messenger;

public class thread_extends extends Thread {
	private Messenger messenger;

	public thread_extends(String name) {
		this.messenger = new Messenger(name);
	}

	public void run() {
		messenger.afficheWarning("Début du thread");

		// Hello World!
		messenger.afficheMessage("Hello World!");
		
		messenger.afficheWarning("Fin du thread");
	}
}
