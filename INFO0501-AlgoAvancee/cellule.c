
#include "cellule.h"

CELLULE initCellule() {
	CELLULE c = (CELLULE)malloc(sizeof(Cellule));
	c->prev = c->next = NULL;
	c->value = 0;
	return c;
}

CELLULE newCellule(int x) {
	CELLULE c = (CELLULE)malloc(sizeof(Cellule));
	c->prev = c->next = NULL;
	c->value = x;
	return c;
}


