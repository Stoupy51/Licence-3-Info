
#include "st_benchmark.h"

int main(int argc, char *argv[]) {
	if (argc != 2) {
		fprintf(stderr,"\nUsage: %s <testing_time>\n", argv[0]);
		return EXIT_FAILURE;
	}
	printf("\n");

	int TAB_SIZE = 1000000;

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

	free(tab);

	printf("\n");
	return 0;
}
