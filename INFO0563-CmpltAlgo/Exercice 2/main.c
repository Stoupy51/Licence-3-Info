
#include "Monome.h"
#include <stdlib.h>
#include <stdio.h>

int main() {
	fprintf(stderr,"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	fprintf(stderr,"Debut de la fonction main()");

	fprintf(stderr,"\n\n--------Create & Print--------\n");
	POLYNOME p = create(4,7);
	print(p);

	fprintf(stderr,"\n\n-------------Add--------------\n");
	add(&p, create(5,3));
	add(&p, create(5,3));
	add(&p, create(7,3));
	add(&p, create(2,3));
	print(p);

	fprintf(stderr,"\n\n----------Add Polynome--------\n");
	POLYNOME p2 = fusion(p, p);
	print(p);
	print(p2);

	fprintf(stderr,"\n\n----------Multiply Polynome--------\n");
	POLYNOME p3 = multiply(p, p2);
	print(p3);

	fprintf(stderr,"\n\n-----------Divide Polynome--------\n");
	POLYNOME a = create(0,4);
	add(&a, create(1,-1));
	add(&a, create(3,1));
	POLYNOME b = create(0,1);
	add(&b, create(1,1));
	POLYNOME p4 = divide(a,b);
	print(a);
	print(b);
	print(p4);

	fprintf(stderr,"\nFin de la fonction main()\n");
	return 0;
}


