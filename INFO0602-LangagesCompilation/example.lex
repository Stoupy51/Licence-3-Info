
%{
// C includes
#include "stack.h"

int compteur = 0;
stack_t stack = initStack();

%}

/* To avoid warnings on input and yyunput */
%option nounput
%option noinput

%%

[0-9]+	{ printf("[%d] Number: %s\n", compteur++, yytext); }
\+		{ printf("[%d] Plus: %s\n", compteur++, yytext); }
\-		{ printf("[%d] Minus: %s\n", compteur++, yytext); }
\*		{ printf("[%d] By: %s\n", compteur++, yytext); }
\/		{ printf("[%d] Slash: %s\n", compteur++, yytext); }

.	;

%%

// C user functions

