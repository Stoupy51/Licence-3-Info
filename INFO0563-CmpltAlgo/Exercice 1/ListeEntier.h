
#ifndef __ListeEntier__
#define __ListeEntier__

/**
 * Structure d'un Element de la liste
**/
typedef struct element {
	int value,
		occurences,
		next;
} Element, *ELEMENT;

/**
 * Une liste doit être créée avec la fonction "createList(int taille)"
**/
typedef struct {
	int		Size;
	ELEMENT	List;
} ListeEntier;

int estVide(ELEMENT l);
int elementLibre(ListeEntier *l);
int estPleine(ListeEntier *l);
ListeEntier createList(int taille);
ListeEntier createListFromList(int values[], int taille);
ListeEntier increaseListLength(ListeEntier *l);
void printListValues(ListeEntier *l);
void printListStruct(ListeEntier *l);
int chercher(int x, ELEMENT l, int *posX, int *prePos);
void insert(int x, ListeEntier *l);
void insertListe(ListeEntier* L, int values[], int taille);
void supprimer(int k, ListeEntier *l);
void compacterListe(ListeEntier *l);
void compacterListeV2(ListeEntier *l);


#endif
