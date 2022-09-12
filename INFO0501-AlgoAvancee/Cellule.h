
#ifndef __Cellule_h__
#define __Cellule_h__

typedef struct cellule, *CELLULE;
struct cellule {
	CELLULE prev, next;
	int value;
}

#endif
