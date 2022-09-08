
#ifndef __Monome__
#define __Monome__

/**
 * Structure d'un Monome
**/
typedef struct monome Monome, *MONOME, *POLYNOME;
struct monome {
	unsigned int	d; // Degré
	double			c; // Coefficient
	MONOME			m; // Monome suivant
};

int isNull(MONOME m);
MONOME init();
MONOME create(unsigned int d, double c);
MONOME copy(MONOME m);
void delete(MONOME *m, unsigned int d);
void deleteRecursif(MONOME *m, unsigned int d);
void add(MONOME *m, MONOME a);
void fusion(POLYNOME *p, POLYNOME a);
void multiply(POLYNOME *p, POLYNOME a);
void printPolynome(MONOME m);


#endif
