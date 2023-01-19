
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>
#include <time.h>

#define NB_LIGNES	12
#define NB_COLONNES	12
#define NB_THREADS 2
#define TH_SLICE (NB_LIGNES / NB_THREADS)

int **matrice;
int *vecteur;
int *vecResultat;

size_t sizeofIntNbColonnes = sizeof(int) * NB_COLONNES;
size_t sizeofIntNbLignes = sizeof(int) * NB_LIGNES;

void afficherMatrice(int** matrice, int m, int n) {
	int i, j;
	printf("\n***Matrice***\n");
	for (i = 0; i < m; i++){
		for (j = 0; j < n; j++)
			printf("%d ", matrice[i][j]);
		printf("\n");
	}
	printf("**************\n");
}

void afficherVecteur(int* vecteur, int taille) {
	int i;
	printf("\n***Vecteur***\n");
	for (i = 0; i < taille; i++)
		printf("%d ", vecteur[i]);
	printf("\n");
	printf("*************\n");
}

// Thread qui va allouer la ligne et la calculer
void* thread_par_lignes(void* arg) {
	int* id = (int*)arg;
	int end = *id + TH_SLICE;
	int myId = *id / TH_SLICE + 1;

	int i, j;
	for (i = *id; i < end; i++) {
		vecResultat[i] = 0;
		for (j = 0; j < NB_COLONNES; j++)
			vecResultat[i] = vecResultat[i] + matrice[i][j] * vecteur[j];
		printf("[Thread #%d] J'ai calculé pour %d : %d\n", myId, i, vecResultat[i]);
	}

	return NULL;
}

int main(int argc, char *argv[]) {
	int i, j;

	srand(time(NULL));

	// Allocation de la matrice de base et remplissage avec rand
	matrice = (int **) malloc(sizeof(int *) * NB_LIGNES);
	for (i = 0; i < NB_LIGNES; i++) {
		matrice[i] = (int *) malloc(sizeofIntNbColonnes);
		for (j = 0; j < NB_COLONNES; j++)
			matrice[i][j] = (rand() % 5) + 1;
	}

	// Allocation d'un vecteur et remplissage avec rand
	vecteur = (int *) malloc(sizeofIntNbColonnes);
	for (i = 0; i < NB_COLONNES; i++)
		vecteur[i] = (rand() % 5) + 1;

	// Allocation du vecteur de résultat avec -1
	vecResultat = (int *) malloc(sizeofIntNbLignes);
	memset(vecResultat, -1, sizeofIntNbLignes);

	// Affichage des matrices
	afficherMatrice(matrice, NB_LIGNES, NB_COLONNES);
	afficherVecteur(vecteur, NB_COLONNES);

	// Calcul du résultat
	pthread_t threads[NB_THREADS];
	int th_tubes[NB_THREADS];
	for (i = 0; i < NB_THREADS; i++) {
		th_tubes[i] = i * TH_SLICE;
		pthread_create(&threads[i], NULL, thread_par_lignes, &th_tubes[i]);
	}
	for (i = 0; i < NB_THREADS; i++)
		pthread_join(threads[i], NULL);

	// Affichage du vecteur résultat
	afficherVecteur(vecResultat, NB_LIGNES);

	// Libérations mémoire
	free(vecteur);
	free(vecResultat);
	for (i = 0; i < NB_LIGNES; i++)
		free(matrice[i]);
	free(matrice);

	return 0;
}

