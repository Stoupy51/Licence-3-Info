
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

#include "table_des_symboles.h"

#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define RED "\033[1;31m"
#define RESET "\033[0m"

#define MAX_FILE_SIZE 1048576

extern int yyparse();
extern FILE *yyin;

char* outputFileName = NULL;
char* outputFileContent = NULL;
struct symbol_t *symbol;
symbol_table t_d_s;
int depth = 0;

/**
 * @brief Fonction main du programme, qui gère les arguments et appelle le parser.
 * 
 * @param argc Le nombre d'arguments.
 * @param argv Les arguments.
 * 
 * @return EXIT_SUCCESS si tout s'est bien passé, EXIT_FAILURE sinon.
*/
int main(int argc, char *argv[]) {
	// File input management if given as argument
	FILE *file;
	if (argc == 2) {
		file = fopen(argv[1], "r");
		if (file == NULL) {
			printf(RED"Error: file not found\n"RESET);
			exit(EXIT_FAILURE);
		}
		yyin = file;

		// Set output file name (file name + .out)
		outputFileName = malloc((strlen(argv[1]) + 5) * sizeof(char));
		strcpy(outputFileName, argv[1]);
		strcat(outputFileName, ".out");

		// Set output file content
		outputFileContent = malloc(MAX_FILE_SIZE * sizeof(char));
		memset(outputFileContent, '\0', MAX_FILE_SIZE);

		// print
		fprintf(stderr, YELLOW"File '%s' opened.\n"RESET, argv[1]);
		fprintf(stderr, YELLOW"Output file '%s' predicted.\n"RESET, outputFileName);
		fprintf(stderr, YELLOW"Output file content initialized : '%s'.\n"RESET, outputFileContent);
	}

	// Set locale
	if (setlocale(LC_ALL, "") == NULL)
		printf(RED"setlocale failed.\n"RESET);

	// Create table
	t_d_s = newTableDesSymboles(128);

	yyparse();

	// Print table
	printf("%s\n", tableDesSymbolesToString(t_d_s));

	// Free table
	freeTableDesSymboles(&t_d_s);

	// Close file if opened
	if (argc == 2)
		fclose(file);
	
	// Save output file
	if (outputFileName != NULL) {

		FILE *f = fopen(outputFileName, "w");
		if (f == NULL) {
			printf(RED"Error: could not create output file\n"RESET);
			exit(EXIT_FAILURE);
		}
		fprintf(f, "%s", outputFileContent);
		fclose(f);
		printf(YELLOW"Output file '%s' created.\n"RESET, outputFileName);
	}

	// Return
	return EXIT_SUCCESS;
}

