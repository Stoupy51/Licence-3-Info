
#ifndef __Abr__
#define __Abr__

#include <stdlib.h>
#include <stdio.h>

typedef struct abr Abr, *ABR;
struct abr {
	int value,
		occurences;
	ABR g,
		d;
};

ABR initAbr();
int isNull(ABR a);
int isLeaf(ABR a);
int getTotalNodes(ABR a);
int getHeight(ABR a);
ABR create(int v);
void add(ABR* a, int v);
void remove(ABR* a, int v);
ABR minPtr(ABR a);
ABR maxPtr(ABR a);
void balance(ABR* a);
void coquilleParfaite(ABR* a, int i, int n);
void infixe(ABR* a);
void balanceV2(ABR* a);

typedef struct couple {
	int value,
		level
} Couple;
typedef struct coupleList {
	int size;
	int nextIndex;
	Couple** list;
} CoupleList;
void printAbr(ABR a);



#endif
