
#include <stdio.h>
#include <stdlib.h>

#include "symbole.h"

/**
 * Libère la mémoire allouée pour un symbole
 * 
 * @param symbole Le symbole à libérer
 * 
 * @return 0 si la libération s'est bien passée, -1 sinon
*/
int freeSymbole(symbole_t *symbole) {
	if (symbole == NULL) {
		fprintf(stderr,"freeSymbole: parameter symbole is NULL\n");
		return -1;
	}

	// Free the name
	free(symbole->name);

	// Free the data if needed
	if (symbole->type == SYMBOL_TYPE_STRING) {
		free(symbole->data.s);
	}
	else if (symbole->type == SYMBOL_TYPE_POINTER) {
		free(symbole->data.p);
	}

	return 0;
}

