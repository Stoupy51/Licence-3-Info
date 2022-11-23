
#include "arbre.h"

Arbre* initArbre() {
	Arbre* a = (Arbre*)malloc(sizeof(Arbre));
	a->size = 0;
	a->head = NULL;
	return a;
}

void freeArbre(Arbre* a) {
	freeNoeudProfond(a->head);
	a->size = 0;
}

void insertArbre(Arbre* a, Noeud* z) {
	Noeud* pn = NULL;
	Noeud* n = a->head;
	int cmp;
	while (n != NULL) {
		cmp = strcmp(n->word, z->word);
		pn = n;
		if (cmp < 0)
			n = n->gauche;
		else
			n = n->droite;
	}

	z->pere = pn;
	if (pn == NULL)
		a->head = z;
	else {
		if (cmp < 0)
			pn->gauche = z;
		else
			pn->droite = z;
	}
}

Noeud* searchInArbre(Arbre* a, char* w) {
	Noeud* n = a->head;
	int cmp;
	while (n != NULL) {
		cmp = strcmp(w, n->word);
		if (cmp < 0)
			n = n->gauche;
		else if (cmp > 0)
			n = n->droite;
		else
			return n;
	}
}

Noeud* minimumArbre(Noeud* n) {
	while (n->gauche != NULL)
		n = n->gauche;
	return n;
}

void transplanter(Arbre* a, Noeud* u, Noeud* v) {
	if (a->head == u)
		a->head = v;
	else {
		if (u == u->pere->gauche)
			u->pere->gauche = v;
		else
			u->pere->droite = v;
	}
	if (v != NULL)
		v->pere = u->pere;
}

void deleteInArbre(Arbre* a, Noeud* n) {
	if (n->gauche == NULL)
		transplanter(a, n, n->droite);
	else {
		if (n->droite == NULL)
			transplanter(a, n, n->gauche);
		else {
			Noeud* y = minimum_arbre(n->droite);
			if (y->pere != n) {
				transplanter(a, y, y->droite);
				y->droite = n->droite;
				y->droite->pere = y;
			}
			transplanter(a, n, y);
			y->gauche = n->gauche;
			y->gauche->pere = y;
		}
	}
}

void printArbre(Arbre a) {
	fprintf(stderr, "\nArbre de taille : %d", a.size);
	if (a.head != NULL) {
		Pile p = initPile(a.size);
		empilerPile(&p, a.head);
		Noeud* x;
		fprintf(stderr, "\n[");
		while (!isPileEmpty(p)) {
			x = depilerPile(&p);
			fprintf(stderr, "%s, ", x->word);
			if (x->droite != NULL)
				empilerPile(&p, x->droite);
			if (x->gauche != NULL)
				empilerPile(&p, x->gauche);
		}
		fprintf(stderr, "\n]");
	}
}

