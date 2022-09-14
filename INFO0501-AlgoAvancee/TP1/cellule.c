
#include "cellule.h"
#include <stdlib.h>

CELLULE initCellule() {
	CELLULE c = (CELLULE)malloc(sizeof(Cellule));
	c->prev = c->next = c->value = NULL;
	return c;
}

CELLULE newCellule(int x) {
	CELLULE c = (CELLULE)malloc(sizeof(Cellule));
	c->value = x;
	c->prev = c->next = NULL;
	return c;
}


