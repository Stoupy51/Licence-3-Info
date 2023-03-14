
#ifndef __tree_h__
#define __tree_h__

#include "symbole.h"

// Les expressions sont formées d'entiers (pour les noeuds),
// d'opérateurs, de fonctions, de symboles (pour les variables)
typedef enum tree_type_t {
	TREE_TYPE_INTEGER = 0,
	TREE_TYPE_OPERATOR = 1,
	TREE_TYPE_FUNCTION = 2,
	TREE_TYPE_SYMBOL = 3
} tree_type_t;

// Union des différents types de valeurs
typedef union tree_value_t {
	int integer;
	char operator_char;
	char* function;
	symbole_t symbol;
} tree_value_t;

// Élement d'arbre
typedef struct tree_t {
	tree_type_t type;
	tree_value_t value;

	// Next element in a chained list
	struct tree_t *next;

	// List of childs
	struct tree_list_t childs;
} tree_t;

// Liste d'éléments d'arbre
typedef struct tree_list_t {
	int size;
	tree_t *head;
} tree_list_t;

tree_t createTreeElement(tree_type_t type, tree_value_t value);
tree_list_t createTreeList();

int treeListAdd(tree_list_t *list, tree_t element);

int freeTreeList(tree_list_t *list);
int freeTreeElement(tree_t *element);

#endif

