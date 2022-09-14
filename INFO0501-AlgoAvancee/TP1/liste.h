
#ifndef __Liste_h__
#define __Liste_h__

#include "cellule.h"

typedef struct liste_t {
	CELLULE head;
	int size;
} Liste;

Liste initListe();
void insertListe(Liste *l, CELLULE c);
void printListe(Liste l);
CELLULE searchInListe(Liste l, int k);
void deleteFromListe(Liste *l, CELLULE *c);
void destroyListe(Liste *l);

#endif
