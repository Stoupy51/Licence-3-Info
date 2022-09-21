
#include "graphe.h"

void initGraphe(Graphe* g, char* fileName) {
	FILE* file;
	char ch_temp[20];
	if ((file = fopen(fileName, "r"))) {
		fscanf(file,"%s", ch_temp);
		fscanf(file,"%d", &g->n_sommets);
		fscanf(file,"%s", ch_temp);
		fscanf(file,"%d", &g->oriente);
		fscanf(file,"%s", ch_temp);
		fscanf(file,"%d", &g->value);
		fscanf(file,"%s", ch_temp);
		fscanf(file,"%s", ch_temp);
		g->m_stockage = (int*)malloc(sizeof(int)*g->n_sommets*g->n_sommets);
		g->m_adj = (int**)malloc(sizeof(int*)*g->n_sommets);
		g->l_adj = (Liste*)malloc(sizeof(Liste)*g->n_sommets);
		int i, j;
		for (i = 0; i < g->n_sommets; i++) {
			g->m_adj[i] = &g->m_stockage[i*g->n_sommets];
			for (j = 0; j < g->n_sommets; j++)
				g->m_stockage[i*j] = 0;
			g->l_adj[i] = initListe();
		}
		// Si la liste n'est pas orientée
		if (!g->oriente) {
			while (ch_temp[0] != 'F') {
				i = atoi(ch_temp);
				fscanf(file,"%s", ch_temp);
				j = atoi(ch_temp);
				fscanf(file,"%s", ch_temp);
				insertListe(&g->l_adj[i], newCellule(j));
				insertListe(&g->l_adj[j], newCellule(i));
				g->m_adj[i][j] = 1;
			}
		}
		else {
			while (ch_temp[0] != 'F') {
				i = atoi(ch_temp);
				fscanf(file,"%s", ch_temp);
				j = atoi(ch_temp);
				fscanf(file,"%s", ch_temp);
				insertListe(&g->l_adj[i], newCellule(j));
				g->m_adj[i][j] = 1;
			}
		}
	}
	else {
		fprintf(stderr,"\nFichier introuvable");
	}
}
/**
typedef struct graphe_t {
	int n_sommets,
		oriente,
		value;
	Liste* l_adj;
	int* m_stockage;
	int** m_adj;
} Graphe;
**/
void printGraphe(Graphe g) {
	fprintf(stderr,"\nNombre de sommets : %d", g.n_sommets);
	fprintf(stderr,"\nEst-orienté : %s", g.oriente ? "oui":"non");
	fprintf(stderr,"\nValeur du graphe : %d", g.value);
	fprintf(stderr,"\nListe des adjacences :");
	int i;
	CELLULE c;
	for (i = 0; i < g.n_sommets; i++) {
		fprintf(stderr,"\n%d : ", i);
		printListe(g.l_adj[i]);
	}

}

