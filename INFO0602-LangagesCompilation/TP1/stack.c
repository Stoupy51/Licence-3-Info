
#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

struct symbol_t initSymbole(char *name, int type, int value) {
	struct symbol_t r = { name, type, value };
	return r;
}

struct stack_t initStack() {
	struct stack_t r = { NULL, 0 };
	return r;
}

int isEmptyStack(struct stack_t stack) {
	return stack.size == 0;
}

struct symbol_t popStack(struct stack_t *stack) {
	// If the stack is empty, return an empty element
	if (stack->size == 0) {
		struct symbol_t r = { NULL, -1, -1 };
		return r;
	}

	// Remove the first element of the stack
	struct stack_element_t *e = stack->head;
	stack->head = e->next;
	stack->size--;

	// Return the symbole of the removed element
	struct symbol_t symbole = e->symbole;
	free(e);
	return symbole;
}

int pushStack(struct stack_t *stack, struct symbol_t symbole) {
	struct stack_element_t *e = malloc(sizeof(struct stack_element_t));
	if (e == NULL)
		return -1;
	e->symbole = symbole;
	e->next = stack->head;
	stack->head = e;
	stack->size++;
	return 1;
}

void printStack(struct stack_t stack) {
	if (stack.size == 0) {
		printf("[]\n");
		return;
	}
	printf("[{ %s, %d, %d }", stack.head->symbole.name, stack.head->symbole.type, stack.head->symbole.value);
	struct stack_element_t *e;
	for (e = stack.head->next; e != NULL; e = e->next)
		printf(", { %s, %d, %d }", e->symbole.name, e->symbole.type, e->symbole.value);
	printf("]\n");
}

void swapStack(struct stack_t *stack) {
	if (stack->size < 2)
		return;
	struct stack_element_t *swap = stack->head;
	stack->head = stack->head->next;
	swap->next = stack->head->next;
	stack->head->next = swap;
}

void clearStack(struct stack_t *stack) {
	while (stack->size != 0)
		popStack(stack);
}

