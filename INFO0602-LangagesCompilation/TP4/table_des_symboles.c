
#include "table_des_symboles.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * @return Une nouvelle liste de symboles vide.
*/
symbol_list newSymbolList() {
	symbol_list list = {NULL, 0};
	return list;
}

/**
 * @param symbol Le symbole à stocker dans l'élément.
 * 
 * @return Un nouvel élément de liste de symboles.
*/
symbol_list_element* newSymbolListElement(struct symbol_t symbol) {

	// Allocation mémoire
	symbol_list_element* element = malloc(sizeof(symbol_list_element));
	if (element == NULL) {
		perror("newSymbolListElement: Erreur d'allocation mémoire");
		exit(EXIT_FAILURE);
	}

	// Initialisation et retour
	element->symbol = symbol;
	element->next = NULL;
	return element;
}

/**
 * @brief Créer et initialise une nouvelle table de symboles.
 * 
 * @param size La taille de la table de hachage de symboles.
 * 
 * @return La table de symboles initialisée.
*/
symbol_table newTableDesSymboles(int size) {

	// Initialisation de quelques valeurs de la table
	symbol_table table;
	table.size = size;
	table.total_symbol_count = 0;

	// Allocation mémoire
	table.data = malloc(sizeof(symbol_list) * size);
	if (table.data == NULL) {
		perror("newTableDesSymboles: Erreur d'allocation mémoire");
		exit(EXIT_FAILURE);
	}

	// Initialisation des listes de symboles
	int i;
	for (i = 0; i < size; i++)
		table.data[i] = newSymbolList();
	
	// Retour de la table de symboles
	return table;
}

/**
 * @brief Calcule une valeur de hachage pour un symbole. (Utilisé pour la table de symboles)
 * 
 * @param symbol Le symbole à hacher.
 * 
 * @return La valeur de hachage du symbole en int.
*/
int hashSymbol(struct symbol_t symbol) {
	
	// Si le symbole n'a pas de nom, on retourne 0
	if (symbol.name == NULL)
		return 0;

	// Initialisation de la valeur de hachage
	int hash = 0;

	// Calcul de la valeur de hachage
	int i, multiplier = 1;
	while (symbol.name[i] != '\0') {
		hash += symbol.name[i] * multiplier;
		multiplier *= 256;
		i++;
	}

	// Retour de la valeur de hachage
	return hash;
}

/**
 * @brief Ajoute un symbole à la table de symboles.
 * 
 * @param symbol Le symbole à ajouter.
 * @param table La table de symboles à laquelle ajouter le symbole.
 * 
 * @return 0 si le symbole a été ajouté, -1 si erreur.
*/
int addSymbolInTable(struct symbol_t symbol, struct table_des_symboles_t *table) {
	int m = hashSymbol(symbol) % table->size;

	// On ajoute à la tête de la liste
	symbol_list_element* element = newSymbolListElement(symbol);
	if (element == NULL)
		return -1;
	element->next = table->data[m].head;
	table->data[m].head = element;

	// On incrément le nombre de symboles dans la table
	table->data[m].count++;
	table->total_symbol_count++;

	// Retour
	return 0;
}

/**
 * @brief Supprime un symbole de la table de symboles.
 * 
 * @param symbol Le symbole à supprimer.
 * @param table La table de symboles de laquelle supprimer le symbole.
 * 
 * @return 0 si le symbole a été supprimé, -1 si le symbole n'a pas été trouvé.
*/
int removeSymbolFromTable(struct symbol_t symbol, struct table_des_symboles_t *table) {
	int m = hashSymbol(symbol) % table->size;

	// On parcourt la liste
	symbol_list_element* element = table->data[m].head;
	symbol_list_element* previous = NULL;
	while (element != NULL) {

		// Si le symbole est trouvé, on le supprime (Fonctionne car même pointeur)
		if (element->symbol.name == symbol.name) {

			// Si c'est le premier élément de la liste
			if (previous == NULL)
				table->data[m].head = element->next;
			else
				previous->next = element->next;

			// On libère la mémoire
			freeSymbole(&symbol);
			free(element);

			// On décrémente le nombre de symboles dans la table
			table->data[m].count--;
			table->total_symbol_count--;

			// Retour
			return 0;
		}

		// On passe à l'élément suivant
		previous = element;
		element = element->next;
	}

	// Retour
	return -1;
}

