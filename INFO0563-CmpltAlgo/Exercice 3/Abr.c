
#include "Abr.h"

ABR initAbr() { return (ABR)NULL; }
int isNull(ABR a) { return a == (ABR)NULL; }
int isLeaf(ABR a) { return !isNull(a) && isNull(a->g) && isNull(a->d); }
int max(int a, int b) { return a < b ? b : a; }

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
void addValue(ABR *a, int v) {
	if (isNull(*a)) {
		(*a) = create(v);
		return;
	}
	if ((*a)->value == v) {
		(*a)->occurences++;
		return;
	}
	if (v < (*a)->value)
		addValue(&(*a)->g, v);
	else
		addValue(&(*a)->d, v);
}

/**
 * @b Ajoute une liste de valeur dans l'arbre
**/
void addValuesList(ABR* a, int* v, int size) {
	int i;
	for (i = 0; i < size; i++)
		addValue(a, v[i]);
}


/**
 * Supprime une valeur de l'arbre selon plusieurs cas
 * @b Diminue l'occurence @if celle-ci est supérieure à 1
 * @b Supprime la valeur de l'arbre par un réagencement @else
**/
void removeValue(ABR *a, int v) {
	if (isNull(*a)) {
		fprintf(stderr, "\nLa valeur %d n'est pas présente dans l'arbre", v);
		return;
	}
	if ((*a)->value == v) {
		if (!(--(*a)->occurences)) {
			fprintf(stderr, "\nSuppression de la valeur %d", (*a)->value);
			if (isLeaf(*a)) {
				fprintf(stderr, "\nSuppression de la feuille %d", (*a)->value);
				free(*a);
				(*a) = initAbr();
				// TODO: PROBLEME ICI
				return;
			}
			ABR m = isNull((*a)->g) ? minPtr((*a)->d) : maxPtr((*a)->g);
			int tmp = (*a)->value;
			(*a)->value = m->value;
			(*a)->occurences = m->occurences;
			m->value = tmp;
			m->occurences = 1;
			fprintf(stderr, "\nRemplacement de la valeur %d par la valeur %d", tmp, (*a)->value);
			fprintf(stderr, "\n(*a)->occ = %d, m->occ = %d", (*a)->occurences, m->occurences);
			removeValue(&m, v);
		}
		return;
	}
	if (v < (*a)->value)
		removeValue(&(*a)->g, v);
	else
		removeValue(&(*a)->d, v);
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
		return;
	}
	if (hg < hd) {
		ABR D = (*a)->d;
		ABR old = D->g;
		if (!isNull(D->d)) {
			D->g = (*a);
			(*a)->d = old;
			(*a) = D;
		}
		else {
			D->g = D->g->d;
			(*a)->d = D->g->g;
			D->g->d = D;
			D->g->g = (*a);
			(*a) = old;
		}
	}
}

void coquilleParfaite(ABR *a, int i, int n);

void infixe(ABR *a);

void balanceV2(ABR *a);


void repeat_char(int count, char* c) {
	while (--count > 0)
		fprintf(stderr,"%s",c);
}

/**
 * Affiche l'arbre du mieux qu'il peut
**/
void printAbr(ABR *a) {
	int h = getHeight(*a);
	int s = getTotalNodes(*a);
	int i, j;

	// Création des tableaux	
	int** heights = (int**)malloc(sizeof(int*) * h);
	heights[0] = (int*)malloc(sizeof(int) * 1);
	heights[0][0] = -1;
	int k = 2;
	for (i = 1; i < h; i++, k *= 2) {
		heights[i] = (int*)malloc(sizeof(int) * k);
		for (j = 0; j < k; j++)
			heights[i][j] = -1;
	}

	// Remplissage des tableaux
	addValueIntoT(heights, 0, 0, 1, *a);

	// Affichage des tableaux
	k = 1;
	for (i = 1; i < h; i++)
		k *= 2;
	fprintf(stderr,"\n");
	int level = 1;
	int b = 0;
	for (i = h-1; i >= 0; i--, k /= 2, level*=2, b = 0) {
		fprintf(stderr,"\n\n");
		for (j = 0; j < k; j++, b = 1) {
			repeat_char(level + b*(level-1), " ");
			//fprintf(stderr,"(%d)",b);
			fprintf(
				stderr,
				heights[i][j] == -1 ? " x" : (heights[i][j] > -10 && heights[i][j] < 10 ? " %d": " %d"),
				heights[i][j]
			);
		}
	}
}

/**
 * Sous fonction de @b printAbr qui remplit un tableau en fonction de la hauteur séléctionnée
**/
void addValueIntoT(int** T, int level, int i, int isG, ABR a) {
	if (isNull(a))
		return;
	if (T[level][i] == -1)
		T[level][i] = a->value;
	addValueIntoT(T, level+1, i*2, 0, a->g);
	addValueIntoT(T, level+1, i*2+1, 0, a->d);
}

