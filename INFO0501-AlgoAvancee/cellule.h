
#ifndef __cellule_h__
#define __cellule_h__

#include <stdlib.h>
#include <stdio.h>

typedef struct cellule Cellule, *CELLULE;
struct cellule {
	CELLULE prev, next;
	int value;
};

CELLULE initCellule();
CELLULE newCellule(int x);

#endif

