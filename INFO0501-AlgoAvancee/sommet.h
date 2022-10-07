
#ifndef __sommet_h__
#define __sommet_h__

#include <stdlib.h>
#include <stdio.h>

#define WHITE 0
#define GRAY 1
#define BLACK 2
#define MAX_INT 2147483648

typedef struct sommet Sommet;
struct sommet {
	int id;
	int color;
	int distance;
	int pere;
	// Dates découverte et fin
	int d, f;
};

Sommet initSommet(int n);

#endif

