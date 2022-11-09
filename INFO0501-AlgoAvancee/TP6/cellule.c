
#include "cellule.h"

Cellule* initCellule() {
	Cellule* c = (Cellule*)malloc(sizeof(Cellule));
	c->prev = c->next = NULL;
	c->word = NULL;
	return c;
}

Cellule* newCellule(char* w) {
	Cellule* c = (Cellule*)malloc(sizeof(Cellule));
	c->prev = c->next = NULL;
	c->word = (char*)malloc(sizeof(char) * WORDLENGTH);
	strcpy(c->word, w);
	return c;
}

