
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>
#include <time.h>

#define TAILLE 100000000
#define NB_THREADS 4
#define SLICE (TAILLE / NB_THREADS)

int* tableau;

// Thread qui calcule la somme d'une partie du tableau
void* thread_tableau(void* arg) {
	int* id = (int*)arg;
	int end = *id + SLICE;

	int i;
	long somme = 0;
	for (i = *id; i < end; i++)
		somme += tableau[i];
	printf("[Thread #%d] J'ai calculé : %ld !\n", (*id / SLICE) + 1, somme);
	*id = somme;
	return NULL;
}

int main(int argc, char *argv[]) {
	printf("\n");
	fflush(stdout);

	pthread_t threads[NB_THREADS];
	long th_args[NB_THREADS];

	// Création du tableau
	tableau = malloc(sizeof(int) * TAILLE);
	int i;
	for (i = 0; i < TAILLE; i++)
		tableau[i] = rand() % 5 + 1;

	// Création des threads
	for (i = 0; i < NB_THREADS; i++) {
		th_args[i] = i * SLICE;
		if (pthread_create(&threads[i], NULL, thread_tableau, &th_args[i]) != 0) {
			perror("\nErreur de création du thread increment !\n");
			exit(EXIT_FAILURE);
		}
	}
	
	// Récupération de la somme
	long somme = 0;
	for (i = 0; i < NB_THREADS; i++) {
		pthread_join(threads[i], NULL);
		somme += th_args[i];
	}

	free(tableau);

	printf("[Thread Principal] La somme totale calculée est %ld !\n", somme);

	return EXIT_SUCCESS;
}

