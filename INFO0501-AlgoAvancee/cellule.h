
#ifndef __cellule_h__
#define __cellule_h__

#include <stdlib.h>
#include <stdio.h>

typedef struct cellule Cellule, *CELLULE;
struct cellule {
	CELLULE prev, next;
	int value;
	int poids;
};

CELLULE initCellule();
CELLULE newCellule(int v);
CELLULE newCelluleAvecPoids(int v, int p);

#endif

