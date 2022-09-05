
#include "ListeEntier.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * Permet de vérifier si la liste est vide
**/
int estVide(ELEMENT l) {
	return !l[0].next;
}

/**
 * Renvoie un index libre dans la liste
 * Sa deuxième définition permet de commencer à partir d'un indice
**/
int elementLibre(ListeEntier *l) {
	int i;
	for (i=1; i <= l->Size && l->List[i].next != -1; i++);
	return i;
}
int elementLibre2(ListeEntier *l, int i) {
	for (; i <= l->Size && l->List[i].next != -1; i++);
	return i;
}

/**
 * Permet de vérifier si la liste est pleine
**/
int estPleine(ListeEntier *l) {
	return (elementLibre(l) > l->Size);
}

/**
 * Créer une liste vide de la taille souhaitée
**/
ListeEntier createList(int taille) {
	ListeEntier L;
	ELEMENT list = (ELEMENT) malloc(sizeof(Element) * (taille+1) );
	int i;
	list[0].next = 0;
	list[0].value = 0;
	list[0].occurences = 0;
	for (i = 1; i <= taille; i++)
		list[i].value = list[i].occurences = list[i].next = -1;
	L.List = list;
	L.Size = taille;
	return L;
}

/**
 * Créer une liste à partir d'une liste de valeurs
 * Ex : {5,3,2,2,2,5,1,3,4}
**/
ListeEntier createListFromList(int values[], int taille) {
	ListeEntier L = createList(taille);
	int i;
	for (i = 0; i < taille; i++)
		insert(values[i], &L);
	return L;
}

/**
 * Créer une liste vide de la taille souhaitée
**/
ListeEntier increaseListLength(ListeEntier *l) {
	ListeEntier newList = createList(l->Size+1);
	int i;
	for (i = 0; i <= l->Size; i++) {
		newList.List[i].value = l->List[i].value;
		newList.List[i].occurences = l->List[i].occurences;
		newList.List[i].next = l->List[i].next;
	}
	newList.List[i].value = newList.List[i].occurences = newList.List[i].next = -1;

	free(l->List);
	return newList;
}


/**
 * Affiche les valeurs de la liste
**/
void printListValues(ListeEntier *l) {
	if (estVide(l->List)) {
		printf("\nLa liste est vide");
		return;
	}
	int i;
	printf("\nLa liste contient les valeurs suivantes : ");
	for (i = l->List[0].next; l->List[i].next; i = l->List[i].next)
		printf("%d (x%d), ", l->List[i].value, l->List[i].occurences);
	printf("%d (x%d)", l->List[i].value, l->List[i].occurences);
}

/**
 * Affiche la structure de la liste
**/
void printListStruct(ListeEntier *l) {
	int i;
	printf("\nSize : %d\n[",l->Size);
	for (i = 0; i < l->Size; i++)
		printf("%d, ", l->List[i].value);
	printf("%d] Values\n", l->List[i].value);
	printf("[");
	for (i = 0; i < l->Size; i++)
		printf("%d, ", l->List[i].occurences);
	printf("%d] Occurences\n", l->List[i].occurences);
	printf("[");
	for (i = 0; i < l->Size; i++)
		printf("%d, ", l->List[i].next);
	printf("%d] Next Index\n", l->List[i].next);
}

/**
 * Cherche la valeur dans une liste donnée avec plusieurs comportement.
 * @return vrai lorsque de la valeur est trouvée, posX prend la position de la valeur et prePos la position avant
 * @return faux dans le cas contraire, posX à -1 et prePos à 0
**/
int chercher(int x, ELEMENT l, int *posX, int *prePos) {
	*posX = -1;
	*prePos = 0;
	if (estVide(l))
		return 0;
	int i;
	for (i = 0; x > l[i].value && l[i].next; *prePos = i, i = l[i].next) {
		if (x == l[i].value) {
			*posX = i;
			return 1;
		}
	}
	if (x == l[i].value) {
		*posX = i;
		return 1;
	}
	if (x > l[i].value)
		for (; l[*prePos].next != 0; *prePos = l[*prePos].next);
	return 0;
}

/**
 * Ajoute un élement à la liste
 * Exemple de liste :
 * [  , 2, 8, 9,-1,-1,-1] Valeur
 * [  , 1, 1, 2,-1,-1,-1] Occurences
 * [ 2, 3, 1, 0,-1,-1,-1] Index suivant
**/
void insert(int x, ListeEntier *l) {
	int posX, prePos;
	// Augmenter l'occurence si la valeur est trouvée
	if (chercher(x, l->List, &posX, &prePos)) {
		//printf("\nLe nombre d'occurences de la valeur %d a bien ete augmentee", x);
		l->List[posX].occurences++;
		return;
	}
	// Sinon,
	posX = elementLibre(l);
	// Aggrandir la liste est si elle est pleine
	if (posX > l->Size)
		(*l) = increaseListLength(l);
	// Ajouter la valeur
	l->List[posX].value = x;
	l->List[posX].occurences = 1;
	l->List[posX].next = l->List[prePos].next;
	l->List[prePos].next = posX;
}

/**
 * Permet d'insérer plusieurs valeurs d'un seul coup
**/
void insertListe(ListeEntier* l, int values[], int taille) {
	int i;
	for (i = 0; i < taille; i++)
		insert(values[i], l);
}


/**
 * Enlève une occurence au i-ème élement de la liste
**/
void supprimer(int k, ListeEntier *l) {
	int i, prePos;
	for (i = prePos = 0; k > 0 && l->List[i].next; k--, prePos = i, i = l->List[i].next);
	// Si la position est trouvée :
	if (k == 0) {
		// Réduire l'occurence si possible
		if (l->List[i].occurences > 1)
			l->List[i].occurences--;
		// Sinon, supprimer l'élément
		else {
			l->List[prePos].next = l->List[i].next;
			l->List[i].value = l->List[i].occurences = l->List[i].next = -1;
		}
	}
	// Si la position n'est pas trouvée, afficher un message d'erreur
	else
		printf("\nSuppression impossible, l'indice est en dehors de la liste");
}

/**
 * Compacte la liste en déplaçant les cases du tableau libre vers la fin de celui-ci.
**/
void compacterListe(ListeEntier *l) {
	int i, j, prePos;
	for (i = 1, j = 2; i < l->Size; i++, j++) {
		// Si l'index actuel est libre mais pas le prochain, alors le déplacer.
		if (l->List[i].next == -1 && l->List[j].next != -1) {
			Element e = l->List[i];
			l->List[i] = l->List[j];
			l->List[j] = e;
			// Retrouver le précedeur de l'index à déplacer
			for (prePos = 0; l->List[prePos].next != j; prePos = l->List[prePos].next);
			l->List[prePos].next = i;
		}
	}
}

/**
 * Compacte la liste en créant une copie ordonnée par ordre croissant.
**/
void compacterListeV2(ListeEntier *l) {
	ListeEntier newListe = createList(l->Size);
	while (!estVide(l->List)) {
		insert(l->List[l->List[0].next].value, &newListe);
		supprimer(1, l);
	}
	free(l->List);
	l->List = newListe.List;
}

/**
 * Compacte la liste en déplaçant les cases du tableau livre vers la fin de celui-ci
 * de manière récursive.
**/
void compacterListeRecursif(ListeEntier *l, int i) {
	int j = elementLibre2(l,i-1);
	// Si l'index actuel est libre mais pas le prochain, alors le déplacer.
	if (j == i-1 && l->List[i].next != -1 && l->List[j].next == -1) {
		Element e = l->List[i];
		l->List[i] = l->List[j];
		l->List[j] = e;
		// Retrouver le précedeur de l'index à déplacer
		int prePos;
		for (prePos = 0; l->List[prePos].next != i; prePos = l->List[prePos].next);
		l->List[prePos].next = j;
	}
	if (i < l->Size)
		compacterListeRecursif(l, i+1);
}







