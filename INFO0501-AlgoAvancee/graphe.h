
#ifndef __Graphe_h__
#define __Graphe_h__

#include "liste.h"
#include "queue.h"

typedef struct graphe_t {
	int n_sommets,
		oriente,
		value;
	Liste* l_adj;
	Sommet* l_sommets;
	int* m_stockage;
	int** m_adj;
} Graphe;

void initGraphe(Graphe* g, char* fileName);
void printGraphe(Graphe g);
void destroyGraphe(Graphe* g);


#endif

