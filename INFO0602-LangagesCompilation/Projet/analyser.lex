
%{
#include "table_des_symboles.h"
#include "y.tab.h"

#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define RED "\033[1;31m"
#define RESET "\033[0m"

void yyerror(const char *error_msg);

//extern int yylval;

extern struct symbol_t *symbol;
extern symbol_table t_d_s;
int line = 1;
%}

/* To avoid warnings on input and yyunput */
%option nounput
%option noinput

%%

-?[0-9]+	{ yylval.value = atoi(yytext); return integer; }
"level"		{ return level; }
"end"		{ return end; }
"put"		{ return put; }
"ROBOT"		{ return robot; }
"PROBE"		{ return probe; }
"EMPTY"		{ return empty; }
"BLOCK"		{ return block; }
"TRAP"		{ return trap; }
"LADDER"	{ return ladder; }
"BOMB"		{ return bomb; }
"LIFE"		{ return life; }
"KEY"		{ return key; }
"GATE"		{ return gate; }
"DOOR"		{ return door; }
"START"		{ return start; }
"EXITE"		{ return exite; }
[a-zA-Z][a-zA-Z0-9_]*	{
	// Recherche de la variable dans la table des symboles
	symbol = getSymbolFromTable(yytext, &t_d_s);
	if (symbol == NULL) {
		// Ajout de la variable dans la table des symboles
		symbol_t sym;
		sym.name = strdup(yytext);
		sym.type = SYMBOL_TYPE_INTEGER;
		symbol = addSymbolInTable(sym, &t_d_s);
		return id;
	}
	else {
		// La variable existe déjà dans la table des symboles
		return variable;
	}
}
[-+*/\.(),]	{ return *yytext; }
\n			{ line++; }
[[:space:]]	;
.			{ yyerror("Invalid character"); }

%%

void yyerror(const char *error_msg) {
    fprintf(stderr, RED"\nError '%s' on '%s' [Line %d]\n"RESET, error_msg, yytext, line);
    exit(EXIT_FAILURE);
}

