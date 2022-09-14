
#include "graphe.h"

void initGraphe(Graphe *g, char *fileName) {
	FILE *file;
	char ch_temp[20];
	if ((file = fopen(fileName, "r"))) {
		fscanf(file,"%s", ch_temp);
		fscanf(file,"%d", g->n_sommets);
		fscanf(file,"%s", ch_temp);
		fscanf(file,"%d", g->oriente);
		fscanf(file,"%s", ch_temp);
		fscanf(file,"%d", g->value);
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
			for (; ch_temp != "FIN_DEF_ARETES     "; fscanf(file,"%s", ch_temp)) {
				fscanf(file,"%d", i);
				fscanf(file,"%d", j);
				insertListe(&g->l_adj[i], j);
				insertListe(&g->l_adj[j], i);
				g->m_adj[i][j] = 1;
			}
		}

		fscanf(file,"%s", ch_temp);
		fscanf(file,"%s", ch_temp);
		fscanf(file,"%s", ch_temp);
		fscanf(file,"%s", ch_temp);
		fscanf(file,"%s", ch_temp);
		
	}
}

