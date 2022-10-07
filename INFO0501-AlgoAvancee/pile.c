
#include "pile.h"

Pile initPile(int size) {
	Pile p;
	p.size = size;
	p.head = 0;
	p.data = (int*)malloc(sizeof(int) * p.size);
	return p;
}

void destroyPile(Pile p) {
	free(p.data);
	p.size = 0;
}

int isPileEmpty(Pile p) {
	return !p.head;
}

int isPileFull(Pile p) {
	return (p.head == p.size);
}

void empilerPile(Pile* p, int s) {
	if (isPileFull(*p)) {
		fprintf(stderr,"\nErreur : La pile est pleine");
		return;
	}
	p->data[p->head] = s;
	p->head++;
}

int sommet(Pile* p) {
	return p->data[p->head];
}

int depilerPile(Pile* p) {
	if (isPileEmpty(*p)) {
		fprintf(stderr,"\nErreur : La pile est vide");
		return -1;
	}
	p->head--;
	return p->data[p->head];
}

void printPile(Pile p) {
	fprintf(stderr,"\nPile : ");
	if (isPileEmpty(p)) {
		fprintf(stderr,"Vide");
		return;
	}
	fprintf(stderr,"[");
	fprintf(stderr,"%d", p.data[0]);
	int i = 1;
	for (; i < p.size; i++)
		fprintf(stderr,", %d", p.data[i]);
	fprintf(stderr,"]\n");
}



