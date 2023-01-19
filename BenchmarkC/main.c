
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <time.h>

double BENCH_countF1 = .0;
double BENCH_countF2 = .0;
double BENCH_ratio = .0;
time_t BENCH_end = 0;

#define BENCHMARK_BETWEEN(f1, f2, testing_time) \
	BENCH_countF1 = .0, BENCH_countF2 = .0; \
	BENCH_end = time(NULL) + testing_time; \
	while (time(NULL) < BENCH_end) { \
		f1; \
		BENCH_countF1++; \
	} \
	BENCH_end = time(NULL) + testing_time; \
	while (time(NULL) < BENCH_end) { \
		f2; \
		BENCH_countF2++; \
	} \
	if (BENCH_countF1 > BENCH_countF2) { \
		BENCH_ratio = BENCH_countF1 / BENCH_countF2; \
		printf("\nf1 > f2 by %d times with", BENCH_ratio); \
	} else { \
		BENCH_ratio = BENCH_countF2 / BENCH_countF1; \
		printf("\nf1 < f1 by %d times with", BENCH_ratio); \
	} \
	printf("\nf1 executed %d times and f2 executed %d times", BENCH_countF1, BENCH_countF2);

int main(int argc, char *argv[]) {

	#define TAB_SIZE 1000000

	size_t size = TAB_SIZE * sizeof(int);
	int* tab = malloc(size);
	int i;
	BENCHMARK_BETWEEN(
		memset(tab, 0, size),
		for (i = 0; i < TAB_SIZE; i++) tab[i] = 0,
		1
	);

	return 0;
}

