
#include "table_hachage.h"

// Par exemple, "Abc" → 65 * 128^2 + 98 * 128^1 + 99 * 128^0 = 1 064 960 + 12 544 + 99 = 1 077 603.
unsigned long long stringToLongLong(char* c) {
	unsigned long long value = 0;
	int i, j, temp;
	int size = strlen(c);
	for (i = 0; i < size; i++) {
		temp = (int)c[i];
		for (j = i + 1; j < size; j++)
			temp *= 128;
		value += temp;
	}
	return value;
}

TableHachage initTableHachage(int size) {
	TableHachage table;
	table.listes = (Liste*)malloc(sizeof(Liste) * size);
	table.size = size;
	for (size--; size >= 0; size--)
		table.listes[size] = initListe();
	return table;
}

void printTableHachage(TableHachage l) {
	if (l.size == 0)
		fprintf(stderr,"\n[]");
	else {
		fprintf(stderr,"\n[");
		int i;
		for (i = 0; i < l.size; i++) {
			fprintf(stderr,"\n   ");
			printListe(l.listes[i]);
		}
		fprintf(stderr,"\n]");
	}

}

void destroyTableHachage(TableHachage *l) {
	int i;
	for (i = 0; i < l->size; i++)
		destroyListe(&l->listes[i]);
	free(l->listes);
	l->size = 0;
}

int hachage(unsigned long long k, int size) {
	return k % size;
}

void insertTableHachage(TableHachage *t, Cellule* c) {
	insertListe(&t->listes[ hachage(stringToLongLong(c->word),t->size) ], c);
}

Cellule* searchInTableHachage(TableHachage t, char* word) {
	return searchInListe(t.listes[ hachage(stringToLongLong(word), t.size) ], word);
}

void deleteFromTableHachage(TableHachage *t, Cellule* c) {
	deleteFromListe(&t->listes[ hachage(stringToLongLong(c->word), t->size) ], c);
}

int wordsInTableHachage(TableHachage t) {
	int i, count = 0;
	for (i = 0; i < t.size; i++)
		count += t.listes[i].size;
	return count;
}

