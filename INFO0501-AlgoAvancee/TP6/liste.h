
#ifndef __Liste_h__
#define __Liste_h__

#include "cellule.h"

typedef struct liste_t {
	Cellule* head;
	int size;
} Liste;

Liste initListe();
void insertListe(Liste *l, Cellule* c);
void printListe(Liste l);
Cellule* searchInListe(Liste l, char* word);
void deleteFromListe(Liste *l, Cellule* c);
void destroyListe(Liste *l);

#endif

