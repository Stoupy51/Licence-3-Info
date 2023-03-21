
#ifndef __symbol_h__
#define __symbol_h__

typedef enum symbol_type_t {
	SYMBOL_TYPE_INTEGER = 0,
	SYMBOL_TYPE_STRING = 1,
	SYMBOL_TYPE_POINTER = 2
} symbol_type_t;

#define MAX_NAME 64
typedef union symbol_data_t {
	int i;
	char s[MAX_NAME];
	void* p;
} symbol_data_t;

// Les symboles sont des variables
typedef struct symbol_t {
	char* name;
	int type;
	symbol_data_t data;
} symbol_t;

char* symboleToString(symbol_t symbole);

int freeSymbole(symbol_t *symbole);

#endif

