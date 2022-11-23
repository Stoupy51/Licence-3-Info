
#include "noeud.h"

Noeud* initNoeud(char* w) {
	Noeud* n = (Noeud*)malloc(sizeof(Noeud));
	n->pere = n->gauche = n->droite = NULL;
	n->word = (char*)malloc(sizeof(char) * WORDLENGTH);
	strcpy(n->word, w);
	return n;
}

void freeNoeud(Noeud* n) {
	free(n->word);
	free(n);
}

void freeNoeudProfond(Noeud* n) {
	if (n == NULL)
		return;
	freeNoeudProfond(n->gauche);
	freeNoeudProfond(n->droite);
	free(n->word);
	free(n);
}

