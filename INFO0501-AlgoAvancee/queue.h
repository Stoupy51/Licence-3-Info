
#ifndef __queue_h__
#define __queue_h__

#include <stdlib.h>
#include <stdio.h>

typedef struct queue {
	int* list;
	int head,
		next,
		size;
} Queue, *QUEUE;

void initQueue(QUEUE q);
void emfiler(QUEUE q, int v);
int defiler(QUEUE q);

#endif

