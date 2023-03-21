
#ifndef __symbol_h__
#define __symbol_h__

typedef enum symbol_type_t {
	SYMBOL_TYPE_INTEGER = 0,
	SYMBOL_TYPE_DOUBLE = 1,
	SYMBOL_TYPE_FLOAT = 2,
	SYMBOL_TYPE_CHAR = 3,
	SYMBOL_TYPE_STRING = 4,
	SYMBOL_TYPE_LONG = 5,
	SYMBOL_TYPE_POINTER = 6
} symbol_type_t;

typedef union symbol_data_t {
	int i;
	double d;
	float f;
	char c;
	char* s;
	long l;
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

