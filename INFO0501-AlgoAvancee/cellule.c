
#include "cellule.h"

CELLULE initCellule() {
	CELLULE c = (CELLULE)malloc(sizeof(Cellule));
	c->prev = c->next = NULL;
	c->value = c->poids = 0;
	return c;
}

CELLULE newCellule(int v) {
	CELLULE c = (CELLULE)malloc(sizeof(Cellule));
	c->prev = c->next = NULL;
	c->value = v;
	return c;
}

CELLULE newCelluleAvecPoids(int v, int p) {
	CELLULE c = (CELLULE)malloc(sizeof(Cellule));
	c->prev = c->next = NULL;
	c->value = v;
	c->poids = p;
	return c;
}


