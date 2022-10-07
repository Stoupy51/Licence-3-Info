
#include "sommet.h"

Sommet initSommet(int n) {
	Sommet s;
	s.id = n;
	s.color = WHITE;
	s.distance = MAX_INT;
	s.pere = s.d = s.f = -1;
	return s;
}

