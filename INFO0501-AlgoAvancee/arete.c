
#include "arete.h"

Arete initArete() {
	Arete a;
	a.u = -1;
	a.v = -1;
	a.poids = -1;
	return a;
}

Arete newArete(int s1, int s2, int poids) {
	Arete a;
	a.u = s1;
	a.v = s2;
	a.poids = poids;
	return a;
}


