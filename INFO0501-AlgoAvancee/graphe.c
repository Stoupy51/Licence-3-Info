
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
				g->m_adj[i][j] = g->m_adj[j][i] = 1;
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
		fprintf(stderr,"\n@@@ Fichier introuvable @@@\n");
	}
}

void printGraphe(Graphe g) {
	fprintf(stderr,"\n<------ Graphe ------>");
	fprintf(stderr,"\nNombre de sommets : %d", g.n_sommets);
	fprintf(stderr,"\nEst-orienté : %s", g.oriente ? "Oui":"Non");
	fprintf(stderr,"\nValeur du graphe : %d", g.value);
	int i, j;
	if (g.n_sommets == 0) {
		fprintf(stderr,"\nGraphe vide\n");
		return;
	}

	// Affichage Liste des adjacences
	fprintf(stderr,"\nListe des adjacences :");
	for (i = 0; i < g.n_sommets; i++) {
		fprintf(stderr,i < 10 ? "\n%d  -> ":"\n%d -> ", i);
		printListe(g.l_adj[i]);
	}

	// Affichage Matrice d'adjacences
	fprintf(stderr,"\n\nMatrice d'adjacences :\n\nx ");
	for (i = 0; i < g.n_sommets; i++)
		fprintf(stderr,i < 10 ? "  %d":" %d", i);
	fprintf(stderr,"\n");
	for (i = 0; i < g.n_sommets; i++) {
		fprintf(stderr,i < 10 ? "\n%d ":"\n%d", i);
		for (j = 0; j < g.n_sommets; j++)
			fprintf(stderr,"  %d", g.m_adj[i][j]);
	}
	fprintf(stderr,"\n");
}

void destroyGraphe(Graphe* g) {
	int i;
	for (i = 0; i < g->n_sommets; i++)
		destroyListe(&g->l_adj[i]);
	free(g->l_adj);
	free(g->m_stockage);
	free(g->m_adj);
	g->n_sommets = g->oriente = g->value = 0;
}


