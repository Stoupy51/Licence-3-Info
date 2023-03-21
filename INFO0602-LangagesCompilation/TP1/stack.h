
#ifndef __stack_h__
#define __stack_h__

struct symbol_t {
	char *name;
	int type;
	int value;
};

struct stack_element_t {
	struct stack_element_t *next;
	struct symbol_t symbole;
};

struct stack_t {
	struct stack_element_t *head;
	int size;
};

struct symbol_t initSymbole(char *name, int type, int value);

struct stack_t initStack();
int isEmptyStack(struct stack_t stack);
struct symbol_t popStack(struct stack_t *stack);
int pushStack(struct stack_t *stack, struct symbol_t symbole);
void printStack(struct stack_t stack);
void swapStack(struct stack_t *stack);
void clearStack(struct stack_t *stack);

#endif

