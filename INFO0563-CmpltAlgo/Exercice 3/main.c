
#include "Abr.h"
#include <stdlib.h>
#include <stdio.h>

int main() {
	fprintf(stderr,"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	fprintf(stderr,"Debut de la fonction main()");

	fprintf(stderr,"\n\n--------Test Arbre--------\n");
	int values[] = {20, 49, 12, 28, 45, 55, 10, 15, 23, 29, 40, 47, 53, 58, 5, 8};
	int size = sizeof(values) / sizeof(int);
	ABR a = create(32);
	fprintf(stderr,"\n(%d)\n",a->value);
	addValuesList(&a, values, size);
	//removeValue(&a, 8);
	printAbr(&a);


	fprintf(stderr,"\n\nFin de la fonction main()\n");
	return 0;
}


