
#ifndef __queue_h__
#define __queue_h__

#include <stdlib.h>
#include <stdio.h>

typedef struct queue Queue, *QUEUE;
struct queue {
	int * list;
	int head,
		next,
		size;
};

#endif

