
#include "Abr.h"
#include <stdlib.h>
#include <stdio.h>

int main() {
	fprintf(stderr,"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	fprintf(stderr,"Debut de la fonction main()");

	fprintf(stderr,"\n\n--------Test Arbre--------\n");
	int values[] = {15, 45, 12, 23, 58, 8, 20, 28, 47, 5, 10, 32, 53, 29, 49, 55};
	int size = sizeof(values) / sizeof(int);
	ABR a = create(40);
	addValuesList(&a, values, size);
	printAbr(&a);
	removeValue(&a, 8);
	printAbr(&a);


	fprintf(stderr,"\n\nFin de la fonction main()\n");
	return 0;
}


