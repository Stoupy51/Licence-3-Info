
#ifndef __cellule_h__
#define __cellule_h__

#include "includes.h"

typedef struct cellule Cellule;
struct cellule {
	Cellule* prev;
	Cellule* next;
	char* word;
};

Cellule* initCellule();
Cellule* newCellule(char* w);

#endif

