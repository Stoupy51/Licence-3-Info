
#ifndef __file_priorites_min_h__
#define __file_priorites_min_h__

#include <stdlib.h>
#include <stdio.h>

typedef struct file_priorites_min {
	int* data;
	int size;
} FilePrioritesMin, FPM;

FPM initFPM(int size);
int parentFPM(int i);
int gaucheFPM(int i);
int droiteFPM(int i);
void entasserMinFPM(FPM t, int i);
FPM construireFPM(int* data, int size);
void destroyFPM(FPM t);
void triParFPM(FPM t);

int extraireMinFPM();

#endif

