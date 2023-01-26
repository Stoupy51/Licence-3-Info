
package m_thread;

import src.Messenger;

public class m_main {
	private static Messenger messenger = new Messenger("");

    public static void main(String[] args) throws Exception {
		messenger.afficheRouge("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nDébut de la fonction main()\n");
        Long time = System.currentTimeMillis();

		// Création des threads
		Thread t1 = new thread_extends("Thread Extends");
		Thread t2 = new Thread(new thread_implements("Thread Implements"));
		t1.start();
		t2.start();

		// Attente de la fin des threads
		t1.join();
		t2.join();

        messenger.afficheRouge("\n\nFin de la fonction main() en "+Long.toString((System.currentTimeMillis()-time))+"ms\n");
    }
}

