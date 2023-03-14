
#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

/**
 * @brief Fonction testant la librairie tree et symbole
 * 
 * @return 0 si le test s'est bien passé, -1 sinon
*/
int main() {
	int c = 1;

	// Création d'un symbole
	symbole_t symbole = {
		.name = "symbole test",
		.type = SYMBOL_TYPE_INTEGER,
		.data.i = 42
	};
	fprintf(stderr,"[%d] Symbole created : %s\n", c++, symboleToString(symbole));

	// Création d'un élément d'arbre
	tree_value_t val = { .symbole = symbole };
	tree_t element = createTree(TREE_TYPE_SYMBOLE, val);
	fprintf(stderr,"[%d] Tree created : %s\n", c++, treeToString(element));

	// Ajout de plusieurs nouveeaux éléments à la liste
	treeListAdd(&element.childs, (tree_t) {
		.type = TREE_TYPE_FUNCTION,
		.value = { .function = "f" },
	});
	fprintf(stderr,"[%d] Tree added element : %s\n", c++, treeToString(element));
	treeListAdd(&element.childs, (tree_t) {
		.type = TREE_TYPE_OPERATOR,
		.value = { .operator_char = '+' },
	});
	fprintf(stderr,"[%d] Tree added element : %s\n", c++, treeToString(element));
	treeListAdd(&element.childs, (tree_t) {
		.type = TREE_TYPE_INTEGER,
		.value = { .integer = 42 },
	});
	fprintf(stderr,"[%d] Tree added element : %s\n", c++, treeToString(element));

	// Suppression de la liste d'éléments d'arbre
	freeTreeList(&element.childs);
	fprintf(stderr, "[%d] Tree list freed\n", c++);

	return 0;
}

