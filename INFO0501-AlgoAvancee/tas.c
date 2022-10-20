
#include "tas.h"

Tas initTas(int size) {
	Tas t;
	t.size = size;
	t.data = (Arete*)malloc(sizeof(Arete) * size);
	return t;
}

int parentTas(int i) {
	return i / 2;
}

int gaucheTas(int i) {
	return 2 * i;
}

int droiteTas(int i) {
	return 2 * i + 1;
}

void entasserMax(Tas t, int i) {
	int g = gaucheTas(i);
	int d = droiteTas(i);
	int max = i;
	if (g <= t.size && t.data[g].poids > t.data[i].poids)
		max = g;
	if (d <= t.size && t.data[d].poids > t.data[max].poids)
		max = d;
	if (max != i) {
		Arete tmp = t.data[i];
		t.data[i] = t.data[max];
		t.data[max] = tmp;
		entasserMax(t, max);
	}
}

Tas construireTasMax(Arete* data) {
	Tas t = initTas(data[0].poids);
	int i;
	for (i = 0; i <= t.size; i++)
		t.data[i] = data[i];
	
	//printPoidsAretes(t.data);
	for (i = (t.size / 2 + 1); i > 0; i--)
		entasserMax(t, i);
	//printPoidsAretes(t.data);
	return t;
}

void destroyTas(Tas t) {
	free(t.data);
	t.size = 0;
}



