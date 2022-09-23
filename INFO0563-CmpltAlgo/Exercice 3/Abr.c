
#include "Abr.h"

ABR initAbr() { return (ABR)NULL; }
int isNull(ABR a) { return a == (ABR)NULL; }
int isLeaf(ABR a) { return !isNull(a) && isNull(a->g) && isNull(a->d); }

/**
 * @return le nombre de sommets total dans l'arbre a
**/
int getTotalNodes(ABR a) {
	return isNull(a) ? 0 : 1 + getTotalNodes(a->g) + getTotalNodes(a->d);
}

/**
 * @return la hauteur de l'arbre
**/
int getHeight(ABR a) {
	return isNull(a) ? 0 : 1 + max(getHeight(a->g), getHeight(a->d));
}

/**
 * @return un arbre sans fils avec comme valeur v
**/
ABR create(int v) {
	ABR a = (ABR)malloc(sizeof(Abr));
	a->value = v;
	a->occurences = 1;
	a->g = a->d = initAbr();
	return a;
}

/**
 * Ajoute une valeur dans l'arbre selon plusieurs cas
 * @b Augmente l'occurence si la valeur est déjà présente
 * @b Si l'arbre est vide, un arbre est crée avec la valeur
 * @b Ajoute la valeur dans le fils de gauche si la valeur est inférieure à celle de l'arbre
 * @b Ajoute la valeur dans le fils de droit si la valeur est supérieure à celle de l'arbre
**/
void add(ABR *a, int v) {
	if ((*a)->value == v) {
		(*a)->occurences++;
		return;
	}
	if (v < (*a)->value)
		add(&(*a)->g, v);
	else
		add(&(*a)->d, v);
}

/**
 * Supprime une valeur de l'arbre selon plusieurs cas
 * @b Diminue l'occurence @if celle-ci est supérieure à 1
 * @b Supprime la valeur de l'arbre par un réagencement @else
**/
void remove(ABR *a, int v) {
	if ((*a)->value = v) {
		if (!(*a)->occurences--) {
			if (isLeaf(*a)) {
				free(*a);
				(*a) = init();
				return;
			}
			ABR m = isNull((*a)->g) ? minPtr((*a)->d) : maxPtr((*a)->g);
			int tmp = (*a)->value;
			(*a)->value = m->value;
			m->value = tmp;
			remove(&m, m->value);
		}
		return;
	}
	if (v < (*a)->value)
		remove(&(*a)->g, v);
	else
		remove(&(*a)->d, v);
}

/**
 * @return un pointeur sur l'arbre le plus petit à partir de l'arbre a
**/
ABR minPtr(ABR a) {
	return isNull(a) ? a : (isNull(a->g) ? &(*a) : minPtr(a->g));
}

/**
 * @return un pointeur sur l'arbre le plus grand à partir de l'arbre a
**/
ABR maxPtr(ABR a) {
	return isNull(a) ? a : (isNull(a->d) ? &(*a) : maxPtr(a->d));
}

/**
 * Permet d'équilibrer l'arbre afin d'avoir un coefficient de déséquilibre <= 1
**/
void balance(ABR* a) {
	int hg = getHeight((*a)->g);
	int hd = getHeight((*a)->d);
	int coef = hg - hd;
	if (coef < 2 && coef > -2)
		return;
	if (hg > hd) {
		ABR G = (*a)->g;
		ABR old = G->d;
		if (!isNull(G->g)) {
			G->d = (*a);
			(*a)->g = old;
			(*a) = G;
		}
		else {
			G->d = G->d->g;
			(*a)->g = G->d->d;
			G->d->g = G;
			G->d->d = (*a);
			(*a) = old;
		}
	}
}

void coquilleParfaite(ABR *a, int i, int n);

void infixe(ABR *a);

void balanceV2(ABR *a);


/**
 * Affiche l'arbre du mieux qu'il peut
**/
void printAbr(ABR a) {
	int h = getHeight(a);
	int s = getTotalNodes(a);
	int i, j;

	// Création des tableaux	
	int** heights = (int**)malloc(sizeof(int*) * h);
	for (i = 0; i < h; i++)
		heights[i] = (int*)malloc(sizeof(int) * i * i + 1);

	// Remplissage des tableaux
	CoupleList* c;
	c->list = (Couple*)malloc(sizeof(Couple) * s);
	c->nextIndex = 0;
	c->size = s;
	addValueIntoT(&c, 0, a);
	int indexes[h];
	for (i = 0; i < h; i++)
		indexes[i] = 0;
	for (i = 0; i < s; i++) {
		int level = c->list[i]->level;
		heights[level][indexes[level]] = c->list[i]->value;
		indexes[level]++;
	}

}

/**
 * Sous fonction de @b printAbr qui remplit un tableau en fonction de la hauteur séléctionnée
**/
void addValueIntoT(CoupleList* l, int level, ABR a) {
	if (isNull(a))
		return;
	Couple* c;
	c->level = level;
	c->value = a->value;
	l->list[l->nextIndex] = c;
	l->nextIndex++;
	addValueIntoT(&(*l), level+1, a->g);
	addValueIntoT(&(*l), level+1, a->d);
}

