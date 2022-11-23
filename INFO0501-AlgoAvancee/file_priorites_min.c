
#include "file_priorites_min.h"

FPM initFPM(int size) {
	FPM t;
	t.size = size;
	t.data = (int*)malloc(sizeof(int) * size);
	return t;
}

int parentFPM(int i) { return i / 2; }
int gaucheFPM(int i) { return 2 * i; }
int droiteFPM(int i) { return 2 * i + 1; }

void entasserMinFPM(FPM t, int i) {
	int g = gaucheFPM(i);
	int d = droiteFPM(i);
	int min = i;

	if (d < t.size && t.data[d] < t.data[min])
		min = d;
	if (g < t.size && t.data[g] < t.data[min])
		min = g;

	if (min != i) {
		int tmp = t.data[i];
		t.data[i] = t.data[min];
		t.data[min] = tmp;
		entasserMinFPM(t, min);
	}
}

FPM construireFPM(int* data, int size) {
	FPM t = initFPM(size);
	int i;
	for (i = 0; i <= t.size; i++)
		t.data[i] = data[i];
	
	for (i = (t.size / 2 + 1); i >= 0; i--)
		entasserMinFPM(t, i);

	return t;
}

void destroyFPM(FPM t) {
	free(t.data);
	t.size = 0;
}

void triParFPM(FPM t) {
	int i = t.data[0];
	t.data[0] = t.data[t.size-1];
	t.data[t.size-1] = i;

	int tmp;
	for (i = 0; i < t.size / 2; i++)
		entasserMinFPM(t, i);
}


int extraireMinFPM() {
	
}







