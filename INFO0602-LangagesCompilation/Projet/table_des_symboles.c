
#include "table_des_symboles.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @return Une nouvelle liste de symboles vide.
*/
symbol_list newSymbolList() {
	symbol_list list = {0, NULL};
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
 * @brief Calcule une valeur de hachage pour un char*. (Utilisé pour la table de symboles)
 * 
 * @param name Le nom à hacher.
 * 
 * @return La valeur de hachage en int.
*/
int hashSymbol(char* name) {

	// Si le symbole n'a pas de nom, on retourne 0
	if (name == NULL)
		return 0;

	// Initialisation de la valeur de hachage
	int hash = 0;

	// Calcul de la valeur de hachage
	int i = 0, multiplier = 1;
	while (name[i] != '\0') {
		hash += name[i] * multiplier;
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
 * @return Pointeur vers le symbole ajouté, NULL si l'allocation mémoire a échoué.
*/
struct symbol_t* addSymbolInTable(struct symbol_t symbol, struct table_des_symboles_t *table) {
	int m = hashSymbol(symbol.name) % table->size;

	// On ajoute à la tête de la liste
	symbol_list_element* element = newSymbolListElement(symbol);
	if (element == NULL)
		return NULL;
	element->next = table->data[m].head;
	table->data[m].head = element;

	// On incrément le nombre de symboles dans la table
	table->data[m].count++;
	table->total_symbol_count++;

	// Retour
	return &element->symbol;
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
	int m = hashSymbol(symbol.name) % table->size;

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

/**
 * @brief Cherche un symbole dans la table de symboles en fonction de son nom.
 * 
 * @param name Le nom du symbole à chercher.
 * @param table La table de symboles dans laquelle chercher le symbole.
 * 
 * @return Pointeur sur le symbole trouvé, NULL si le symbole n'a pas été trouvé.
*/
struct symbol_t* getSymbolFromTable(char* name, struct table_des_symboles_t *table) {

	// On calcule la valeur de hachage
	int m = hashSymbol(name) % table->size;

	// On parcourt la liste
	symbol_list_element* element = table->data[m].head;
	while (element != NULL) {

		// Si le symbole est trouvé, on le retourne
		int cmp = strcmp(element->symbol.name, name);
		if (cmp == 0)
			return &element->symbol;

		// On passe à l'élément suivant
		element = element->next;
	}

	// Retour
	return NULL;
}

/**
 * @brief Supprime tous les symboles de la table de symboles à une certaine profondeur.
 * 
 * @param table La table de symboles à vider.
*/
void removeSymbolDepth(int depth, struct table_des_symboles_t *table) {
	
	// On parcourt la table de symboles
	int i;
	for (i = 0; i < table->size; i++) {

		// On parcourt la liste
		symbol_list_element* element = table->data[i].head;
		symbol_list_element* previous = NULL;
		while (element != NULL) {

			// Si le symbole est trouvé, on le supprime
			if (element->symbol.depth >= depth) {

				// Si c'est le premier élément de la liste
				if (previous == NULL)
					table->data[i].head = element->next;
				else
					previous->next = element->next;

				// On libère la mémoire
				freeSymbole(&element->symbol);
				free(element);

				// On décrémente le nombre de symboles dans la table
				table->data[i].count--;
				table->total_symbol_count--;

				// On passe à l'élément suivant
				if (previous == NULL)
					element = table->data[i].head;
				else
					element = previous->next;
			}
			else {
				// On passe à l'élément suivant
				previous = element;
				element = element->next;
			}
		}
	}
}


/**
 * @brief Génère une chaîne de caractères représentant la table de symboles.
 * 
 * @param table La table de symboles à représenter.
 * 
 * @return La chaîne de caractères représentant la table de symboles.
*/
char* tableDesSymbolesToString(struct table_des_symboles_t table) {
	
	// Initialisation de la chaîne de caractères
	char* string = malloc(sizeof(char) * 8096);
	if (string == NULL) {
		perror("tableDesSymbolesToString: Erreur d'allocation mémoire");
		exit(EXIT_FAILURE);
	}
	string[0] = '\0';

	// On parcourt la table de symboles
	int i;
	for (i = 0; i < table.size; i++) {
		
		// Si la liste est vide, on passe à la suivante
		if (table.data[i].count == 0)
			continue;

		// On concatène la chaîne de caractères avec le numéro de la liste
		strcat(string, "- ");

		// On parcourt la liste
		symbol_list_element* element = table.data[i].head;
		while (element != NULL) {

			// On concatène la chaîne de caractères
			char* symbol_string = symboleToString(element->symbol);
			strcat(string, symbol_string);
			strcat(string, ", ");
			free(symbol_string);

			// On passe à l'élément suivant
			element = element->next;
		}

		// On concatène la chaîne de caractères avec le nombre de symboles et un retour à la ligne
		char symbol_count_string[32];
		sprintf(symbol_count_string, "(%d symboles)\n", table.data[i].count);
		strcat(string, symbol_count_string);
	}

	// On concatène la chaîne de caractères avec le nombre total de symboles
	char total_symbol_count_string[32];
	sprintf(total_symbol_count_string, "Nombre total de symboles : %ld", table.total_symbol_count);
	strcat(string, total_symbol_count_string);

	// Retour
	return string;
}

/**
 * @brief Libère la mémoire allouée pour la table de symboles (profondément).
 * 
 * @param table La table de symboles à libérer.
 * 
 * @return -1 si erreur, 0 sinon.
*/
int freeTableDesSymboles(struct table_des_symboles_t *table) {
	
	// On parcourt la table de symboles
	int i;
	for (i = 0; i < table->size; i++) {

		// On parcourt la liste
		symbol_list_element* element = table->data[i].head;
		while (element != NULL) {

			// On libère la mémoire
			if (freeSymbole(&element->symbol) == -1)
				return -1;
			symbol_list_element* next = element->next;
			free(element);

			// On passe à l'élément suivant
			element = next;
		}
	}

	// On libère la mémoire
	free(table->data);

	// Retour
	return 0;
}
