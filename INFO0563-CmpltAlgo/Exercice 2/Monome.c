
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
void delete(MONOME m, unsigned int d) {
	MONOME next;
	for (next = m; !isNull(next) && next->m->d != d; next = next->m);
	if (next->m->d == d) {
		MONOME ex = next->m;
		next->m = ex->m;
		free(ex);
	}
	else
		fprintf(stderr,"\nAucun Monome de degre %d a ete trouve.",d);
}

/**
 * Supprime un Monome dans la chaîne du Polygone de manière récursive
**/
void deleteRecursif(MONOME m, unsigned int d) {
	if (isNull(m)) {
		fprintf(stderr,"\nAucun Monome de degre %d a ete trouve.",d);
		return;
	}
	if (d == m->d) {
		MONOME ex = m;
		m = m->m;
		free(ex);
		return;
	}
	if (d < m->d)
		deleteRecursif(m->m, d);
}


/**
 * Ajoute un Monome dans le Polygone
**/
void add(MONOME *m, MONOME a) {
	fprintf(stderr,"\nici 1");
	if (isNull(*m)) {
		(*m) = a;
		return;
	}
	fprintf(stderr,"\na=%d, m=%d",a->d,(*m)->d);
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
	MONOME t = head(m);
	if (a->d == t->d) {
		if (!(t->c += a->c)) {
			delete(*m, t->d);
			return;
		}
	}
	// Sinon, si le degré est inférieur,
	// chercher une place dans la chaîne -- TODO
	else
		add(m, a);
	(*m) = t;
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






