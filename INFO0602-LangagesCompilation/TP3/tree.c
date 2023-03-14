
#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

/**
 * Crée un élément d'arbre
 * 
 * @param type Le type de l'élément
 * @param value La valeur de l'élément (union de : un entier, un opérateur, une fonction, un symbole)
 * 
 * @return L'élément créé
*/
tree_t createTreeElement(tree_type_t type, tree_value_t value) {
	tree_t element;
	element.type = type;
	element.value = value;
	return element;
}

/**
 * Crée une liste d'éléments d'arbre
 * 
 * @return La liste d'éléments d'arbre créée
*/
tree_list_t createTreeList() {
	tree_list_t list;
	list.size = 0;
	list.head = NULL;
	return list;
}

/**
 * Ajoute un élément à la liste d'éléments d'arbre
 * 
 * @param list La liste d'éléments d'arbre
 * @param element L'élément à ajouter
 * 
 * @return 0 si l'ajout s'est bien passé, -1 sinon
*/
int treeListAdd(tree_list_t *list, tree_t element) {
	if (list == NULL) {
		fprintf(stderr,"treeListAdd: parameter list is NULL\n");
		return -1;
	}

	// Malloc and copy the element
	tree_t *newElement = malloc(sizeof(tree_t));
	if (newElement == NULL) {
		fprintf(stderr,"treeListAdd: malloc failed\n");
		return -1;
	}
	*newElement = element;

	// Add the element to the list (at the front)
	newElement->next = list->head;
	list->head = newElement;
	list->size++;

	return 0;
}

/**
 * Libère la mémoire allouée pour une liste d'éléments d'arbre
 * 
 * @param list La liste d'éléments d'arbre
 * 
 * @return 0 si la libération s'est bien passée, -1 sinon
*/
int freeTreeList(tree_list_t *list) {
	if (list == NULL) {
		fprintf(stderr,"freeTreeList: parameter list is NULL\n");
		return -1;
	}

	// Free all elements
	tree_t *current = list->head;
	while (current != NULL) {
		tree_t *next = current->next;
		freeTreeElement(current);
		current = next;
	}

	// Reset the list
	list->size = 0;
	list->head = NULL;

	return 0;
}

/**
 * Libère la mémoire allouée pour un élément d'arbre
 * 
 * @param element L'élément d'arbre
 * 
 * @return 0 si la libération s'est bien passée, -1 sinon
*/
int freeTreeElement(tree_t *element) {
	if (element == NULL) {
		fprintf(stderr,"freeTreeElement: parameter element is NULL\n");
		return -1;
	}

	// Free the childs
	freeTreeList(&element->childs);

	// Free the element value if needed (only for symbol and function)
	if (element->type == TREE_TYPE_SYMBOL) {
		freeSymbole(&element->value.symbol);
	}
	else if (element->type == TREE_TYPE_FUNCTION) {
		free(element->value.function);
	}

	return 0;
}

