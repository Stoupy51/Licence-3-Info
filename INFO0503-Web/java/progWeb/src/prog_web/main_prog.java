
package prog_web;

public class main_prog {
    public main_prog() {}

    public static void main(String[] args) throws Exception {
        System.out.println("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nDébut de la fonction main()\n");
        Long time = System.currentTimeMillis();


		// construire votre objet à partir des caractéristiques indépendantes du code;
        CodeDeSuivi code = new CodeDeSuivi("0-2573.0-1200.0-3-true-FR-0.1546-400.0-1665232943");
        System.out.println("\n"+code+"\n");

		// récupérer une caractéristiques en particuliers;
		System.out.println("\nenergyType: "+Integer.toString(code.getEnergyType()));
		System.out.println("quantity: "+Float.toString(code.getQuantity()));
		System.out.println("minQuantity: "+Float.toString(code.getMinQuantity()));
		System.out.println("extractMode: "+Integer.toString(code.getExtractMode()));
		System.out.println("extractModeStrict: "+code.getExtractModeStrict());
		System.out.println("energyFromCountry: "+code.getEnergyFromCountry());
		System.out.println("maxPrice: "+Float.toString(code.getMaxPrice()));
		System.out.println("maxBudget: "+Float.toString(code.getMaxBudget()));
		System.out.println("date: "+Integer.toString(code.getDate()));

		// transformer votre objet en String JSON;
		System.out.println("\nJSON: "+code.toJSON()+"\n");

		// reconstruire un objet CodeDeSuivi depuis un String JSON;
		CodeDeSuivi code2 = CodeDeSuivi.fromJSON(code.toJSON());
		System.out.println("\n"+code2+"\n");

		// trier des instances de CodeDeSuivi selon la quantité d'énergie qu'il décrive.
		// Pour ce faire, on implémentera l'interface Comparable.
		CodeDeSuivi[] codes = {code2, new CodeDeSuivi("0-2700.0-1200.0-3-true-FR-0.1546-400.0-1665232943"), new CodeDeSuivi("0-2300.0-1200.0-3-true-FR-0.1546-400.0-1665232943")};
		System.out.println("\nAvant le tri : "+codes[0]+", "+codes[1]+", "+codes[2]);
		java.util.Arrays.sort(codes);
		System.out.println("Après le tri : "+codes[0]+", "+codes[1]+", "+codes[2]);



        System.out.println("\n\nFin de la fonction main() en "+Long.toString((System.currentTimeMillis()-time))+"ms\n");
    }
}

