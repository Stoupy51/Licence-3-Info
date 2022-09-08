
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
 * Renvoie une copie detachée du Monome
**/
MONOME copy(MONOME m) {
	return create(m->d,m->c);
}

/**
 * Supprime un Monome dans la chaîne du Polynome
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
		fprintf(stderr,"\nAucun Monome de degre %d a ete trouve.",d);
}

/**
 * Supprime un Monome dans la chaîne du Polynome de manière récursive
**/
void deleteRecursif(MONOME *m, unsigned int d) {
	if (isNull(*m)) {
		fprintf(stderr,"\nAucun Monome de degre %d a ete trouve.",d);
		return;
	}
	if (d == (*m)->d) {
		MONOME ex = (*m);
		(*m) = (*m)->m;
		free(ex);
		return;
	}
	if (d < (*m)->d)
		deleteRecursif(&(*m)->m, d);
}


/**
 * Ajoute un Monome dans le Polynome de manière récursive
**/
void add(MONOME *m, MONOME a) {
	if (isNull(*m)) {
		(*m) = a;
		return;
	}
	// Si le degré de a est supérieur au degré de m,
	// alors insérer dans la chaîne tout en inversant
	if (a->d > (*m)->d) {
		a->m = (*m);
		(*m) = a;
		return;
	}
	// Sinon
	// Si le degré de a est == au degré de la tête,
	// alors augmenter le coefficient et supprimer
	// la tête si son coefficient est égale à 0
	if ((*m)->d == a->d) {
		if (!((*m)->c += a->c)) {
			delete(m, (*m)->d);
			return;
		}
	}
	// Sinon, si le degré est inférieur,
	// chercher une place dans la chaîne -- TODO
	else
		add(&(*m)->m, a);
}

/**
 * Ajoute un Polynome dans le premier Polynome passé en paramètre
**/
void fusion(POLYNOME *p, POLYNOME a) {
	MONOME next;
	for (next = a; !isNull(next); next = next->m)
		add(p, copy(next));
}


/**
 * Affiche l'entièreté du Polynome
**/
void printPolynome(POLYNOME p) {
	fprintf(stderr,"\nPolynome : ");
	fprintf(stderr,"%fx^%d",p->c,p->d);
	MONOME next;
	for (next = p->m; !isNull(next); next = next->m)
		fprintf(stderr,", %fx^%d",next->c,next->d);
}






