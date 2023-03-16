
%{
#include "y.tab.h" 

#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define RED "\033[1;31m"
#define RESET "\033[0m"

void yyerror(const char *error_msg);
extern int yylval;
int line = 1;
%}

/* To avoid warnings on input and yyunput */
%option nounput
%option noinput

%%

-?[0-9]+	{ yylval = atoi(yytext); return integer; }
"level"		{ return level; }
"end"		{ return end; }
"put"		{ return put; }
"robot"		{ return robot; }
"probe"		{ return probe; }
"empty"		{ return empty; }
"block"		{ return block; }
"trap"		{ return trap; }
"ladder"	{ return ladder; }
"bomb"		{ return bomb; }
"life"		{ return life; }
"key"		{ return key; }
"gate"		{ return gate; }
"door"		{ return door; }
"start"		{ return start; }
"exite"		{ return exite; }
\n			{ line++; }
[[:space:]]	;
.			{ yyerror("Invalid character"); }

%%

void yyerror(const char *error_msg) {
    fprintf(stderr, RED"\nError '%s' on '%s' [Line %d]\n"RESET, error_msg, yytext, line);
    exit(EXIT_FAILURE);
}

