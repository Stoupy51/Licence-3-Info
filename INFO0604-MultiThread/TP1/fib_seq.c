
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>

unsigned int fib(int n) {
	unsigned int x, y;
	
	if (n <= 1)
		return n;
	else {
		x = fib(n - 1);
		y = fib(n - 2);
		return x + y;
	}
}

void* thread_run(void* arg) {
	int* r = malloc(sizeof(int));
	*r = fib(*(int*)arg);
	free(arg);
	return r;
}

int main(int argc, char *argv[]) {
	unsigned int f;
	int n, diffTemps;
	time_t temps1, temps2;

	if (argc != 2) {
		printf("Usage : ./fib_seq.o n\n");
		printf("n : no du terme de la suite de fibonacci a calculer\n");
		exit(EXIT_SUCCESS);
	}
	n = atoi(argv[1]);	
	temps1 = time(NULL);

	// Démarrage des threads
    pthread_t thread_1;
    pthread_t thread_2;
	int* v_1 = malloc(sizeof(int));
	int* v_2 = malloc(sizeof(int));
	*v_1 = n-1;
	*v_2 = n-2;
    pthread_create(&thread_1, NULL, thread_run, v_1);
    pthread_create(&thread_2, NULL, thread_run, v_2);
	// Attente de l'arrêt des threads
	void* void_1;
	void* void_2;
    pthread_join(thread_1, &void_1);
    pthread_join(thread_2, &void_2);
	v_1 = (int*)void_1;
	v_2 = (int*)void_2;
	f = *v_1 + *v_2;

	temps2 = time(NULL);
	diffTemps = (int) temps2 - (int) temps1;
	printf("Valeur du %d-ieme nombre de Fibonacci : %u\n", n, f);
	printf("Temps : %d secondes\n", diffTemps);
	
	return EXIT_SUCCESS;
}

