
%{
// C includes
#include "stack.h"

void empile(int i);
void depile(char operator);

int compteur = 0;
int num_row = 1;
stack_t stack;

%}

/* To avoid warnings on input and yyunput */
%option nounput
%option noinput

%%

(\-[0-9])+	{ empile(atoi(yytext)); }
[0-9]+		{ empile(atoi(yytext)); }
\+			{ depile('+'); }
\-			{ depile('-'); }
\*			{ depile('*'); }
\/			{ depile('/'); }
=			{ printStack(stack); }
"SWAP"		{ swapStack(&stack); }
"CLEAR"		{ clearStack(&stack); }
\n			{ num_row++; }
.			;

%%

// C user functions
void empile(int i) {
	printf("[%d - %d] Number: %d\n", num_row, compteur++, i);
	pushStack(&stack, initSymbole("int", 1, i));
}

void depile(char operator) {

	int a = popStack(&stack);
	int b = popStack(&stack);
	int c;
	if (operator == '+')
		c = a + b;
	else if (operator == '-')
		c = a - b;
	else if (operator == '*')
		c = a * b;
	else if (operator == '/')
		c = a / b;

	printf("[%d - %d] Opération : %d %c %d = %d\n", num_row, compteur++, a, operator, b, c);
	pushStack(&stack, c);
}

