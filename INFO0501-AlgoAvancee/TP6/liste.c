
#include "liste.h"

Liste initListe() {
	Liste l;
	l.head = NULL;
	l.size = 0;
	return l;
}

void insertListe(Liste *l, Cellule* c) {
	c->next = l->head;
	if (l->head != NULL)
		l->head->prev = c;
	l->head = c;
	c->prev = NULL;
	l->size++;
}

void printListe(Liste l) {
	if (l.size == 0)
		fprintf(stderr,"[]");
	else {
		Cellule* c = l.head;
		fprintf(stderr,"[%s",c->word);
		for (c = c->next; c != NULL; c = c->next) {
			fprintf(stderr,", %s",c->word);
		}
		fprintf(stderr,"]");
	}
}

Cellule* searchInListe(Liste l, char* word) {
	Cellule* c = l.head;
	for (; c != NULL && strcmp(c->word, word) != 0; c = c->next);
	return c;
}

void deleteFromListe(Liste *l, Cellule* c) {
	if (c == NULL)
		return;
	if (l->head == c)
		l->head = c->next;
	else
		c->prev->next = c->next;
	if (c->next != NULL)
		c->next->prev = c->prev;
	l->size--;
	
	// Libération de la mémoire
	free(c);
}

void destroyListe(Liste *l) {
	Cellule* c;
	while (l->head != NULL) {
		c = l->head;
		l->head = l->head->next;
		free(c);
	}
	l->size = 0;
}


