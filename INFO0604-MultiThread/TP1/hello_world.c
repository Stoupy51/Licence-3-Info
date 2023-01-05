
#include "pthread.h"
#include "stdio.h"
#include "stdlib.h"

void *hello_world(void *args) {
    int *v = (int*)args;

    printf("Hello World ! du thread %d de %d !\n", v[0], v[1]);

    free(args);
    return NULL;
}

int main(int argc, char *argv[]) {
    int nbThread = 1;
    if (argc == 2)
        nbThread = atoi(argv[1]);
    
    // Démarrage des threads
    pthread_t *threads = malloc(sizeof(pthread_t) * nbThread);
    for (int i = 0; i < nbThread; i++) {
        int *args = malloc(sizeof(int) * 2);
        args[0] = i + 1;
        args[1] = nbThread;
        pthread_create(&threads[i], NULL, hello_world, args);
    }

    for (int i = 0; i < nbThread; i++)
        pthread_join(threads[i], NULL);
    free(threads);

    return EXIT_SUCCESS;
}

