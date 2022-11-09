
#ifndef __cellule_h__
#define __cellule_h__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define WORDLENGTH 27

typedef struct cellule Cellule;
struct cellule {
	Cellule* prev;
	Cellule* next;
	char* word;
};

Cellule* initCellule();
Cellule* newCellule(char* w);

#endif

