
%{
#include <stdio.h>
#include <stdlib.h>

void yyerror(const char *error_msg);
int yylex();
int error = 0;
%}

%token integer

%left '+' '-'
%left '*' '/'

%%

EXEC: EXPRESSION '.' {
		if (error == 0)
			printf("=%d\n", $1);
		else
			error = 0;
	} EXEC | ;

EXPRESSION: integer
    | EXPRESSION '+' EXPRESSION	{ $$ = $1 + $3; }
	| EXPRESSION '-' EXPRESSION	{ $$ = $1 - $3; }
	| '-' EXPRESSION			{ $$ = -$2; }
	| EXPRESSION '*' EXPRESSION	{ $$ = $1 * $3; }
	| EXPRESSION '/' EXPRESSION	{
		if ($3 == 0) {
			printf("Error: division by zero : %d / %d\n", $1, $3);
			error = 1;
		}
		else
			$$ = $1 / $3;
	}
	| '(' EXPRESSION ')'		{ $$ = $2; }
	;

%%

