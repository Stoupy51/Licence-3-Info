
#ifndef __arete_h__
#define __arete_h__

#include <stdlib.h>
#include <stdio.h>

typedef struct arete {
	int u, v;
	int poids;
} Arete;

Arete initArete();
Arete newArete(int s1, int s2, int poids);

#endif

