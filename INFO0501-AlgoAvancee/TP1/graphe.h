
#ifndef __Graphe_h__
#define __Graphe_h__

#include "liste.h"

typedef struct graphe_t {
	int n_sommets,
		oriente,
		value;
	Liste* l_adj;
	int* m_stockage;
	int** m_adj;
} Graphe;

void initGraphe(Graphe* g, char* fileName);
void printGraphe(Graphe g);


#endif

