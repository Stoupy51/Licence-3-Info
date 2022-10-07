
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

		// Allocations mémoire pour la matrice et la liste d'adjacences, ainsi que la liste des sommets
		g->m_stockage = (int*)malloc(sizeof(int)*g->n_sommets*g->n_sommets);
		g->m_adj = (int**)malloc(sizeof(int*)*g->n_sommets);
		g->l_adj = (Liste*)malloc(sizeof(Liste)*g->n_sommets);
		g->l_sommets = (Sommet*)malloc(sizeof(Sommet)*g->n_sommets);

		// Initialisation de la matrice des adjacences, de la liste des adjacences, et la liste des sommets
		int i, j;
		for (i = 0; i < g->n_sommets; i++) {
			g->m_adj[i] = &g->m_stockage[i*g->n_sommets];
			for (j = 0; j < g->n_sommets; j++)
				g->m_stockage[i*j] = 0;
			g->l_adj[i] = initListe();
			g->l_sommets[i] = initSommet(i);
		}

		// Si la liste n'est pas orientée
		if (!g->oriente) {
			while (ch_temp[0] != 'F') {
				i = atoi(ch_temp);
				fscanf(file,"%d", j);
				fscanf(file,"%s", ch_temp);
				insertListe(&g->l_adj[i], newCellule(j));
				insertListe(&g->l_adj[j], newCellule(i));
				g->m_adj[i][j] = g->m_adj[j][i] = 1;
			}
		}
		// Si elle est orientée
		else {
			while (ch_temp[0] != 'F') {
				i = atoi(ch_temp);
				fscanf(file,"%d", j);
				fscanf(file,"%s", ch_temp);
				insertListe(&g->l_adj[i], newCellule(j));
				g->m_adj[i][j] = 1;
			}
		}
	}
	else {
		fprintf(stderr,"\n!!!!! Fichier introuvable !!!!!\n");
	}
}

void initGrapheAvecPoids(Graphe* g, char* fileName) {
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

		// Allocations mémoire pour la matrice et la liste d'adjacences, ainsi que la liste des sommets
		g->m_stockage = (int*)malloc(sizeof(int)*g->n_sommets*g->n_sommets);
		g->m_adj = (int**)malloc(sizeof(int*)*g->n_sommets);
		g->m_stockagePoids = (int*)malloc(sizeof(int)*g->n_sommets*g->n_sommets);
		g->m_poids = (int**)malloc(sizeof(int*)*g->n_sommets);
		g->l_adj = (Liste*)malloc(sizeof(Liste)*g->n_sommets);
		g->l_sommets = (Sommet*)malloc(sizeof(Sommet)*g->n_sommets);

		// Initialisation de la matrice des adjacences, de la liste des adjacences, et la liste des sommets
		int i, j, p;
		for (i = 0; i < g->n_sommets; i++) {
			g->m_adj[i] = &g->m_stockage[i*g->n_sommets];
			g->m_poids[i] = &g->m_stockagePoids[i*g->n_sommets];
			for (j = 0; j < g->n_sommets; j++) {
				g->m_stockage[i*j] = 0;
				g->m_stockagePoids[i*j] = 0;
			}
			g->l_adj[i] = initListe();
			g->l_sommets[i] = initSommet(i);
		}

		// Si la liste n'est pas orientée
		if (!g->oriente) {
			while (ch_temp[0] != 'F') {
				i = atoi(ch_temp);
				fscanf(file,"%d", j);
				fscanf(file,"%d", p);
				fscanf(file,"%s", ch_temp);
				insertListe(&g->l_adj[i], newCelluleAvecPoids(j, p));
				insertListe(&g->l_adj[j], newCelluleAvecPoids(i, p));
				g->m_adj[i][j] = g->m_adj[j][i] = 1;
				g->m_poids[i][j] = g->m_poids[j][i] = p;
			}
		}
		// Si elle est orientée
		else {
			while (ch_temp[0] != 'F') {
				i = atoi(ch_temp);
				fscanf(file,"%d", j);
				fscanf(file,"%d", p);
				fscanf(file,"%s", ch_temp);
				insertListe(&g->l_adj[i], newCelluleAvecPoids(j, p));
				g->m_poids[i][j] = p;
			}
		}
	}
	else {
		fprintf(stderr,"\n!!!!! Fichier introuvable !!!!!\n");
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
	free(g->m_stockagePoids);
	free(g->m_poids);
	g->n_sommets = g->oriente = g->value = 0;
}

void parcoursLargeur(Graphe* g, int r) {
	int v = 0;
	for (; v < g->n_sommets; v++) {
		g->l_sommets[v].color = WHITE;
		g->l_sommets[v].distance = MAX_INT;
		g->l_sommets[v].pere = -1;
	}
	g->l_sommets[r].color = GRAY;
	g->l_sommets[r].distance = 0;
	Queue q = initQueue(g->n_sommets);
	enfilerQueue(&q, r);
	int u;
	while (!isQueueEmpty(q)) {
		u = defilerQueue(&q);
		for (v = g->n_sommets - 1; v >= 0; v--) {
			if (g->m_adj[u][v] && g->l_sommets[v].color == WHITE) {
				//fprintf(stderr,"\n (u,v) = (%d,%d)",u,v);
				g->l_sommets[v].color = GRAY;
				g->l_sommets[v].distance = g->l_sommets[u].distance + 1;
				g->l_sommets[v].pere = u;
				enfilerQueue(&q, v);
			}
		}
		g->l_sommets[u].color = BLACK;
	}
}

void afficherChemin(Graphe g, int r, int v) {
	if (v == r)
		fprintf(stderr, "\n%d", v);
	else {
		if (g.l_sommets[v].pere == -1)
			fprintf(stderr, "\nIl n'existe pas de chemin de %d à %d", r, v);
		else {
			afficherChemin(g, r, g.l_sommets[v].pere);
			fprintf(stderr, " <-- %d", v);
		}
	}
}

void parcoursProfondeurRecursif(Graphe* g) {
	int u = 0;
	for (; u < g->n_sommets; u++) {
		g->l_sommets[u].color = WHITE;
		g->l_sommets[u].pere = -1;
	}
	int date = 0;
	int maxDate = 2*g->n_sommets;
	for (u = 0; u < g->n_sommets; u++) {
		if (g->l_sommets[u].color == WHITE)
			visiterVoisin(g, u, &date);
		if (date == maxDate)
			return;
	}
}

void visiterVoisin(Graphe* g, int u, int* date) {
	fprintf(stderr, "\nVisiterVoisin(%d)",u);
	(*date)++;
	g->l_sommets[u].d = (*date);
	g->l_sommets[u].color = GRAY;
	int v = g->n_sommets - 1;
	for (; v >= 0; v--)
		if (g->m_adj[u][v] && g->l_sommets[v].color == WHITE) {
			g->l_sommets[v].pere = u;
			visiterVoisin(g, v, date);
		}
	(*date)++;
	g->l_sommets[u].f = (*date);
	g->l_sommets[u].color = BLACK;
}

void afficherParcoursProfondeur(Graphe g) {
	int u = 0;
	for (; u < g.n_sommets; u++) {
		fprintf(stderr,
			"\nSommet : %d, Date debut : %d, Date fin : %d, Pere : %d",
			u,
			g.l_sommets[u].d,
			g.l_sommets[u].f,
			g.l_sommets[u].pere
		);
	}
}

void parcoursProfondeurIteratif(Graphe* g) {
	//Invalide pour le moment

	/**
	int v = 0;
	for (; v < g->n_sommets; v++) {
		g->l_sommets[v].color = WHITE;
		g->l_sommets[v].distance = MAX_INT;
		g->l_sommets[v].pere = g->l_sommets[v].f = -1;
	}
	g->l_sommets[0].color = GRAY;
	g->l_sommets[0].distance = 0;
	g->l_sommets[0].d = 0;
	Pile p = initPile(g->n_sommets);
	empilerPile(&p, 0);
	int u;
	int date = 0;
	while (!isPileEmpty(p)) {
		u = depilerPile(&p);
		for (v = g->n_sommets - 1; v >= 0; v--) {
			if (g->m_adj[u][v] && g->l_sommets[v].color == WHITE) {
				g->l_sommets[v].color = GRAY;
				g->l_sommets[v].distance = g->l_sommets[u].distance + 1;
				g->l_sommets[v].pere = u;
				g->l_sommets[v].d = date++;
				g->l_sommets[v].f = -1;
				empilerPile(&p, v);
			}
		}
		g->l_sommets[u].color = BLACK;
	}
	**/
}

Arete* getAretes(Graphe g) {
	int i, j;
	int k = 1;
	for (i = 0; i < g.n_sommets; i++)
		for (j = 0; j < g.n_sommets; j++)
			if (g.m_adj[i][j])
				k++;
	Arete* aretes = (Arete*)malloc(sizeof(Arete) * k);
	k = 0;
	for (i = 0; i < g.n_sommets; i++) {
		for (j = 0; j < g.n_sommets; j++) {
			if (g.m_adj[i][j]) {
				aretes[k] = newArete(i, j, g.m_poids[i][j]);
				k++;
			}
		}
	}
	return aretes;
}

