
#include "liste.h"
#include "graphe.h"

int main() {
	fprintf(stderr,"\n\n\n\n\n\n\n\n\n\n\n\n\nDébut du main()\n");

#define TP 2
#if TP == 1
	/**
	 * Tests de la liste chaînée
	**/
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
#endif

#if TP == 2
	fprintf(stderr,"\n------Tests de queue------\n");
	Queue q = initQueue(5);
	printQueue(q);
	enfilerQueue(q, initSommet(1));
	enfilerQueue(q, initSommet(3));
	enfilerQueue(q, initSommet(5));
	printQueue(q);

#endif

	fprintf(stderr,"\nFin du main()\n");	
	return 0;
}

