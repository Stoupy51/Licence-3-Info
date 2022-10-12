
#include "ensemble.h"

/**
 *  Ensembles disjoints

composantes-connexes(G)
	Pour chaque sommet V appartenant à G.sommets
		créer-ensemble(V)
	Pour chaque arete (u,v) appartenant à G.aretes
		Si trouver-ensemble(u) != trouver-ensemble(v)
			union(u,v) // unie les ensembles de u et v

meme-composante(u,v)
	return trouver-ensemble(u) == trouver-ensemble(v)

crée-ensemble(x)
	créer une nouvelle liste chainée dont l'objet unique est x

trouver-ensemble(x)
	return x.ensemble.tete

union(x,y)
	x.ensemble.queue.succ = y.ensemble.tete
	x.ensemble.queue = y.ensemble.queue
	pour chaque objet z faisant partie de l'ensemble de y
		z.ensemble = x.ensemble

*/

Ensemble createEnsemble(int x) {
	Ensemble e;
	Element* l = (Element*)malloc(sizeof(Element));
	l->s = x;
	e.head = e.tail = &(*l);
	return e;
}

Ensemble* trouverEnsemble(Element x) {
	return x.ensemble;
}

void unionEnsemble(Element* x, Element* y) {
	x->ensemble->tail->next = y->ensemble->head;
	x->ensemble->tail = y->ensemble->tail;
	Element* z = y->next;
	while (z != (Element*)NULL) {
		z->ensemble = x->ensemble;
		z = z->next;
	}
}


