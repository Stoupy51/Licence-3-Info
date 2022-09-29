

#include "sommet.h"
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define MAX_INT 2147483648

Sommet initSommet(int n) {
	Sommet s;
	s.id = n;
	s.color = WHITE;
	s.distance = MAX_INT;
	s.pere = (Sommet*)NULL;
}



