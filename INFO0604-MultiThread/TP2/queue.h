
#ifndef __queue_h__
#define __queue_h__

#include <stdlib.h>
#include <stdio.h>

typedef struct queue_t {
	int* data;
	int head,
		tail,
		size,
		count;
} Queue, queue_t;

Queue initQueue(int size);
void destroyQueue(Queue q);
int isQueueEmpty(Queue q);
int isQueueFull(Queue q);
void enfilerQueue(Queue* q, int s);
int defilerQueue(Queue* q);
void printQueue(Queue q);

#endif

