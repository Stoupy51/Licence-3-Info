
#include "pthread.h"
#include "stdio.h"
#include "stdlib.h"
#include "sys/time.h"
#include <unistd.h>

void *show_time(void *args) {
	struct timeval tv;
	gettimeofday(&tv, NULL);
	unsigned long us = 1000000 * tv.tv_sec + tv.tv_usec;

    printf("Le lancement du thread a pris %ld micro secondes !\n", us - *(unsigned long*)args);
	
	// while (1) {}
    return NULL;
}

int main(int argc, char *argv[]) {
    int nbThread = 1;
    if (argc == 2)
        nbThread = atoi(argv[1]);
    
    // Démarrage des threads
    pthread_t *threads = malloc(sizeof(pthread_t) * nbThread);
	unsigned long *time_threads = malloc(sizeof(unsigned long) * nbThread);
    for (int i = 0; i < nbThread; i++) {
        struct timeval tv;
		gettimeofday(&tv, NULL);
		time_threads[i] = 1000000 * tv.tv_sec + tv.tv_usec;
        
        pthread_create(&threads[i], NULL, show_time, &time_threads[i]);
    }

	// sleep(2);
	// return 1;

    for (int i = 0; i < nbThread; i++)
        pthread_join(threads[i], NULL);
    free(threads);
	free(time_threads);

    return EXIT_SUCCESS;
}

