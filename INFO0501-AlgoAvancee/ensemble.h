
#ifndef __ensemble_h__
#define __ensemble_h__

#include "arete.h"

typedef struct element Element;
typedef struct ensemble Ensemble;
struct element {
	int s; // Sommet
	Element* next; // Prochain sommet
	Ensemble* ensemble; // Ensemble
};

struct ensemble {
	Element* head;
	Element* tail;
};

Ensemble createEnsemble(int x);
Ensemble* trouverEnsemble(Element x);
void unionEnsemble(Element* x, Element* y);

#endif

