
#include "liste.h"
#include "graphe.h"

int main() {
	fprintf(stderr,"\n\n\n\n\n\n\n\n\n\n\n\n\nDébut du main()\n");

#define TP 3
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
	destroyGraphe(g);
	printGraphe(g);


	fprintf(stderr,"\n------Graphe (Partie 3.3)------\n");
	char ch_temp[64];
	fprintf(stderr,"\nEntrez le nom du fichier du graphe : ");
	scanf("%s", ch_temp);
	initGraphe(&g, ch_temp);
	printGraphe(g);
	destroyGraphe(g);
#endif

#if TP == 2
	fprintf(stderr,"\n------Tests de queue------\n");
	Queue q = initQueue(5);
	printQueue(q);
	enfilerQueue(&q, 1);
	enfilerQueue(&q, 3);
	enfilerQueue(&q, 5);
	printQueue(q);

	fprintf(stderr,"\n------Parcours Largeur------\n");
	Graphe g;
	initGraphe(&g, "graphe2.txt");
	int i;
	parcoursLargeur(&g, 0);
	for (i = 0; i < g.n_sommets; i++)
		afficherChemin(g, 0, i);
	
	fprintf(stderr,"\n------Parcours Profondeur Recursif------\n");
	parcoursProfondeurRecursif(&g);
	afficherParcoursProfondeur(g);

	fprintf(stderr,"\n\n------Parcours Profondeur Iteratif------\n");
	parcoursProfondeurIteratif(&g);
	afficherParcoursProfondeur(g);
#endif

#if TP == 3
	fprintf(stderr,"\n------Tests de Tableau D'arêtes------\n");
	Graphe g;
	initGrapheAvecPoids(&g, "graphe5.txt");

	Arete* a = getAretes(g);
	printPoidsAretes(a);
	sortAretesInsertion(a);
	printPoidsAretes(a);
	
	fprintf(stderr,"\n------Tests du Tas------\n");
	Arete* b = (Arete*)malloc(sizeof(Arete) * 11);
	b[0] = newArete(0, 0, 10);
	b[1] = newArete(0, 0, 4);
	b[2] = newArete(0, 0, 1);
	b[3] = newArete(0, 0, 3);
	b[4] = newArete(0, 0, 2);
	b[5] = newArete(0, 0, 16);
	b[6] = newArete(0, 0, 9);
	b[7] = newArete(0, 0, 10);
	b[8] = newArete(0, 0, 14);
	b[9] = newArete(0, 0, 8);
	b[10] = newArete(0, 0, 7);
	printPoidsAretes(b);
	sortAretesTas(b);
	printPoidsAretes(b);

#endif

	fprintf(stderr,"\nFin du main()\n");	
	return 0;
}

