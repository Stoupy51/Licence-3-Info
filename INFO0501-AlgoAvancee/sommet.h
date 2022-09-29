
#ifndef __sommet_h__
#define __sommet_h__

#include <stdlib.h>
#include <stdio.h>

typedef struct sommet Sommet;

struct sommet {
	int id;
	int color;
	int distance;
	Sommet* pere;
};

Sommet initSommet(int n);

#endif

