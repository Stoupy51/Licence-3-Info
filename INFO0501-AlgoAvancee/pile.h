
#ifndef __pile_h__
#define __pile_h__

#include "sommet.h"

typedef struct pile {
	int* data;
	int head,
		size;
} Pile;

Pile initPile(int size);
void destroyPile(Pile p);
int isPileEmpty(Pile p);
int isPileFull(Pile p);
int sommet(Pile* p);
void empilerPile(Pile* p, int s);
int depilerPile(Pile* p);
void printPile(Pile p);

#endif

