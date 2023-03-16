
%{
#include <stdio.h>
#include <stdlib.h>
#include "level.h"

#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define RESET "\033[0m"
void yyerror(const char *error_msg);
int yylex();

level_t lvl;

%}

%token level
%token end

%%

EXEC: LEVEL_BLOCK EXEC
	| LEVEL_BLOCK { printf(GREEN"\nValid input!\n"RESET); }

LEVEL_BLOCK: level { level_init(&lvl); } CONTENT end { level_display(&lvl); }

CONTENT: ;

%%

