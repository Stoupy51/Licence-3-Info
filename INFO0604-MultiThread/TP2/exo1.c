
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>
#include <time.h>

typedef struct int_p {
	pthread_mutex_t mutex;
	pthread_cond_t c_increment;
	pthread_cond_t c_increment_9;
	int value;
	int sync_print;
} int_p;

int_p compteur = {
	PTHREAD_MUTEX_INITIALIZER,
	PTHREAD_COND_INITIALIZER,
	PTHREAD_COND_INITIALIZER,
	0,
	-1
};

void* thf_increment(void* arg) {
	int id = *(int*)arg;
	while (1) {
		printf("[Thread Increment #%d] Hey !\n", id);

		pthread_mutex_lock(&compteur.mutex);
		compteur.value++;
		if (compteur.value % 2 == 0)
			pthread_cond_broadcast(&compteur.c_increment);
		else if (compteur.value == 9)
			pthread_cond_broadcast(&compteur.c_increment_9);
		pthread_mutex_unlock(&compteur.mutex);

		sleep(2);
	}
	return NULL;
}

void* thf_print(void* arg) {
	int id = *(int*)arg;
	pthread_mutex_lock(&compteur.mutex);

	while (1) {
		if (compteur.sync_print != compteur.value) {
			compteur.sync_print = compteur.value;
			if (compteur.value % 2 == 0)
				printf("[Thread Print #%d] Compteur == %d\n", id, compteur.value);
		}

		pthread_cond_wait(&compteur.c_increment, &compteur.mutex);
	}
	return NULL;
}

void* thf_reset(void* arg) {
	int id = *(int*)arg;
	pthread_mutex_lock(&compteur.mutex);

	while (1) {
		if (compteur.value >= 9) {
			printf("[Thread Reset #%d] Reset !\n", id);
			compteur.value = 0;
		}

		pthread_cond_wait(&compteur.c_increment_9, &compteur.mutex);
	}
	return NULL;
}

int main(int argc, char *argv[]) {
	printf("\n");
	fflush(stdout);

	#define s_increment 1
	#define s_print 4
	#define s_reset 4
	pthread_t th_increment[s_increment];
	pthread_t th_print[s_print];
	pthread_t th_reset[s_reset];
	int i;

	int th_id_increment[s_increment];
	int th_id_print[s_print];
	int th_id_reset[s_reset];

	for (i = 0; i < s_increment; i++) {
		th_id_increment[i] = i + 1;
		if (pthread_create(&th_increment[i], NULL, thf_increment, &th_id_increment[i]) != 0) {
			perror("\nErreur de création du thread increment !\n");
			exit(EXIT_FAILURE);
		}
	}
	
	for (i = 0; i < s_print; i++) {
		th_id_print[i] = i + 1;
		if (pthread_create(&th_print[i], NULL, thf_print, &th_id_print[i]) != 0) {
			perror("\nErreur de création du thread print !\n");
			exit(EXIT_FAILURE);
		}
	}
	
	for (i = 0; i < s_reset; i++) {
		th_id_reset[i] = i + 1;
		if (pthread_create(&th_reset[i], NULL, thf_reset, &th_id_reset[i]) != 0) {
			perror("\nErreur de création du thread reset !\n");
			exit(EXIT_FAILURE);
		}
	}
	
	while (1)
		sleep(__INT_MAX__);

	return EXIT_SUCCESS;
}

