#include <stdio.h>
#include <time.h>

/**
 * Rekursive implementation of the factorial
 * \f$ factr(n) = n! = n \cdot (n-1) \cdot (n-2) \cdot \ldots \cdot 1 = \Pi_{n=1}^n i \f$
 *
 * @param n the parameter to calc \f$ n! \f$.
 * @return \f$ n! \f$.
 */
int factr(int n)
{
	// add the recursive implementation here
	return n;
}

/**
 * Iterative implementation of the factorial
 * \f$ factr(n) = n! = n \cdot (n-1) \cdot (n-2) \cdot \ldots \cdot 1 = \Pi_{n=1}^n i \f$
 *
 * @param n the parameter to calc \f$ n! \f$.
 * @return \f$ n! \f$.
 */
int facti(int n)
{
	// add the iterative implementation here
	return n;
}

/**
 * Benchmarking both factorial algorithms.
 */
void benchmarkFactCaller(void)
{
    printf("- %s, %d\n", __func__, __LINE__);

	int n = 100000;
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
	// Call recursive and iterative implementation
	// Add some nice output here ...
	factr(5);
	facti(5);

	// Calls benchmark
	benchmarkFactCaller();
}
