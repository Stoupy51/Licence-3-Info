
#ifndef __queue_h__
#define __queue_h__

#include "sommet.h"

typedef struct queue {
	int* data;
	int head,
		tail,
		size;
} Queue;

Queue initQueue(int size);
void destroyQueue(Queue q);
int isQueueEmpty(Queue q);
int isQueueFull(Queue q);
void enfilerQueue(Queue* q, int s);
int defilerQueue(Queue* q);
void printQueue(Queue q);

#endif

