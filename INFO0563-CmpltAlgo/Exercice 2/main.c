
#include "Monome.h"
#include <stdlib.h>
#include <stdio.h>

int main() {
	fprintf(stderr,"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	fprintf(stderr,"Debut de la fonction main()");

	fprintf(stderr,"\n\n--------Create & Print--------\n");
	POLYNOME p = create(4,7);
	printPolynome(p);

	fprintf(stderr,"\n\n-------------Add--------------\n");
	add(&p, create(5,3));
	printPolynome(p);



	fprintf(stderr,"\nFin de la fonction main()\n");
	return 0;
}


