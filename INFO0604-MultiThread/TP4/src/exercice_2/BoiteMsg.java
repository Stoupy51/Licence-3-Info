
package exercice_2;

import java.util.Queue;
import java.util.LinkedList;

public class BoiteMsg {
	private Queue<String> msg;
	private boolean isEmpty;
	private Object lock;

	public BoiteMsg() {
		this.msg = new LinkedList<String>();
		this.isEmpty = true;
	}

	public synchronized boolean deposer(String msg) {
		boolean r = this.msg.offer(msg);
		this.isEmpty = this.msg.isEmpty();
		return r;
	}

	public synchronized String recuperer() {
		if (this.isEmpty)
			return "";
		else {
			String r = this.msg.remove();
			this.isEmpty = this.msg.isEmpty();
			return r;
		}
	}

	public void waitOnLock() throws InterruptedException {
		lock.wait();
	}

	public boolean isEmpty() {
		return this.isEmpty;
	}
}

