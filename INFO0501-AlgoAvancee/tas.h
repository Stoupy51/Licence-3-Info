
#ifndef __tas_h__
#define __tas_h__

#include <stdlib.h>
#include <stdio.h>

typedef struct tas {
	int* data;
	int size;
} Tas;

Tas initTas(int size);
int parentTas(Tas t, int i);
int gaucheTas(Tas t, int i);
int droiteTas(Tas t, int i);
void entasserMax(Tas t, int i);
Tas construireTasMax(int* data, int size);
void destroyTas(Tas t);

#endif

