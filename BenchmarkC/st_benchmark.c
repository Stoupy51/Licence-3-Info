
#include "st_benchmark.h"

// Functions definitions
void testMultipleMallocs1(size_t nOI);
void testMultipleMallocs2(size_t nOI);

/**
 * @brief Benchmark main function
 * 
 * @param argc Number of arguments
 * @param argv Arguments list
 * 
 * @return int
*/
int main(int argc, char *argv[]) {
	// Check the number of arguments
	if (argc != 2) {
		fprintf(stderr,"\nUsage: %s <testing_time>\n", argv[0]);
		return EXIT_FAILURE;
	}
	printf("\n");

	// Initialisations of variables
	int i, testing_time = atoi(argv[1]);
	char buffer[1024];

	// Benchmark between two functions
	size_t nOI = 2785009972;
	printf("Size of the memory to allocate: %zu\n", nOI);
	ST_BENCHMARK_BETWEEN (buffer,
		{ testMultipleMallocs1(nOI); },		// Code f1
		{ testMultipleMallocs2(nOI); },		// Code f2
		"'Multiple mallocs'",				// Name of code f1
		"'one malloc'",						// Name of code f2
		testing_time						// Max Testing time
	);
	printf("%s", buffer);

	// Benchmark of a function
	ST_BENCHMARK_SOLO(buffer,
		{ testMultipleMallocs2(nOI); },
		"'testMultipleMallocs2'", 1000
	);
	printf("%s", buffer);

	int* a = malloc(nOI * sizeof(int));
	for (i = 0; i < nOI; i++) {
		a[i] = i;
	}
	sleep(5);
	free(a);

	// Return line and exit
	printf("\n");
	return 0;
}

/**
 * @brief Function that uses multiple mallocs to allocate memory for different types
 * 
 * @c slower than testMultipleMallocs2 but more readable to allocate memory
*/
void testMultipleMallocs1(size_t nOI) {

	// Allocate the memory
	int* i = malloc(nOI * sizeof(int));
	double* d = malloc(nOI * sizeof(double));
	char* c = malloc(nOI * sizeof(char));
	float* f = malloc(nOI * sizeof(float));
	long* l = malloc(nOI * sizeof(long));
	long double* ld = malloc(nOI * sizeof(long double));
	short* s = malloc(nOI * sizeof(short));
	unsigned int* ui = malloc(nOI * sizeof(unsigned int));
	unsigned long* ul = malloc(nOI * sizeof(unsigned long));
	unsigned short* us = malloc(nOI * sizeof(unsigned short));
	unsigned char* uc = malloc(nOI * sizeof(unsigned char));

	// Free the memory
	free(i); free(d); free(c); free(f); free(l); free(ld); free(s); free(ui); free(ul); free(us); free(uc);
}

/**
 * @brief Function that uses one malloc to allocate memory for
 * different types and then cast the pointer to the right type
 * 
 * @c faster than testMultipleMallocs1 but less readable to allocate memory
*/
void testMultipleMallocs2(size_t nOI) {
	// Calculate the total size of the memory to allocate (Could also multiply by nOI after each sizeof)
	size_t totalSize = 0
		+ (nOI * sizeof(int)) + (nOI * sizeof(double)) + (nOI * sizeof(char)) + (nOI * sizeof(float))
		+ (nOI * sizeof(long)) + (nOI * sizeof(long double)) + (nOI * sizeof(short)) + (nOI * sizeof(unsigned int))
		+ (nOI * sizeof(unsigned long)) + (nOI * sizeof(unsigned short)) + (nOI * sizeof(unsigned char));

	// Allocate the memory
	void* globalMalloc = malloc(totalSize);
	int* i = (int*)globalMalloc;
	double* d = (double*)(i + nOI);
	char* c = (char*)(d + nOI);
	float* f = (float*)(c + nOI);
	long* l = (long*)(f + nOI);
	long double* ld = (long double*)(l + nOI);
	short* s = (short*)(ld + nOI);
	unsigned int* ui = (unsigned int*)(s + nOI);
	unsigned long* ul = (unsigned long*)(ui + nOI);
	unsigned short* us = (unsigned short*)(ul + nOI);
	unsigned char* uc = (unsigned char*)(us + nOI);

	// Free the memory
	free(globalMalloc);
}

