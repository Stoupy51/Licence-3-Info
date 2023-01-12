
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>
#include <time.h>

#include "queue.h"

#define NB_GUICHETS 4
#define CAPACITE 10

typedef struct int_p {
	pthread_mutex_t mutex;
	pthread_cond_t c_queue_libre;
	pthread_cond_t c_entering;
	queue_t queue;
	int value;
} int_p;

int_p protect = {
	PTHREAD_MUTEX_INITIALIZER,
	PTHREAD_COND_INITIALIZER,
	PTHREAD_COND_INITIALIZER,
	NULL,
	-1
};

void* thf_entering(void* arg) {
	int n;
	int next_id = 0;
	while (1) {
		printf("Entrez combien d'étrangers vous voulez faire entrer :\n");
		scanf("%d", &n);

		pthread_mutex_lock(&protect.mutex);
		while (n > 0) {
			if (isQueueFull(protect.queue)) {
				printf("La file d'attente est pleine, Mr.%d va attendre devant la porte !\n", next_id);
				pthread_cond_wait(&protect.c_queue_libre, &protect.mutex);
			}
			else {
				next_id++;
				n--;
				enfilerQueue(&protect.queue, next_id);
				printf("Ajout de Mr.%d dans la file d'attente !\n", next_id);
			}
			pthread_cond_broadcast(&protect.c_entering);
		}
		pthread_mutex_unlock(&protect.mutex);
	}
	return NULL;
}

void* thf_guichets(void* arg) {
	int id = *(int*)arg;

	int n, size;
	while (1) {
		pthread_mutex_lock(&protect.mutex);
		if (isQueueEmpty(protect.queue)) {
			pthread_cond_wait(&protect.c_entering, &protect.mutex);
			pthread_mutex_unlock(&protect.mutex);
		}
		else {
			n = defilerQueue(&protect.queue);
			size = protect.queue.count;
			pthread_cond_broadcast(&protect.c_queue_libre);
			pthread_mutex_unlock(&protect.mutex);
			sleep(5);
			printf("[Guichet #%d] Le prochain étranger (Mr.%d) est appelé, il reste %d personnes dans la salle d'attente !\n", id, n, size);
		}
	}
	return NULL;
}


int main(int argc, char *argv[]) {
	printf("\n");
	fflush(stdout);

	protect.queue = initQueue(CAPACITE);

	pthread_t th_entering;
	pthread_t th_guichets[NB_GUICHETS];

	int th_id_entering;
	int th_id_guichets[NB_GUICHETS];

	if (pthread_create(&th_entering, NULL, thf_entering, &th_id_entering) != 0) {
		perror("\nErreur de création du thread d'entrée !\n");
		exit(EXIT_FAILURE);
	}

	int i;
	for (i = 0; i < NB_GUICHETS; i++) {
		th_id_guichets[i] = i + 1;
		if (pthread_create(&th_guichets[i], NULL, thf_guichets, &th_id_guichets[i]) != 0) {
			perror("\nErreur de création d'un thread guichet !\n");
			exit(EXIT_FAILURE);
		}
	}
		
	while (1)
		sleep(__INT_MAX__);

	return EXIT_SUCCESS;
}

