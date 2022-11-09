
#ifndef __TableHachage_h__
#define __TableHachage_h__

#include "liste.h"

typedef struct table_hachage {
	Liste* listes;
	int size;
} TableHachage;

TableHachage initTableHachage(int size);
void printTableHachage(TableHachage l);
void destroyTableHachage(TableHachage *l);

unsigned long long stringToLongLong(char* c);


/**
 * void insertTableHachage(TableHachage *t, Cellule* c);
 * 
insérer-hachage-chainée(t, x):
	insérer x en tête de la liste t[h(x.cle)]

rechercher-hachage-chainée(t, k):
	rechercher un élément de clé k dans la liste t[h(k)]

supprimer-hachage-chainée(t, x):
	supprimer x de la liste t[h(x.cle)]
**/

#endif

