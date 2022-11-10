
#ifndef __TableHachage_h__
#define __TableHachage_h__

#include "liste.h"

typedef struct table_hachage {
	Liste* listes;
	int size;
} TableHachage;

unsigned long long stringToLongLong(char* c);

TableHachage initTableHachage(int size);
void printTableHachage(TableHachage l);
void destroyTableHachage(TableHachage *l);
int hachage(unsigned long long k, int size);

void insertTableHachage(TableHachage *t, Cellule* c);
Cellule* searchInTableHachage(TableHachage t, char* word);
void deleteFromTableHachage(TableHachage *t, Cellule* c);

int wordsInTableHachage(TableHachage t);

/**
insérer-hachage-chainée(t, x):
	insérer x en tête de la liste t[h(x.cle)]

rechercher-hachage-chainée(t, x):
	rechercher un élément de clé k dans la liste t[h(k)]

supprimer-hachage-chainée(t, x):
	supprimer x de la liste t[h(x.cle)]
**/

#endif

