
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "symbol.h"

/**
 * @brief Convertit un symbole en chaîne de caractères
 * 
 * @param symbole Le symbole à convertir
 * 
 * @return La chaîne de caractères correspondant au symbole
*/
char* symboleToString(symbol_t symbole) {
	char* str = malloc(100 * sizeof(char));
	if (str == NULL) {
		fprintf(stderr,"symboleToString: malloc failed\n");
		return NULL;
	}

	// Convert the name
	sprintf(str,"%s = ",symbole.name);

	// Convert the data
	char tmp[100];
	switch (symbole.type) {
		case SYMBOL_TYPE_INTEGER: sprintf(tmp, "%d", symbole.data.i); break;
		case SYMBOL_TYPE_DOUBLE: sprintf(tmp, "%f", symbole.data.d); break;
		case SYMBOL_TYPE_FLOAT: sprintf(tmp, "%f", symbole.data.f); break;
		case SYMBOL_TYPE_CHAR: sprintf(tmp, "%c", symbole.data.c); break;
		case SYMBOL_TYPE_STRING: sprintf(tmp, "%s", symbole.data.s); break;
		case SYMBOL_TYPE_LONG: sprintf(tmp, "%ld", symbole.data.l); break;
		case SYMBOL_TYPE_POINTER: sprintf(tmp, "%p", symbole.data.p); break;
		default: fprintf(stderr,"symboleToString: unknown symbole type\n"); return NULL;
	}
	strcat(str, tmp);

	return str;
}

/**
 * Libère la mémoire allouée pour un symbole
 * 
 * @param symbole Le symbole à libérer
 * 
 * @return 0 si la libération s'est bien passée, -1 sinon
*/
int freeSymbole(symbol_t *symbole) {
	fprintf(stderr,"freeSymbole()\n");
	if (symbole == NULL) {
		fprintf(stderr,"freeSymbole: parameter symbole is NULL\n");
		return -1;
	}
	fprintf(stderr,"freeSymbole: freeing symbole %s\n", symbole->name);

	// Free the name
	free(symbole->name);

	// Free the data if needed
	if (symbole->type == SYMBOL_TYPE_STRING) {
		free(symbole->data.s);
	}
	else if (symbole->type == SYMBOL_TYPE_POINTER) {
		free(symbole->data.p);
	}

	fprintf(stderr,"freeSymbole: done\n");
	return 0;
}

