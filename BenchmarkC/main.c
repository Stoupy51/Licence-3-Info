
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <time.h>

#define COLOR_RESET "\033[0m"
#define COLOR_RED "\033[0;31m"
#define COLOR_YELLOW "\033[0;33m"

long BENCH_countF1 = 0;
long BENCH_countF2 = 0;
time_t BENCH_start = 0;
time_t BENCH_end = 0;

#define BENCHMARK_BETWEEN(bench_f1, bench_f2, bench_testing_time) \
	BENCH_countF1 = 0; \
	BENCH_countF2 = 0; \
	BENCH_end = time(NULL) + bench_testing_time; \
	while (time(NULL) < BENCH_end) { \
		bench_f1; \
		BENCH_countF1 += 1; \
	} \
	BENCH_end = time(NULL) + bench_testing_time; \
	while (time(NULL) < BENCH_end) { \
		bench_f2; \
		BENCH_countF2 += 1; \
	} \
	if (BENCH_countF1 > BENCH_countF2) { \
		printf("\nf1 > f2 by %f times with", (double)BENCH_countF1 / (double)BENCH_countF2); \
	} else { \
		printf("\nf1 < f2 by %f times with", (double)BENCH_countF2 / (double)BENCH_countF1); \
	} \
	printf("\n%sf1 executed %s%ld%s times and f2 executed %s%ld times%s\n\n", COLOR_RED, COLOR_YELLOW, COLOR_RED, BENCH_countF1, COLOR_YELLOW, BENCH_countF2, COLOR_RESET);

#define BENCHMARK_SOLO(bench_f, bench_count) \
	BENCH_start = time(NULL); \
	for (int i = 0; i < bench_count; i++) { \
		bench_f; \
	} \
	BENCH_end = time(NULL); \
	printf("\nbench_f executed %d times in %ld seconds\n\n", bench_count, BENCH_end - BENCH_start);


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

