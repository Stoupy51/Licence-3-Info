
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/time.h>
#include <time.h>

#define COLOR_RESET "\033[0m"
#define COLOR_RED "\033[0;31m"
#define COLOR_YELLOW "\033[0;33m"

int BENCH_i = 0;
long BENCH_countF1 = 0;
long BENCH_countF2 = 0;
time_t BENCH_end = 0;
struct timeval BENCH_timeval, BENCH_timeval2;
unsigned long BENCH_time = 0;

#define BENCHMARK_BETWEEN(bench_f1, bench_f2, bench_testing_time) \
	BENCH_countF1 = 0; \
	BENCH_countF2 = 0; \
	BENCH_end = time(NULL) + 1; \
	while (time(NULL) < BENCH_end) {} \
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
		printf(COLOR_RED "f1 > f2 by " COLOR_YELLOW "%f" COLOR_RED " times with" COLOR_RESET, (double)BENCH_countF1 / (double)BENCH_countF2); \
	} else { \
		printf(COLOR_RED "f1 < f2 by " COLOR_YELLOW "%f" COLOR_RED " times with" COLOR_RESET, (double)BENCH_countF2 / (double)BENCH_countF1); \
	} \
	printf(COLOR_RED "\nf1 executed " COLOR_YELLOW "%ld" COLOR_RED " times and f2 executed " COLOR_YELLOW "%ld" COLOR_RED " times\n\n" COLOR_RESET, BENCH_countF1, BENCH_countF2);


#define BENCHMARK_SOLO(bench_f, bench_count) \
	gettimeofday(&BENCH_timeval, NULL); \
	BENCH_time = 1000000 * BENCH_timeval.tv_sec + BENCH_timeval.tv_usec; \
	BENCH_i = 0; \
	for (BENCH_i = 0; BENCH_i < bench_count; BENCH_i++) { \
		bench_f; \
	} \
	gettimeofday(&BENCH_timeval2, NULL); \
	BENCH_time = 1000000 * BENCH_timeval2.tv_sec + BENCH_timeval2.tv_usec - BENCH_time; \
	printf(COLOR_RED "f executed " COLOR_YELLOW "%d" COLOR_RED " times in " COLOR_YELLOW "%lf" COLOR_RED "s\n\n" COLOR_RESET, bench_count, (double)BENCH_time / 1000000.0);


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

	int dump;
	BENCHMARK_BETWEEN (
		{
			// Code 1 (f1)
			memset(tab, 0, size);
		},
		{
			// Code 2 (f2)
			for (i = 0; i < TAB_SIZE; i++) {
				tab[i] = 0;
			}
		},
		t
	);

	BENCHMARK_SOLO(
		{
			// Code  (f)
			//memset(tab, 0, size);
		},
		10000
	);

	return 0;
}

