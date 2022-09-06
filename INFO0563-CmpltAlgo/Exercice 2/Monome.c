
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
}











