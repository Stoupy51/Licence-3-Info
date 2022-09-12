
#ifndef __Liste_h__
#define __Liste_h__

typedef struct liste_t {
	CELLULE head;
	int size;
}

CELLULE rechercherListe(liste_t l, int k);
void insererListe(liste *l, CELLULE x);
void supprimerListe(liste *l, CELLULE x);

#endif
