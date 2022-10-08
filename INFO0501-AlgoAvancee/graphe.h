
#ifndef __Graphe_h__
#define __Graphe_h__

#include "liste.h"
#include "queue.h"
#include "pile.h"
#include "arete.h"
#include "tas.h"

typedef struct graphe_t {
	int n_sommets,
		oriente,
		value;
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


#endif

