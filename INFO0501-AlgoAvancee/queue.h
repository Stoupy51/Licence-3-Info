
#ifndef __queue_h__
#define __queue_h__

#include "sommet.h"

typedef struct queue {
	Sommet* data;
	int head,
		tail,
		size;
} Queue;

Queue initQueue(int size);
void destroyQueue(Queue q);
int isQueueEmpty(Queue q);
int isQueueFull(Queue q);
void enfilerQueue(Queue q, Sommet s);
Sommet defilerQueue(Queue q);
void printQueue(Queue q);

#endif

