
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include "table_des_symboles.h"

#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define RESET "\033[0m"

extern int yyparse();
extern FILE *yyin;

struct table_des_symboles_t t_d_s;
struct symbol_t *symbol;

int main(int argc, char *argv[]) {
	if (argc != 2) {
		printf("Usage: %s <file>\n", argv[0]);
		return EXIT_FAILURE;
	}

	// File input
	FILE *file = fopen(argv[1], "r");
	if (file == NULL) {
		printf("Error: file not found\n");
		return EXIT_FAILURE;
	}
	yyin = file;

	// Set locale
	if(setlocale(LC_ALL, "") == NULL)
        printf("setlocale failed.\n");

	// Create table
	t_d_s = newTableDesSymboles(128);

    yyparse();
    return EXIT_SUCCESS;
}

