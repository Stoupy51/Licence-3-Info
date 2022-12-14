
#ifndef __Graphe_h__
#define __Graphe_h__

#include "liste.h"
#include "queue.h"
#include "pile.h"
#include "arete.h"
#include "tas.h"
#include "file_priorites_min.h"

typedef struct graphe_t {
	int n_sommets,
		oriente,
		value,
		n_aretes;
	Liste* l_adj;
	Sommet* l_sommets;
	int* m_stockage;
	int** m_adj;
	// Poids pour les arêtes
	int* m_stockagePoids;
	int** m_poids;
} Graphe;

void initGraphe(Graphe* g, char* fileName);
void initGrapheAvecPoids(Graphe* g, char* fileName);
void printGraphe(Graphe g);
void destroyGraphe(Graphe g);

void parcoursLargeur(Graphe* g, int r);
void afficherChemin(Graphe g, int r, int v);

void parcoursProfondeurRecursif(Graphe* g);
void visiterVoisin(Graphe* g, int u, int* date);
void afficherParcoursProfondeur(Graphe g);

void parcoursProfondeurIteratif(Graphe* g);

Arete* getAretes(Graphe g);
void printAretes(Arete* aretes);
void printPoidsAretes(Arete* aretes);
void sortAretesInsertion(Arete* aretes);
void sortAretesTas(Arete* aretes);

Arete* acpm_kruskal_tableau(Graphe g);
Arete* acpm_prim_tableau(Graphe g, int r);
void afficher_acpm(Arete* E);

// TP 7
void sourceUniqueInit(Graphe* g, int s);
void relacher(Graphe* g, int u, int v);
int bellmanFord(Graphe* g, int s);
int dijkstra(Graphe* g, int s);

#endif

