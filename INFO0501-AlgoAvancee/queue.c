
#include "queue.h"

Queue initQueue(int size) {
	Queue q;
	q.size = size + 1;
	q.head = q.tail = 0;
	q.data = (Sommet*)malloc(sizeof(Sommet) * size);
}

void destroyQueue(Queue q) {
	free(q.data);
	q.size = 0;
}

int isQueueEmpty(Queue q) {
	return q.head == q.tail;
}

int isQueueFull(Queue q) {
	return (!q.tail && q.head == q.size - 1) || (q.head + 1) % q.size == q.tail;
}

void enfilerQueue(Queue q, Sommet s) {
	if (isQueueFull(q)) {
		fprintf(stderr,"\nErreur : La queue est pleine");
		return;
	}
	q.data[q.head] = s;
	q.head = (q.head + 1) % q.size;
}

Sommet defilerQueue(Queue q) {
	if (isQueueEmpty(q)) {
		fprintf(stderr,"\nErreur : La queue est vide");
		return initSommet(-1);
	}
	Sommet s = q.data[q.tail];
	q.tail = (q.tail + 1) % q.size;
	return s;
}

void printQueue(Queue q) {
	fprintf(stderr,"\nQueue : ");
	if (isQueueEmpty(q)) {
		fprintf(stderr,"Vide");
		return;
	}
	fprintf(stderr,"\n[");
	int i = 0;
	for (; i < q.size; i++)
		fprintf(stderr,"%d ", q.data[i].id);
	fprintf(stderr,"]");
}



