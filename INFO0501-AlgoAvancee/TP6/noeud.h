
#ifndef __noeud_h__
#define __noeud_h__

#include "includes.h"

typedef struct noeud Noeud;
struct noeud {
	Noeud* pere;
	Noeud* gauche;
	Noeud* droite;
	char* word;
};

Noeud* initNoeud(char* w);
void freeNoeud(Noeud* n);
void freeNoeudProfond(Noeud* n);

#endif

