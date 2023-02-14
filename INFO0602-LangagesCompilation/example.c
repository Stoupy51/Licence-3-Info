
#include <stdlib.h>
#include "stack.h"

extern int yylex();
extern stack_t stack;

int main(int argc, char *argv[]) {
	stack = initStack();
    yylex();
    return EXIT_SUCCESS;
}

