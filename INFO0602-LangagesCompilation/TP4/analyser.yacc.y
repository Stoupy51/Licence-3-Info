
%{
#include <stdio.h>
#include <stdlib.h>
#include "level.h"

#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define RESET "\033[0m"
void yyerror(const char *error_msg);
int yylex();

int x, y;
level_t lvl;
block_t v_block;

%}

%token integer
%token level
%token end
%token put
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

%%

EXEC: LEVEL_BLOCK EXEC | LEVEL_BLOCK {
	printf(GREEN"\nValid input!\n"RESET);
};

LEVEL_BLOCK: level { level_init(&lvl); } CONTENT end { level_display(&lvl); };

CONTENT: PUT_FUNC CONTENT | PUT_FUNC | ;

PUT_FUNC: put '(' integer ',' integer ',' ITEM ')' {
	switch (v_block.type) {
		case 1 : level_add_robot(&lvl, $3, $5); break;
		case 2 : level_add_probe(&lvl, $3, $5); break;
		case 3 : level_add_empty(&lvl, $3, $5); break;
		case 4 : level_add_block(&lvl, $3, $5); break;
		case 5 : level_add_trap(&lvl, $3, $5); break;
		case 6 : level_add_ladder(&lvl, $3, $5); break;
		case 7 : level_add_bomb(&lvl, $3, $5); break;
		case 8 : level_add_life(&lvl, $3, $5); break;
		case 9 : level_add_key(&lvl, $3, $5, v_block.value); break;
		case 10 : level_add_gate(&lvl, $3, $5, v_block.value); break;
		case 11 : level_add_door(&lvl, $3, $5, v_block.value); break;
		case 12 : level_add_start(&lvl, $3, $5); break;
		case 13 : level_add_exit(&lvl, $3, $5); break;
		default : break;
	}
};

ITEM: robot { v_block = (block_t){1, 0}; }
	| probe { v_block = (block_t){2, 0}; }
	| empty { v_block = (block_t){3, 0}; }
	| block { v_block = (block_t){4, 0}; }
	| trap { v_block = (block_t){5, 0}; }
	| ladder { v_block = (block_t){6, 0}; }
	| bomb { v_block = (block_t){7, 0}; }
	| life { v_block = (block_t){8, 0}; }
	| key '(' integer ')' {
		if ($3 < 1 || $3 > 4)
			yyerror("Invalid key value (must be between 1 and 4).");
		v_block = (block_t){9, $3};
	}
	| gate '(' integer ')' {
		if ($3 < 1 || $3 > 4)
			yyerror("Invalid gate value (must be between 1 and 4).");
		v_block = (block_t){10, $3};
	}
	| door '(' integer ')' {
		if ($3 < 1 || $3 > 99)
			yyerror("Invalid door value (must be between 1 and 99).");
		v_block = (block_t){11, $3};
	}
	| start { v_block = (block_t){12, 0}; }
	| exite { v_block = (block_t){13, 0}; }
	;

%%

