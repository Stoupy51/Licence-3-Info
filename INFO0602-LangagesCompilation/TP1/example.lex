
%{
// C includes
#include "stack.h"

void empile(int i);
void depile(char operator);

int compteur = 0;
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


.	;

%%

// C user functions
void empile(int i) {
	printf("[%d] Number: %d\n", compteur++, i);
	pushStack(&stack, i);
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

	printf("[%d] Opération : %d %c %d = %d\n", compteur++, a, operator, b, c);
	pushStack(&stack, c);
}

