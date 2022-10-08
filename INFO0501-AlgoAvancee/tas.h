
#ifndef __tas_h__
#define __tas_h__

#include "arete.h"

typedef struct tas {
	Arete* data;
	int size;
} Tas;

Tas initTas(int size);
int parentTas(int i);
int gaucheTas(int i);
int droiteTas(int i);
void entasserMax(Tas t, int i);
Tas construireTasMax(Arete* data);
void destroyTas(Tas t);

#endif

