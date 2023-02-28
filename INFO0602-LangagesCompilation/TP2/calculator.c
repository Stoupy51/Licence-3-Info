
#include <stdlib.h>
#include <stdio.h>

#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define RESET "\033[0m"

extern int yyparse();
extern FILE *yyin;

int main(int argc, char *argv[]) {
	printf(YELLOW "Enter a simple operation with integers and the operators '+' or '-' or '*' or '/'\n");
    printf("You must complete the operation with '.' then press CTRL+D\n" RESET);

	// File input
	if (argc == 2) {
		FILE *file = fopen(argv[1], "r");
		if (file == NULL) {
			printf("Error: file not found\n");
			return EXIT_FAILURE;
		}
		yyin = file;
	}

    yyparse();
    return EXIT_SUCCESS;
}

