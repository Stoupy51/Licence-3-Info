
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <time.h>

long BENCH_countF1 = 0;
long BENCH_countF2 = 0;
time_t BENCH_end = 0;

#define BENCHMARK_BETWEEN(f1, f2, testing_time) \
	BENCH_countF1 = 0; \
	BENCH_countF2 = 0; \
	BENCH_end = time(NULL) + testing_time; \
	while (time(NULL) < BENCH_end) { \
		f1; \
		BENCH_countF1 += 1; \
	} \
	BENCH_end = time(NULL) + testing_time; \
	while (time(NULL) < BENCH_end) { \
		f2; \
		BENCH_countF2 += 1; \
	} \
	if (BENCH_countF1 > BENCH_countF2) { \
		printf("\nf1 > f2 by %f times with", (double)BENCH_countF1 / (double)BENCH_countF2); \
	} else { \
		printf("\nf1 < f2 by %f times with", (double)BENCH_countF2 / (double)BENCH_countF1); \
	} \
	printf("\nf1 executed %ld times and f2 executed %ld times\n\n", BENCH_countF1, BENCH_countF2);

int main(int argc, char *argv[]) {
	if (argc != 2) {
		fprintf(stderr,"\nUsage: %s <testing_time>\n", argv[0]);
		return EXIT_FAILURE;
	}

	#define TAB_SIZE 1000000

	size_t size = TAB_SIZE * sizeof(int);
	int* tab = malloc(size);
	int i;
	int t = atoi(argv[1]);
	BENCHMARK_BETWEEN(
		memset(tab, 0, size),
		for (i = 0; i < TAB_SIZE; i++) tab[i] = 0,
		t
	);

	return 0;
}

