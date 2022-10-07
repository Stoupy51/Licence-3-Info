
#include "tas.h"

Tas initTas(int size) {
	Tas t;
	t.size = size;
	t.data = (int*)malloc(sizeof(int) * size);
	return t;
}

int parentTas(Tas t, int i) {
	return (i - 1) / 2;
}

int gaucheTas(Tas t, int i) {
	return 2 * i + 1;
}

int droiteTas(Tas t, int i) {
	return 2 * i + 2;
}

void entasserMax(Tas t, int i) {
	int g = gaucheTas(t, i);
	int d = droiteTas(t, i);
	int max = i;
	if (g < t.size && t.data[g] > t.data[i])
		max = g;
	if (d < t.size && t.data[d] > t.data[max])
		max = d;
	if (max != i) {
		int tmp = t.data[i];
		t.data[i] = t.data[max];
		t.data[max] = tmp;
		entasserMax(t, max);
	}
}

Tas construireTasMax(int* data, int size) {
	Tas t = initTas(size);
	int i;
	for (i = 0; i < size; i++)
		t.data[i] = data[i];
	for (i = size / 2 - 1; i >= 0; i--)
		entasserMax(t, i);
	return t;
}

void destroyTas(Tas t) {
	free(t.data);
}



