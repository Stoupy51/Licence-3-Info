
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

/**
 * Structure contenant les deux sorties d'une division de polynômes
**/
typedef struct divideResult {
	POLYNOME	q,
				r;
} divideResult;

void freePolynome(POLYNOME *p);

int isNull(MONOME m);
int abs_mul(MONOME m);
int neutre(MONOME m);
MONOME init();
MONOME create(unsigned int d, double c);
MONOME copy(MONOME m);
MONOME negativeCopy(MONOME m);
void delete(MONOME *m, unsigned int d);
void deleteRecursif(MONOME *m, unsigned int d);
void add(MONOME *m, MONOME a);
void print(POLYNOME m);
POLYNOME copyPolynome(POLYNOME p);
POLYNOME negativeCopyPolynome(POLYNOME p);
POLYNOME fusion(POLYNOME a, POLYNOME b);
POLYNOME sub(POLYNOME a, POLYNOME b);
POLYNOME multiply(POLYNOME a, POLYNOME b);
divideResult divide(POLYNOME a, POLYNOME b);


#endif
