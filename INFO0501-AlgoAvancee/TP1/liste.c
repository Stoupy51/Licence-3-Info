
#include "liste.h"

Liste initListe() {
	Liste l;
	l.head = NULL;
	l.size = 0;
	return l;
}

void insertListe(Liste *l, CELLULE c) {
	c->next = l->head;
	if (l->head != NULL)
		l->head->prev = c;
	l->head = c;
	c->prev = NULL;
	l->size++;
}

void printListe(Liste l) {
	if (l.size == 0)
		fprintf(stderr,"Liste vide");
	else {
		CELLULE c = l.head;
		fprintf(stderr,"[%d",c->value);
		for (c = c->next; c != NULL; c = c->next) {
			fprintf(stderr,", %d",c->value);
		}
		fprintf(stderr,"]");
	}
}

CELLULE searchInListe(Liste l, int k) {
	CELLULE c = l.head;
	for (; c != NULL && c->value != k; c = c->next);
	return c;
}

void deleteFromListe(Liste *l, CELLULE *c) {
	if (*c == NULL)
		return;
	if (l->head == *c)
		l->head = (*c)->next;
	else
		(*c)->prev->next = (*c)->next;
	if ((*c)->next != NULL)
		(*c)->next->prev = (*c)->prev;
	l->size--;
	// Libération de la mémoire
	free((*c));
	(*c) = NULL;
}

void destroyListe(Liste *l) {
	CELLULE x;
	while (l->head != NULL) {
		x = l->head;
		l->head = l->head->next;
		free(x);
	}
	l->size = 0;
}


