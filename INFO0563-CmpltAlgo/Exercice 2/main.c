
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
	add(&p, create(5,3));
	add(&p, create(7,3));
	add(&p, create(2,3));
	printPolynome(p);

	fprintf(stderr,"\n\n----------Add Polynome--------\n");
	POLYNOME p2 = init();
	addPolynome(&p2, p);
	printPolynome(p);
	printPolynome(p2);

	fprintf(stderr,"\nFin de la fonction main()\n");
	return 0;
}


