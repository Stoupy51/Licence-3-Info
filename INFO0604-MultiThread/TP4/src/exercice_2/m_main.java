
package exercice_2;

import utils.Logger;
import utils.MainSupport;

public class m_main {
	private final static Logger logger = new Logger("");
	private static MainSupport mainSupport;

    public static void main(String[] args) throws Exception {
		mainSupport = new MainSupport(logger);

		// Initializations
		int nb_threads = 2;
		Thread th_producteurs[] = new Thread[nb_threads];
		Thread th_consommateurs[] = new Thread[nb_threads];
		BoiteMsg boite = new BoiteMsg();

		// Création des threads
		for (int i = 0; i < nb_threads; i++) {
			th_producteurs[i] = new Thread(new Producteur("Producteur", i, boite));
			th_consommateurs[i] = new Thread(new Consommateur("Consommateur", i, boite));
			th_producteurs[i].start();
			th_consommateurs[i].start();
		}

		// Attente de la fin des threads
		for (int i = 0; i < nb_threads; i++) {
			th_producteurs[i].join();
			th_consommateurs[i].join();
		}

		mainSupport.end();
	}
}

