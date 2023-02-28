
#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

stack_t initStack() {
	stack_t r = { NULL, 0 };
	return r;
}

int isEmptyStack(stack_t stack) {
	return stack.size == 0;
}

int popStack(stack_t *stack) {
	if (stack->size == 0)
		return -1;
	stack_element_t *e = stack->head;
	int r = e->value;
	stack->head = e->next;
	stack->size--;
	free(e);
	return r;
}

int pushStack(stack_t *stack, int i) {
	stack_element_t *e = malloc(sizeof(stack_element_t));
	if (e == NULL)
		return -1;
	e->value = i;
	e->next = stack->head;
	stack->head = e;
	stack->size++;
	return 1;
}

void printStack(stack_t stack) {
	if (stack.size == 0) {
		printf("[]\n");
		return;
	}
	printf("[%d", stack.head->value);
	stack_element_t *e;
	for (e = stack.head->next; e != NULL; e = e->next)
		printf(", %d", e->value);
	printf("]\n");
}

void swapStack(stack_t *stack) {
	if (stack->size < 2)
		return;
	stack_element_t *swap = stack->head;
	stack->head = stack->head->next;
	swap->next = stack->head->next;
	stack->head->next = swap;
}

void clearStack(stack_t *stack) {
	while (stack->size != 0)
		popStack(stack);
}

