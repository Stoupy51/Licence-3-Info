
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tree.h"

/**
 * Crée un élément d'arbre
 * 
 * @param type Le type de l'élément
 * @param value La valeur de l'élément (union de : un entier, un opérateur, une fonction, un symbole)
 * 
 * @return L'élément créé
*/
tree_t createTree(tree_type_t type, tree_value_t value) {
	tree_t element;
	element.type = type;
	element.value = value;
	element.next = NULL;
	element.childs = createTreeList();
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
 * @brief Convertit un arbre en chaîne de caractères
 * 
 * @param tree L'arbre à convertir
 * 
 * @return La chaîne de caractères représentant l'arbre
*/
char* treeToString(tree_t tree) {
	char* str = malloc(sizeof(char) * 1000);
	if (str == NULL) {
		fprintf(stderr,"treeToString: malloc failed\n");
		return NULL;
	}

	// Convert the tree to a string
	switch (tree.type) {
		case TREE_TYPE_INTEGER: sprintf(str, "%d:", tree.value.integer); break;
		case TREE_TYPE_OPERATOR: sprintf(str, "%c:", tree.value.operator_char); break;
		case TREE_TYPE_FUNCTION: sprintf(str, "%s:", tree.value.function); break;
		case TREE_TYPE_SYMBOLE: sprintf(str, "%s:", symboleToString(tree.value.symbole)); break;
		default: fprintf(stderr,"treeToString: unknown tree type\n"); return NULL;
	}

	// Add the childs to the string
	strcat(str, " [");
	tree_t *current = tree.childs.head;
	while (current != NULL) {
		char* childStr = treeToString(*current);
		strcat(str, childStr);
		strcat(str, ", ");
		free(childStr);
		current = current->next;
	}

	// Remove the last ", " if there is one
	if (tree.childs.size > 0) {
		str[strlen(str) - 2] = '\0';
	}
	strcat(str, "]");

	return str;
}

/**
 * Libère la mémoire allouée pour une liste d'éléments d'arbre
 * 
 * @param list La liste d'éléments d'arbre
 * 
 * @return 0 si la libération s'est bien passée, -1 sinon
*/
int freeTreeList(tree_list_t *list) {
	fprintf(stderr,"freeTreeList()\n");
	if (list == NULL) {
		fprintf(stderr,"freeTreeList: parameter list is NULL\n");
		return -1;
	}

	// Free all elements
	tree_t *current = list->head;
	while (current != NULL) {
		tree_t *next = current->next;
		if (freeTreeElement(current) == -1) {
			fprintf(stderr,"freeTreeList: freeTreeElement failed\n");
			return -1;
		}
		current = next;
	}

	// Reset the list
	list->size = 0;
	list->head = NULL;

	fprintf(stderr,"freeTreeList: free done\n");
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
	fprintf(stderr,"freeTreeElement()\n");
	if (element == NULL) {
		fprintf(stderr,"freeTreeElement: parameter element is NULL\n");
		return -1;
	}
	fprintf(stderr, "freeTreeElement: Free of %s\n", treeToString(*element));

	// Free the childs
	if (element->childs.size > 0)
		freeTreeList(&element->childs);

	// Free the element value if needed (only for symbol)
	if (element->type == TREE_TYPE_SYMBOLE) {
		freeSymbole(&element->value.symbole);
	}

	fprintf(stderr, "freeTreeElement: free of %p done\n", element);
	return 0;
}

