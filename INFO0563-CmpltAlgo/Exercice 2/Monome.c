
#include "Monome.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * Permet de vérifier si la Monome est null
**/
int isNull(MONOME m) {
	return m == (MONOME)NULL;
}

/**
 * Renvoie un Monome initialisé à null
**/
MONOME init() {
	return (MONOME)NULL;
}

/**
 * Créer un Monome suivant les paramètres donnés
**/
MONOME create(unsigned int d, double c) {
	MONOME m = (MONOME)malloc(sizeof(Monome));
	m->d = d;
	m->c = c;
	m->m = init();
	return m;
}

/**
 * Renvoie la tête du Monome et "s'approndit" dans la chaîne
**/
MONOME head(MONOME *m) {
	MONOME head = (*m);
	(*m) = (*m)->m;
	return head;
}

/**
 * Supprime un Monome dans la chaîne du Polygone
**/
void delete(MONOME *m, unsigned int d) {
	MONOME next;
	for (next = (*m); !isNull(next) && next->m->d != d; next = next->m);
	if (next->m->d == d) {
		MONOME ex = next->m;
		next->m = ex->m;
		free(ex);
	}
	else
		fprintf(stderr,"\nAucun Monome de degre %d a ete trouve",d);
}


/**
 * Ajoute un Monome dans le Polygone
**/
void add(MONOME *m, MONOME a) {
	if (isNull(*m)) {
		(*m) = a;
		return;
	}
	MONOME t = head(m);
	// Si le degré de a est supérieur eu degré de d,
	// alors insérer dans la chaîne tout en inversant
	if (a->d > (*m)->d) {
		a->m = t;
		(*m)->m = a;
	}
	// Sinon
	else {
		// Si le degré de a est == au degré de la tête,
		// alors augmenter le coefficient et supprimer
		// la tête si son coefficient est égale à 0
		if (a->d == t->d) {
			if (!(t->c += a->c)) {
				delete(m, t->d);
				return;
			}
		}
		(*m) = t;
	}
}

/**
 * Affiche l'entièreté du Polynome
**/
void printPolynome(POLYNOME p) {
	fprintf(stderr,"\nPolygone : ");
	fprintf(stderr,"%fx^%d",p->c,p->d);
	MONOME next;
	for (next = p->m; !isNull(next); next = next->m)
		fprintf(stderr,", %fx^%d",next->c,next->d);
}






