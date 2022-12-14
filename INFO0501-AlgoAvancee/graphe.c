
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
				fscanf(file,"%d", &j);
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
				fscanf(file,"%d", &j);
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

		g->n_aretes = 0;
		// Si la liste n'est pas orientée
		if (!g->oriente) {
			while (ch_temp[0] != 'F') {
				i = atoi(ch_temp);
				fscanf(file,"%d", &j);
				fscanf(file,"%d", &p);
				fscanf(file,"%s", ch_temp);
				insertListe(&g->l_adj[i], newCelluleAvecPoids(j, p));
				insertListe(&g->l_adj[j], newCelluleAvecPoids(i, p));
				g->m_adj[i][j] = g->m_adj[j][i] = 1;
				g->m_poids[i][j] = g->m_poids[j][i] = p;
				g->n_aretes += 2;
			}
		}
		// Si elle est orientée
		else {
			while (ch_temp[0] != 'F') {
				i = atoi(ch_temp);
				fscanf(file,"%d", &j);
				fscanf(file,"%d", &p);
				fscanf(file,"%s", ch_temp);
				insertListe(&g->l_adj[i], newCelluleAvecPoids(j, p));
				g->m_poids[i][j] = p;
				g->n_aretes++;
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

void destroyGraphe(Graphe g) {
	int i;
	for (i = 0; i < g.n_sommets; i++)
		destroyListe(&g.l_adj[i]);
	free(g.l_adj);
	free(g.m_stockage);
	free(g.m_adj);
	free(g.m_stockagePoids);
	free(g.m_poids);
	g.n_sommets = g.oriente = g.value = 0;
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
	int k = 0;
	for (i = 0; i < g.n_sommets; i++)
		for (j = 0; j < g.n_sommets; j++)
			if (g.m_adj[i][j])
				k++;
	Arete* aretes = (Arete*)malloc(sizeof(Arete) * k + 1);
	aretes[0] = newArete(0, 0, k);
	k = 1;
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

void printAretes(Arete* aretes) {
	int i = 1;
	fprintf(stderr, "\n[\n");
	for (; i <= aretes[0].poids; i++) {
		if (i%10 == 0)
			fprintf(stderr, "\n");
		fprintf(stderr, " | %d-%d (%d)", aretes[i].u, aretes[i].v, aretes[i].poids);
	}
	fprintf(stderr, "\n]\n");
}

void printPoidsAretes(Arete* aretes) {
	int i = 2;
	fprintf(stderr, "\n[%d",aretes[1].poids);
	for (; i <= aretes[0].poids; i++) {
		fprintf(stderr, ", %d", aretes[i].poids);
	}
	fprintf(stderr, "]\n");
}


void sortAretesInsertion(Arete* aretes) {
	fprintf(stderr, "\nSortAretesInsertion : %d aretes", aretes[0].poids);
	int i, j;
	Arete tmp;
	for (j = 2; j <= aretes[0].poids; j++) {
		tmp = aretes[j];
		i = j - 1;
		while (i > 0 && aretes[i].poids > tmp.poids) {
			aretes[i + 1] = aretes[i];
			i--;
		}
		aretes[i + 1] = tmp;
	}
}

void sortAretesTas(Arete* aretes) {
	Tas t = construireTasMax(aretes);
	int i;
	for (i = 1; i <= t.size; i++)
		aretes[i] = t.data[i];
	destroyTas(t);
}


Arete* acpm_kruskal_tableau(Graphe g) {
	Arete* A = getAretes(g);
	sortAretesInsertion(A);
	// Tableau des composantes connexes
	int* cc = (int*)malloc(sizeof(int) * g.n_sommets);
	int i, j, k, l, icc;
	for (i = 0; i < g.n_sommets; i++)
		cc[i] = i;
	
	// Ensembles d'aretes
	Arete* E = (Arete*)malloc(sizeof(Arete) * g.n_sommets + 1);

	// Pour toutes les aretes prise par ordre croissant,
	int u, v;
	j = 0;
	for (i = 1; i < k; i++) {
		u = A[i].u;
		v = A[i].v;
		// Si les deux sommets ne sont pas en composante connexes :
		if (cc[u] != cc[v]) {
			// Enregistrer l'arête de la connexion
			j++;
			E[j] = A[i];

			// Les connecter
			icc = cc[v];
			for (l = 0; l < g.n_sommets; l++)
				if (cc[l] == icc)
					cc[l] = cc[u];
		}
	}
	E[0].poids = j;
	return E;
}

Arete* acpm_prim_tableau(Graphe g, int r) {
	Arete* E = (Arete*)malloc(sizeof(Arete) * g.n_sommets + 1);
	int* distances = (int*)malloc(sizeof(int) * g.n_sommets);
	int* peres = (int*)malloc(sizeof(int) * g.n_sommets);
	char* couverts = (char*)malloc(sizeof(char) * g.n_sommets);

	int i;
	for (i = 0; i < g.n_sommets; i++) {
		distances[i] = MAX_INT;
		peres[i] = -1;
		couverts[i] = 1;
	}

	int u, j, min, k;
	Cellule* v;
	distances[r] = i = k = 0;
	for (; i < g.n_sommets; i++) {
		// u = minDistance(distances, couverts);
		min = MAX_INT;
		for (j = 0; j < g.n_sommets; j++) {
			if (couverts[j] && distances[j] < min) {
				u = j;
				min = distances[u];
			}
		}

		couverts[u] = 0;
		for (v = g.l_adj[u].head; v != (Cellule*)NULL; v = v->next) {
			if (couverts[v->value] && distances[v->value] > g.m_poids[u][v->value]) {
				peres[v->value] = u;
				distances[v->value] = g.m_poids[u][v->value];

				// On retient les arêtes pour l'affichage
				j = v->value + 1;
				E[j].u = u;
				E[j].v = v->value;
				E[j].poids = g.m_poids[u][v->value];
			}
		}
	}

	E[0].poids = g.n_sommets;
	return E;
}

void afficher_acpm(Arete* E) {
	printAretes(E);
	int i, j = 0;
	for (i = 1; i <= E[0].poids; i++)
		j += E[i].poids;
	fprintf(stderr, "Arbre couvrant de poids %d !\n", j);
}

// TP 7

void sourceUniqueInit(Graphe* g, int s) {
	int i = 0;
	for (; i < g->n_sommets; i++) {
		g->l_sommets[i].distance = MAX_INT;
		g->l_sommets[i].pere = -1;
	}
	g->l_sommets[s].distance = 0;
}

void relacher(Graphe* g, int u, int v) {
	long u_w = g->l_sommets[u].distance + g->m_poids[u][v];
	if (g->l_sommets[v].distance > u_w) {
		g->l_sommets[v].distance = u_w;
		g->l_sommets[v].pere = u;
	}
}

/**
Bellman-Ford(G, w, s):
	source-unique-initialisation(G, s)
	Pour i = 1 à (G.S - 1)
		Pour chaque arc (u,v) appartenant à G.A
			relacher(u,v,w)
	Pour chaque arc (u,v) appartenant à G.A
		Si v.d > u.d + w(u,v)
			return Faux
	return Vrai
*/
int bellmanFord(Graphe* g, int s) {
	sourceUniqueInit(g, s);
	int i = 0;
	int u;
	Cellule* c;
	for (; i < g->n_sommets; i++)
		for (u = 0; u < g->n_sommets; u++)
			for (c = g->l_adj[u].head; c != NULL; c = c->next)
				relacher(g, u, c->value);
	for (u = 0; u < g->n_sommets; u++)
		for (c = g->l_adj[u].head; c != NULL; c = c->next)
			if (g->l_sommets[c->value].distance > g->l_sommets[u].distance + g->m_poids[u][c->value])
				return 0;
	return 1;
}

int dijkstra(Graphe* g, int s) {
	sourceUniqueInit(g, s);
	int i, j, u, min;
	Cellule* v;
	char* couverts = (char*)malloc(sizeof(char) * g->n_sommets);
	for (i = 0; i < g->n_sommets; i++)
		couverts[i] = 0;

	for (i = 0; i < g->n_sommets; i++) {
		// u = minDistanceRestante
		// Mieux : file de priorité
		min = MAX_INT;
		for (j = 0; j < g->n_sommets; j++) {
			if (!couverts[j] && g->l_sommets[j].distance < min) {
				u = j;
				min = g->l_sommets[u].distance;
			}
		}
		couverts[u] = 1;

		// Relâcher chaque adjacent
		for (v = g->l_adj[u].head; v != NULL; v = v->next)
			relacher(g, u, v->value);
	}
	return 1;
}

