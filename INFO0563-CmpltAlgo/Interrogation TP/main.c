
#include "ListeEntier.h"
#include <stdlib.h>
#include <stdio.h>

int main() {
	fprintf(stderr,"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	fprintf(stderr,"Debut de la fonction main()");

	fprintf(stderr,"\n----------1) Création de liste de 25 éléments---------\n");
	ListeEntier l = createList(25);

	fprintf(stderr,"\n----------2) Insertion d'une liste de valeur---------\n");
	int values[] = {10, 25, 8, 12, 4, 17, 33, 5, 18, 3, 7, 40, 15, 6, 19, 30, 20, 29, 63, 50, 35, 22, 42, 13};
	int size = sizeof(values)/sizeof(values[0]);
	insertListe(&l, values, size);
	printListValues(l);
	printListStruct(l);

	fprintf(stderr,"\n----------3) Que prévois le programme lors de l'insertion de 47 et 21 ?---------\n");
	insert(47, &l);
	fprintf(stderr,"\n--- L'insertion de 47 se fera sans aucun problème car il reste une place de");
	fprintf(stderr,"\n--- libre dans la liste. Elle va donc se ranger dans la dernière colonne\n");
	printListStruct(l);

	insert(21, &l);
	fprintf(stderr,"--- L'insertion de 21 se fera différement car il ne reste plus aucune place de");
	fprintf(stderr,"\n--- libre dans la liste. Elle va donc aggrandir la liste et s'insérer en suite\n");
	printListStruct(l);

	fprintf(stderr,"\n----------4) Supprimez la 9eme valeur et afficher la liste---------\n");
	fprintf(stderr,"\n--- La 9eme valeur a été supprimée de la liste, elle était positionnée à l'index 23\n");
	supprimer(9, &l);
	printListStruct(l);

	fprintf(stderr,"\n----------5) Ajouter la valeur 21 dans votre liste et affichez---------\n");
	fprintf(stderr,"\n--- Etant donné que la valeur est déjà présente dans la liste, l'occurence a été incrémentée\n");
	insert(21, &l);
	printListStruct(l);

	fprintf(stderr,"\n----------6) Supprimez les 22e, 8e, 15e, 4e et encore 22e valeurs. Comment réagit votre programme---------\n");
	fprintf(stderr,"\n--- Suppression 22 :");
	supprimer(22, &l);
	printListStruct(l);
	fprintf(stderr,"\n--- Suppression 8 :");
	supprimer(8, &l);
	printListStruct(l);
	fprintf(stderr,"\n--- Suppression 15 :");
	supprimer(15, &l);
	printListStruct(l);
	fprintf(stderr,"\n--- Suppression 4 :");
	supprimer(4, &l);
	printListStruct(l);
	fprintf(stderr,"\n--- Suppression 22 :");
	supprimer(22, &l);
	printListStruct(l);
	fprintf(stderr,"--- La suppression de la 22ème valeur est impossible, le programme réagit donc en répondant que l'indice est en dehors de la liste\n");

	fprintf(stderr,"\n----------7) Ordonnez un compactage de votre liste et affichez le résultat---------");
	fprintf(stderr,"\n--- Avant :");
	printListStruct(l);
	compacterListe(&l);
	fprintf(stderr,"\n--- Après :");
	printListStruct(l);


#define BONUS 1
#if BONUS == 1
	fprintf(stderr,"\n----------8) (Bonus que j'ai inventé) Compacter la liste tout en la triant en ordre croissant---------");
	fprintf(stderr,"\n--- Avant :");
	printListStruct(l);
	compacterListeV2(&l);
	fprintf(stderr,"\n--- Après :");
	printListStruct(l);
#endif

	fprintf(stderr,"\nFin de la fonction main()\n");
	return 0;
}


