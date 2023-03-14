
#ifndef __symbole_h__
#define __symbole_h__

#define SYMBOL_TYPE_INTEGER 0
#define SYMBOL_TYPE_DOUBLE 1
#define SYMBOL_TYPE_FLOAT 2
#define SYMBOL_TYPE_CHAR 3
#define SYMBOL_TYPE_STRING 4
#define SYMBOL_TYPE_LONG 5
#define SYMBOL_TYPE_POINTER 6

typedef union symbole_data_t {
	int i;
	double d;
	float f;
	char s;
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

int freeSymbole(symbole_t *symbole);

#endif

