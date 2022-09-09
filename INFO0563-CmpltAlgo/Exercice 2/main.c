
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

	fprintf(stderr,"\n\n-------Multiply Polynome------\n");
	POLYNOME p3 = multiply(p, p2);
	print(p3);

	fprintf(stderr,"\n\n--------Divide Polynome-------\n");
	POLYNOME a = init();
	add(&a, create(5,1));
	add(&a, create(3,-3));
	add(&a, create(1,2));
	add(&a, create(0,-10));
	POLYNOME b = init();
	add(&b, create(2,-1));
	add(&b, create(1,1));
	add(&b, create(0,1));
	divideResult d = divide(a,b);
	print(d.q);
	print(d.r);

	/*fprintf(stderr,"\n\n-------Divide Polynome 2------\n");
	print(divide(a,a).q);
	print(divide(b,b).q);
	POLYNOME p6 = divide(b,b).q;
	POLYNOME p7 = multiply(d.q,d.q);
	print(d.q);
	print(p7);
	print(divide(p7,d.q).q);*/

	fprintf(stderr,"\n\nFin de la fonction main()\n");
	return 0;
}


