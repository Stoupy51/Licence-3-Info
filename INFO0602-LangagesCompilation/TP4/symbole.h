
#ifndef __symbole_h__
#define __symbole_h__

typedef enum symbole_type_t {
	SYMBOL_TYPE_INTEGER = 0,
	SYMBOL_TYPE_DOUBLE = 1,
	SYMBOL_TYPE_FLOAT = 2,
	SYMBOL_TYPE_CHAR = 3,
	SYMBOL_TYPE_STRING = 4,
	SYMBOL_TYPE_LONG = 5,
	SYMBOL_TYPE_POINTER = 6
} symbole_type_t;

typedef union symbole_data_t {
	int i;
	double d;
	float f;
	char c;
	char* s;
	long l;
	void* p;
} symbole_data_t;

// Les symboles sont des variables
typedef struct symbole_t {
	char* name;
	int type;
	symbole_data_t data;
} symbole_t;

char* symboleToString(symbole_t symbole);

int freeSymbole(symbole_t *symbole);

#endif

