
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
int max(int a, int b);
int getTotalNodes(ABR a);
int getHeight(ABR a);
ABR create(int v);
void addValue(ABR* a, int v);
void addValuesList(ABR* a, int* v, int size);
void removeValue(ABR* a, int v);
ABR minPtr(ABR a);
ABR maxPtr(ABR a);
void balance(ABR* a);
void coquilleParfaite(ABR* a, int i, int n);
void infixe(ABR* a);
void balanceV2(ABR* a);

void repeat_char(int count, char* c);
void addValueIntoT(int** T, int level, int i, int isG, ABR a);
void printAbr(ABR* a);



#endif
