
#ifndef __stack_h__
#define __stack_h__

typedef struct {
	struct stack_element_t *next;
	int value;
} stack_element_t;

typedef struct {
	stack_element_t *head;
	int size;
} stack_t;

stack_t initStack();
int isEmptyStack(stack_t stack);
int popStack(stack_t *stack);
int pushStack(stack_t *stack, int i);

#endif

