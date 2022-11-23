
#ifndef __arbre_h__
#define __arbre_h__

#include "noeud.h"
#include "pile.h"

typedef struct arbre {
	int size;
	Noeud* head;
} Arbre;

Arbre* initArbre();
void freeArbre(Arbre* a);
void insertArbre(Arbre* a, Noeud* z);
Noeud* searchInArbre(Arbre* a, char* w);
Noeud* minimumArbre(Noeud* n);
void transplanter(Arbre* a, Noeud* u, Noeud* v);
void deleteInArbre(Arbre* a, Noeud* n);
void printArbre(Arbre a);

#endif

