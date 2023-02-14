
#include <stdio.h>

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
	return 1;
}


