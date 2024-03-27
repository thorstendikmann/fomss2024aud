#include <stdio.h>
#include <time.h>

/**
 * Rekursive Implementierung des Faktoriellen.
 */
int factr(int n)
{
	if (n <= 1)
		return 1;
	else
		return n * factr(n - 1);
}

/**
 * Iterative Implementierung des Faktoriellen.
 */
int facti(int n)
{
	int result = 1;
	for (int i = 2; i <= n; i++)
		result *= i;
	return result;
}

/**
 * Benchmarking beider Faktorial-Algorithmen.
 */
void benchmarkFactCaller(void)
{
	printf("- %s, %d\n", __func__, __LINE__);

	int n = 12; // Reduzierter Wert für n, um Überläufe und Stacküberlauf zu vermeiden
	printf("Starting factorial benchmark ... \n");

	clock_t t_start, t_stop;
	double runtime;

	t_start = clock();
	printf("Recursive: %i\n", factr(n));
	t_stop = clock();
	runtime = ((double)t_stop - t_start) / CLOCKS_PER_SEC; // in seconds
	printf("Runtime %lf for factr alg \n", runtime);

	t_start = clock();
	printf("Iterative: %i\n", facti(n));
	t_stop = clock();
	runtime = ((double)t_stop - t_start) / CLOCKS_PER_SEC; // in seconds
	printf("Runtime %lf for facti alg \n", runtime);
}

int main(void)
{
	// Demonstration der rekursiven und iterativen Implementierung
	printf("Rekursives Faktoriell von 5: %d\n", factr(5));
	printf("Iteratives Faktoriell von 5: %d\n", facti(5));

	// Aufruf des Benchmarks
	benchmarkFactCaller();
}
