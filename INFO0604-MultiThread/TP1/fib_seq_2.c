
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

void* fib_thread(void* arg) {
	int* r = (int*)arg;
	if (*r <= 1)
		return NULL;
	
    pthread_t thread;
	unsigned int x = *r - 1;
	unsigned int y = *r - 2;
    pthread_create(&thread, NULL, fib_thread, &x);
	fib_thread(&y);
    pthread_join(thread, NULL);

	*r = x + y;
	return NULL;
}

int main(int argc, char *argv[]) {
	unsigned int f;
	int n, diffTemps;
	time_t temps1, temps2;

	if (argc != 2) {
		printf("Usage : ./fib_seq_2.o n\n");
		printf("n : no du terme de la suite de fibonacci a calculer\n");
		exit(EXIT_SUCCESS);
	}
	n = atoi(argv[1]);	
	temps1 = time(NULL);

	f = n;
	fib_thread(&f);

	temps2 = time(NULL);
	diffTemps = (int) temps2 - (int) temps1;
	printf("Valeur du %d-ieme nombre de Fibonacci : %u\n", n, f);
	printf("Temps : %d secondes\n", diffTemps);
	
	return EXIT_SUCCESS;
}

