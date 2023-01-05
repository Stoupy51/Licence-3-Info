
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>

#define SPIN 10000000000
#define nbThreads 4
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
long compteur = 0;

void* thread_loop(void* arg) {
	long i;
	for (i = 0; i < SPIN / nbThreads; i++) {
		pthread_mutex_lock(&mutex);
		compteur++;
		pthread_mutex_unlock(&mutex);
	}
    return NULL;
}

int main(int argc, char *argv[]) {
	int i, diffTemps;
	time_t temps1, temps2;
	temps1 = time(NULL);

	// Démarrage des threads
    pthread_t* threads = malloc(sizeof(pthread_t) * nbThreads);
    for(i = 0; i < nbThreads; i++)
        pthread_create(&threads[i], NULL, thread_loop, NULL);

	// Attente de l'arrêt des threads
	for(i = 0; i < nbThreads; i++)
        pthread_join(threads[i], NULL);
    free(threads);

	temps2 = time(NULL);
	diffTemps = (int)temps2 - (int)temps1;
	printf("Valeur finale du compteur : %ld\n", compteur);
	printf("Temps : %d secondes\n", diffTemps);

	return EXIT_SUCCESS;
}

