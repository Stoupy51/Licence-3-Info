
package m_thread;

import src.Messenger;

public class thread_implements implements Runnable {
	private Messenger messenger;

	public thread_implements(String name) {
		this.messenger = new Messenger(name);
	}

	public void run() {
		messenger.afficheWarning("Début du thread");

		// Hello World!
		messenger.afficheMessage("Hello World!");
		
		messenger.afficheWarning("Fin du thread");
	}
}
