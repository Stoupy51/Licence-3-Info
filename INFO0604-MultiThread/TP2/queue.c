
#include "queue.h"

Queue initQueue(int size) {
	Queue q;
	q.size = size + 1;
	q.head = q.tail = 0;
	q.data = (int*)malloc(sizeof(int) * q.size);
	q.count = 0;
	return q;
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

void enfilerQueue(Queue* q, int s) {
	if (isQueueFull(*q)) {
		fprintf(stderr,"\nErreur : La queue est pleine");
		return;
	}
	q->count++;
	q->data[q->head] = s;
	q->head = (q->head + 1) % q->size;
}

int defilerQueue(Queue* q) {
	if (isQueueEmpty(*q)) {
		fprintf(stderr,"\nErreur : La queue est vide");
		return -1;
	}
	q->count--;
	int s = q->data[q->tail];
	q->tail = (q->tail + 1) % q->size;
	return s;
}

void printQueue(Queue q) {
	printf("\nQueue : ");
	if (isQueueEmpty(q)) {
		printf("Vide");
		return;
	}
	printf("[");
	printf("%d", q.data[0]);
	int i = 1;
	for (; i < q.size; i++)
		printf(", %d", q.data[i]);
	printf("]\n");
}



