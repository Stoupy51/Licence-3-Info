
#include "table_hachage.h"

TableHachage initTableHachage(int size) {
	TableHachage table;
	table.listes = (Liste*)malloc(sizeof(Liste) * size);
	table.size = size;
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
}






