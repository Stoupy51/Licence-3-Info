
#ifndef __stack_h__
#define __stack_h__

typedef struct stack_element_t stack_element_t;
struct stack_element_t {
	stack_element_t *next;
	int value;
};

typedef struct {
	stack_element_t *head;
	int size;
} stack_t;

stack_t initStack();
int isEmptyStack(stack_t stack);
int popStack(stack_t *stack);
int pushStack(stack_t *stack, int i);
void printStack(stack_t stack);
void swapStack(stack_t *stack);
void clearStack(stack_t *stack);

#endif

