
#include "ListeEntier.h"
#include <stdlib.h>
#include <stdio.h>

int main() {
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("Debut de la fonction main()");

	ListeEntier Liste;
	Liste = createList(7);
	printListStruct(&Liste);
	insert(5, &Liste);
	printListStruct(&Liste);

	printf("\n----------Insertions---------\n");
	int values[] = {5,3,2,2,2,5,1,3,4};
	int size = sizeof(values)/sizeof(values[0]);
	insertListe(&Liste, values, size);
	printListValues(&Liste);
	printListStruct(&Liste);

	printf("\n----------Supprimer----------\n");
	supprimer(1, &Liste);
	supprimer(4, &Liste);
	printListValues(&Liste);
	printListStruct(&Liste);

	printf("\n----------Compacter----------\n");
	compacterListe(&Liste);
	printListValues(&Liste);
	printListStruct(&Liste);

	printf("\n---------Compacter V2--------\n");
	compacterListeV2(&Liste);
	printListValues(&Liste);
	printListStruct(&Liste);

	printf("\n---------Compacter Recursif--------\n");
	supprimer(2,&Liste);
	supprimer(2,&Liste);
	printListStruct(&Liste);
	compacterListeRecursif(&Liste, 1);
	printListValues(&Liste);
	printListStruct(&Liste);

	printf("\n---------Insertions 2--------\n");
	int values2[] = {7,8,6,1};
	insertListe(&Liste, values2, 4);
	printListValues(&Liste);
	printListStruct(&Liste);

	printf("\nFin de la fonction main()\n");
	return 0;
}


