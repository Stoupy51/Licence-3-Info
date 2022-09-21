
#include "liste.h"
#include "graphe.h"

int main() {
	fprintf(stderr,"\n\n\n\n\n\n\n\n\n\n\n\n\nDébut du main()\n");

	/**
	 * Tests de la liste chaînée
	** /
	int x;
	Liste l = initListe();
	CELLULE c;
	char prompt = 'Y';
	while (prompt == 'Y' || prompt == 'y') {
		fprintf(stderr,"\nEntrez un entier : ");
		scanf("%d", &x);
		insertListe(&l, newCellule(x));
		printListe(l);
		fprintf(stderr,"\nVoulez-vous continuer d'entrer des valeurs ? (Y/N) ");
		scanf("%s", &prompt);
	}
	prompt = 'Y';
	while (prompt == 'Y' || prompt == 'y') {
		fprintf(stderr,"\nQuel entier voulez-vous supprimer : ");
		scanf("%d", &x);
		c = searchInListe(l, x);
		deleteFromListe(&l, &c);
		printListe(l);
		fprintf(stderr,"\nVoulez-vous continuer de supprimer des valeurs ? (Y/N) ");
		scanf("%s", &prompt);
	}
	destroyListe(&l);
	**/

	/**
	 * Tests du graphe
	**/
	fprintf(stderr,"\n------Graphe (Partie 3.2)------\n");
	Graphe g;
	initGraphe(&g, "graphe1.txt");
	printGraphe(g);
	destroyGraphe(&g);
	printGraphe(g);


	fprintf(stderr,"\n------Graphe (Partie 3.3)------\n");
	char ch_temp[64];
	fprintf(stderr,"\nEntrez le nom du fichier du graphe : ");
	scanf("%s", ch_temp);
	initGraphe(&g, ch_temp);
	printGraphe(g);
	destroyGraphe(&g);


	fprintf(stderr,"\nFin du main()\n");	
	return 0;
}

