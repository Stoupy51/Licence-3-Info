
#include "Monome.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * Supprime un Monome dans la chaîne du Polynome
**/
void freePolynome(POLYNOME *m) {
	MONOME next;
	for (next = (*m); !isNull(next);) {
		MONOME ex = next;
		next = ex->m;
		free(ex);
	}
}

/**
 * @return Vrai si le Monome est null
**/
int isNull(MONOME m) {
	return m == (MONOME)NULL;
}

/**
 * @return Vrai si le coefficient et le degré du Monome sont à 0
**/
int abs_mul(MONOME m) {
	return (!m->c && !m->d);
}

/**
 * @return Vrai si le degré du Monome sont à 0
**/
int neutre(MONOME m) {
	return (!m->d && m->c);
}

/**
 * @return Monome initialisé à null
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
 * @return Copie detachée du Monome
**/
MONOME copy(MONOME m) {
	return create(m->d,m->c);
}

/**
 * @return Copie detachée du Monome (avec coefficient opposé)
**/
MONOME negativeCopy(MONOME m) {
	return create(m->d, -m->c);
}

/**
 * Supprime un Monome dans la chaîne du Polynome
**/
void delete(MONOME *m, unsigned int d) {
	MONOME next;
	for (next = (*m); !isNull(next) && next->d != d; next = next->m);
	if (!isNull(next) && next->d == d) {
		MONOME ex = next;
		next = ex->m;
		free(ex);
	}
	//else
		//fprintf(stderr,"\nAucun Monome de degre %d a ete trouve.",d);
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
 * Affiche l'entièreté du Polynome
**/
void print(POLYNOME p) {
	if (isNull(p))
		return;
	fprintf(stderr,"\nPolynome : ");
	fprintf(stderr,"%5.2lfx^%d",p->c,p->d);
	MONOME next;
	for (next = p->m; !isNull(next); next = next->m) {
		if (next->d != 0)
			fprintf(stderr,", %.3lfx^%d",next->c,next->d);
		else
			fprintf(stderr,", %.3lfx",next->c);
	}
}

///////////////////////////////////////////////
////////////////// POLYNOMES //////////////////
///////////////////////////////////////////////

/**
 * @return Copie detachée du Polynome
**/
POLYNOME copyPolynome(POLYNOME p) {
	POLYNOME p2 = init();
	MONOME next;
	for (next = p; !isNull(next); next = next->m)
		add(&p2, copy(next));
	return p2;
}

/**
 * @return Copie detachée du Polynome avec des coefficients opposés
**/
POLYNOME negativeCopyPolynome(POLYNOME p) {
	POLYNOME p2 = init();
	MONOME next;
	for (next = p; !isNull(next); next = next->m)
		add(&p2, negativeCopy(next));
	return p2;
}

/**
 * @return Résultat de la fusion des deux polynomes
**/
POLYNOME fusion(POLYNOME a, POLYNOME b) {
	POLYNOME p = copyPolynome(a);
	MONOME next;
	for (next = b; !isNull(next); next = next->m) {
		add(&p, copy(next));
	}
	return p;
}

/**
 * @return Résultat de la soustraction des deux polynomes
**/
POLYNOME sub(POLYNOME a, POLYNOME b) {
	POLYNOME p = copyPolynome(a);
	MONOME next;
	for (next = b; !isNull(next); next = next->m) {
		add(&p, negativeCopy(next));
	}
	return p;
}

/**
 * @return Résultat de la multiplication de deux polynomes
**/
POLYNOME multiply(POLYNOME a, POLYNOME b) {
	if (isNull(a)) return a;
	if (isNull(b)) return b;
	if (abs_mul(a)) return a;
	if (abs_mul(b)) return b;
	if (neutre(a)) return b;
	if (neutre(b)) return a;
	POLYNOME p = init();
	MONOME x, y;
	for (x = a; !isNull(x); x = x->m) {
		for (y = b; !isNull(y); y = y->m) {
			add(&p, create(x->d + y->d, x->c * y->c));
		}
	}
	return p;
}

/**
 * @return Résultat de la division de deux polynomes
**/
divideResult divide(POLYNOME a, POLYNOME b) {
	divideResult d;
	d.q = init();
	d.r = init();
	if (isNull(b) || abs_mul(b)) {
		fprintf(stderr,"\nWarning: Division par 0 impossible");
		return d;
	}
	if (isNull(a) || abs_mul(a)) {
		d.r = create(0,0.0);
		return d;
	}
	// Cas good
	d.r = copyPolynome(a);
	while (d.r->d >= b->d) {
		fprintf(stderr,"\nEt encore !");
		POLYNOME x = create(d.r->d - b->d, d.r->c / b->c);
		add(&d.q, x);
		print(d.r);
		print(x);
		print(multiply(b,x));
		d.r = sub(d.r, multiply(b,x));
		print(d.r);
		MONOME cc;
		cc->d = cc;
		//print(d.q);
		//print(d.r);
	}
	fprintf(stderr,"\nFin divide !");
	return d;
}




