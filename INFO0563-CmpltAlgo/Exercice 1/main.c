
#include "ListeEntier.h"
#include <stdlib.h>
#include <stdio.h>

int main() {
	fprintf(stderr,"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	fprintf(stderr,"Debut de la fonction main()");

	ListeEntier Liste;
	Liste = createList(7);
	printListStruct(&Liste);
	insert(5, &Liste);
	printListStruct(&Liste);

	fprintf(stderr,"\n----------Insertions---------\n");
	int values[] = {5,3,2,2,2,5,1,3,4};
	int size = sizeof(values)/sizeof(values[0]);
	insertListe(&Liste, values, size);
	printListValues(&Liste);
	printListStruct(&Liste);

	fprintf(stderr,"\n----------Supprimer----------\n");
	supprimer(1, &Liste);
	supprimer(4, &Liste);
	printListValues(&Liste);
	printListStruct(&Liste);

	fprintf(stderr,"\n----------Compacter----------\n");
	compacterListe(&Liste);
	printListValues(&Liste);
	printListStruct(&Liste);

	fprintf(stderr,"\n---------Compacter V2--------\n");
	compacterListeV2(&Liste);
	printListValues(&Liste);
	printListStruct(&Liste);

	fprintf(stderr,"\n---------Compacter Recursif--------\n");
	supprimer(2,&Liste);
	supprimer(2,&Liste);
	printListStruct(&Liste);
	compacterListeRecursif(&Liste, 1);
	printListValues(&Liste);
	printListStruct(&Liste);

	fprintf(stderr,"\n---------Insertions 2--------\n");
	int values2[] = {7,8,6,1};
	insertListe(&Liste, values2, 4);
	printListValues(&Liste);
	printListStruct(&Liste);
	compacterListeV2(&Liste);
	printListStruct(&Liste);

	fprintf(stderr,"\nFin de la fonction main()\n");
	return 0;
}


