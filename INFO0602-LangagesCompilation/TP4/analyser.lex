
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

"level"		{ return level; }
"end"		{ return end; }
\n			{ line++; }
[[:space:]]	;
.			{ yyerror("Invalid character"); }

%%

void yyerror(const char *error_msg) {
    fprintf(stderr, RED"\nError '%s' on '%s' [Line %d]\n"RESET, error_msg, yytext, line);
    exit(EXIT_FAILURE);
}

