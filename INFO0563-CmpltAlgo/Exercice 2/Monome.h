
#ifndef __Monome__
#define __Monome__

/**
 * Structure d'un Monome
**/
typedef struct monome {
	unsigned int	d; // Degré
	double			c; // Coefficient
	MONOME			m; // Monome suivant
} Monome, *MONOME, *POLYNOME;

int isNull(MONOME m);
void add(MONOME *m, MONOME a);
MONOME init();
MONOME create(unsigned int d, double c);
MONOME head(MONOME *m);


#endif
