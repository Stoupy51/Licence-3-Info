
#ifndef __pile_h__
#define __pile_h__

#include "noeud.h"

typedef struct pile {
	Noeud** data;
	int head,
		size;
} Pile;

Pile initPile(int size);
void destroyPile(Pile p);
int isPileEmpty(Pile p);
int isPileFull(Pile p);
void empilerPile(Pile* p, Noeud* n);
Noeud* depilerPile(Pile* p);
void printPile(Pile p);

#endif

