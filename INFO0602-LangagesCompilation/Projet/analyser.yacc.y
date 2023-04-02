
%{
#include <stdio.h>
#include <stdlib.h>
#include "level.h"
#include "tree.h"
#include "symbol.h"
#include "table_des_symboles.h"

#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define RESET "\033[0m"
void yyerror(const char *error_msg);
int yylex();

int x, y;
level_t lvl;
block_t v_block;
extern char* outputFileContent;
extern struct symbol_t *symbol;
extern symbol_table t_d_s;
extern int depth;

%}

%token level
%token end
%token put
%token get
%token robot
%token probe
%token empty
%token block
%token trap
%token ladder
%token bomb
%token life
%token key
%token gate
%token door
%token start
%token exite

%union {
	int value;
	char ptr[MAX_NAME];
	symbol_t symbol;
}

%token <value> integer
%token <ptr> id
%token <symbol> variable
%type <value> EXPRESSION ASSIGNMENT

%left '+' '-'
%left '*' '/' '%'

%%

// Global
EXEC: GLOBAL_LIST {
	printf(GREEN"\nValid input!\n"RESET);
};

// Analyze put or get functions
GLOBAL_LIST: GLOBAL_LIST GLOBAL_CONTENT | ;
GLOBAL_CONTENT: LEVEL_BLOCK | ASSIGNMENT;

// Level
LEVEL_BLOCK: level ENTER_LEVEL_BLOCK CONTENT_LIST end {
	// Display the level
	level_display(&lvl);

	// Save the level in the output file
	if (outputFileContent != NULL) {
		// Get char* from level_t
		char* levelStr = level_get_string(&lvl);

		// Concatenate the level to the output file
		strcat(outputFileContent, levelStr);
		strcat(outputFileContent, "\n");

		// Free the level string
		free(levelStr);
	}

	// Free the symbols
	fprintf(stderr,YELLOW"Freeing symbols...\n"RESET);
	removeSymbolDepth(depth, &t_d_s);
	depth -= 1;
	fprintf(stderr,YELLOW"Level %d parsed.\n"RESET, depth);
};
ENTER_LEVEL_BLOCK: {
	depth += 1;
	level_init(&lvl);
};

// Analyze put or assignement
CONTENT_LIST: CONTENT_LIST CONTENT | ;
CONTENT: PUT_FUNC | ASSIGNMENT;

PUT_FUNC: put '(' EXPRESSION ',' EXPRESSION ',' ITEM ')' {

	// Check if the position is valid
	if ($3 < 0 || $3 >= WIDTH || $5 < 0 || $5 >= HEIGHT)
		yyerror("Invalid position.");

	// Put the item
	switch (v_block.type) {
		case ROBOT_B : level_add_robot(&lvl, $3, $5); break;
		case PROBE_B : level_add_probe(&lvl, $3, $5); break;
		case EMPTY_B : level_add_empty(&lvl, $3, $5); break;
		case BLOCK_B : level_add_block(&lvl, $3, $5); break;
		case TRAP_B : level_add_trap(&lvl, $3, $5); break;
		case LADDER_B : level_add_ladder(&lvl, $3, $5); break;
		case BOMB_B : level_add_bomb(&lvl, $3, $5); break;
		case LIFE_B : level_add_life(&lvl, $3, $5); break;
		case KEY_B : level_add_key(&lvl, $3, $5, v_block.value); break;
		case GATE_B : level_add_gate(&lvl, $3, $5, v_block.value); break;
		case DOOR_B : level_add_door(&lvl, $3, $5, v_block.value); break;
		case START_B : level_add_start(&lvl, $3, $5); break;
		case EXIT_B : level_add_exit(&lvl, $3, $5); break;
		default : break;
	}
};

GET_FUNC: get '(' EXPRESSION ',' EXPRESSION ')' {

	// Check if the position is valid
	if ($3 < 0 || $3 >= WIDTH || $5 < 0 || $5 >= HEIGHT)
		yyerror("Invalid position.");

	// Get the item
	v_block = level_get_block(&lvl, $3, $5);
};

ITEM: GET_FUNC
	| robot { v_block = (block_t){ROBOT_B, 0}; }
	| probe { v_block = (block_t){PROBE_B, 0}; }
	| empty { v_block = (block_t){EMPTY_B, 0}; }
	| block { v_block = (block_t){BLOCK_B, 0}; }
	| trap { v_block = (block_t){TRAP_B, 0}; }
	| ladder { v_block = (block_t){LADDER_B, 0}; }
	| bomb { v_block = (block_t){BOMB_B, 0}; }
	| life { v_block = (block_t){LIFE_B, 0}; }
	| key '(' EXPRESSION ')' {
		if ($3 < 1 || $3 > 4)
			yyerror("Invalid key value (must be between 1 and 4).");
		v_block = (block_t){KEY_B, $3};
	}
	| gate '(' EXPRESSION ')' {
		if ($3 < 1 || $3 > 4)
			yyerror("Invalid gate value (must be between 1 and 4).");
		v_block = (block_t){GATE_B, $3};
	}
	| door '(' EXPRESSION ')' {
		if ($3 < 1 || $3 > 99)
			yyerror("Invalid door value (must be between 1 and 99).");
		v_block = (block_t){DOOR_B, $3};
	}
	| start { v_block = (block_t){START_B, 0}; }
	| exite { v_block = (block_t){EXIT_B, 0}; }
	;

EXPRESSION: integer
	| variable {
		// Recherche de la variable dans la table des symboles
		symbol = getSymbolFromTable($1.name, &t_d_s);
		if (symbol == NULL)
			yyerror("Variable not found.");
		$$ = symbol->data.i;
	}
	| EXPRESSION '+' EXPRESSION	{ $$ = $1 + $3; }
	| EXPRESSION '-' EXPRESSION	{ $$ = $1 - $3; }
	| '-' EXPRESSION			{ $$ = -$2; }
	| EXPRESSION '*' EXPRESSION	{ $$ = $1 * $3; }
	| EXPRESSION '/' EXPRESSION	{
		if ($3 == 0) {
			printf("Error: division by zero : %d / %d\n", $1, $3);
			yyerror("division by zero");
		}
		else
			$$ = $1 / $3;
	}
	| EXPRESSION '%' EXPRESSION	{
		if ($3 == 0) {
			printf("Error: modulo by zero : %d %% %d\n", $1, $3);
			yyerror("modulo by zero");
		}
		else
			$$ = $1 % $3;
	}
	| '(' EXPRESSION ')'		{ $$ = $2; }
	;

ASSIGNMENT: id '=' EXPRESSION {
		// Ajout de la variable dans la table des symboles
		symbol = getSymbolFromTable($1, &t_d_s);
		if (symbol == NULL)
			yyerror("Variable not found.");
		symbol->data.i = $3;
		printf(GREEN"[+] Variable %s = %d\n"RESET, symbol->name, symbol->data.i);
	}
	| variable '=' EXPRESSION {
		// Modification de la variable dans la table des symboles
		symbol = getSymbolFromTable($1.name, &t_d_s);
		if (symbol == NULL)
			yyerror("Variable not found.");
		symbol->data.i = $3;
		printf(GREEN"[X] Variable %s = %d\n"RESET, symbol->name, symbol->data.i);
	}
	| variable '+' '=' EXPRESSION {
		symbol = getSymbolFromTable($1.name, &t_d_s);
		if (symbol == NULL)
			yyerror("Variable not found.");
		symbol->data.i += $4;
		printf(GREEN"[X] Variable %s = %d\n"RESET, symbol->name, symbol->data.i);
	}
	| variable '-' '=' EXPRESSION {
		symbol = getSymbolFromTable($1.name, &t_d_s);
		if (symbol == NULL)
			yyerror("Variable not found.");
		symbol->data.i -= $4;
		printf(GREEN"[X] Variable %s = %d\n"RESET, symbol->name, symbol->data.i);
	}
	| variable '*' '=' EXPRESSION {
		symbol = getSymbolFromTable($1.name, &t_d_s);
		if (symbol == NULL)
			yyerror("Variable not found.");
		symbol->data.i *= $4;
		printf(GREEN"[X] Variable %s = %d\n"RESET, symbol->name, symbol->data.i);
	}
	| variable '/' '=' EXPRESSION {
		symbol = getSymbolFromTable($1.name, &t_d_s);
		if (symbol == NULL)
			yyerror("Variable not found.");
		symbol->data.i /= $4;
		printf(GREEN"[X] Variable %s = %d\n"RESET, symbol->name, symbol->data.i);
	}
	| variable '%' '=' EXPRESSION {
		symbol = getSymbolFromTable($1.name, &t_d_s);
		if (symbol == NULL)
			yyerror("Variable not found.");
		symbol->data.i %= $4;
		printf(GREEN"[X] Variable %s = %d\n"RESET, symbol->name, symbol->data.i);
	}
	| variable '+' '+' {
		symbol = getSymbolFromTable($1.name, &t_d_s);
		if (symbol == NULL)
			yyerror("Variable not found.");
		symbol->data.i++;
		printf(GREEN"[X] Variable %s = %d\n"RESET, symbol->name, symbol->data.i);
	}
	| variable '-' '-' {
		symbol = getSymbolFromTable($1.name, &t_d_s);
		if (symbol == NULL)
			yyerror("Variable not found.");
		symbol->data.i--;
		printf(GREEN"[X] Variable %s = %d\n"RESET, symbol->name, symbol->data.i);
	}
	;

%%

