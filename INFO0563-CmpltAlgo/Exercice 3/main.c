
#include "Abr.h"
#include <stdlib.h>
#include <stdio.h>

int main() {
	fprintf(stderr,"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	fprintf(stderr,"Debut de la fonction main()");

	fprintf(stderr,"\n\n--------Test Arbre remove + add--------\n");
	int values[] = {20, 49, 12, 28, 45, 55, 8, 15 , 23, 29, 40, 47, 53, 58, 5, 10};
	int size = sizeof(values) / sizeof(int);
	ABR a = create(32);
	addValuesList(&a, values, size);
	printAbr(a);
	removeValue(&a, 8);
	printAbr(a);

	fprintf(stderr,"\n\n--------Test Equilibrage--------\n");
	int values2[] = {15, 60, 12, 23, 58, 8, 20, 28, 47, 53, 49, 55};
	int size2 = sizeof(values2) / sizeof(int);
	ABR b = create(40);
	addValuesList(&b, values2, size2);
	printAbr(b);
	balance(&b);
	printAbr(b);

	fprintf(stderr,"\n\n--------Test Equilibrage parfait--------\n");
	int values3[] = {15, 45, 12, 23, 58, 8, 20, 28, 47, 5, 10, 32, 53, 29, 49, 55};
	int size3 = sizeof(values3) / sizeof(int);
	ABR c = create(40);
	addValuesList(&c, values3, size3);
	printAbr(c);
	perfectBalance(&c);
	printAbr(c);


	fprintf(stderr,"\n\nFin de la fonction main()\n");
	return 0;
}


