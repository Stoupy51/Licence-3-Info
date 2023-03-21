
#ifndef __table_des_symboles_h__
#define __table_des_symboles_h__

#include "symbol.h"

// Structure d'un élément de liste chaînée de symboles
typedef struct linked_symbol_list_element_t {
	struct symbol_t symbol;
	struct linked_symbol_list_element_t *next;
} symbol_list_element;

// Structure d'une liste chaînée de symboles
typedef struct linked_symbol_list_t {
	int count;
	struct linked_symbol_list_element_t *head;
} symbol_list;

#define TABLE_SIZE 128

// Structure d'une table de hachage de listes chaînées de symboles
typedef struct table_des_symboles_t {
	int size;
	struct linked_symbol_list_t *data;
	long total_symbol_count;
} symbol_table;

// Fonctions d'Initialisation
symbol_list newSymbolList();
symbol_list_element* newSymbolListElement(struct symbol_t symbol);
symbol_table newTableDesSymboles(int size);

// Fonctions de manipulation
int hashSymbol(struct symbol_t symbol);
int addSymbolInTable(struct symbol_t symbol, struct table_des_symboles_t *table);




#endif

