#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>

// Surpress "warning: ‘y’ is used uninitialized [-Wuninitialized]"
// https://gcc.gnu.org/onlinedocs/gcc/Diagnostic-Pragmas.html
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuninitialized"
#pragma GCC diagnostic ignored "-Wunused-parameter"

/**
 * Calculates the inverse square root \f$ \frac{1}{\sqrt{(\mathrm{number})}} \f$ "by feet" - using pow and division.
 * @return the inverse square root of number
 * @param number the input.
 */
float inv_sqrt(float number)
{
    // Put your own inverse square root function here.
    return 0.0;
}

/**
 * This is the id-Software Quake III "inverse squareroot" algorithm.
 * @return the inverse square root of number
 * @param number the input.
 * Origin: https://github.com/id-Software/Quake-III-Arena/blob/dbe4ddb10315479fc00086f08e25d968b4b43c49/code/game/q_math.c#L552
 */
float Q_rsqrt(float number)
{
    // Put your Quake inverse square root function here.
    return 0.0;
}

// Return back to diagnostics settings before.
#pragma GCC diagnostic pop

/**
 * Benchmarks two inverse sqare root algorithms with each other.
 * Calls both algorithms <em>many</em> times and measures the duration.
 */
void benchmarkISqrtAlgs(void)
{
    printf("- %s, %d\n", __func__, __LINE__);

    // iteration control
    float start = 0.00001;
    float stop = 15000;
    float increment = 0.0005;

    volatile float res = 0.0;

    clock_t t_start, t_stop;
    double runtime;

    printf("Starting benchmark ... \n");

    // ------------- own inv_sqrt

    t_start = clock();
    for (volatile float i = start; i < stop; i += increment)
    {
        res = inv_sqrt(i);
    }
    t_stop = clock();

    runtime = ((double)t_stop - t_start) / CLOCKS_PER_SEC; // in seconds
    printf("Runtime %lf for inv_sqrt alg \n", runtime);

    // ------------- Quake

    t_start = clock();
    for (volatile float i = start; i < stop; i += increment)
    {
        res = Q_rsqrt(i);
    }
    t_stop = clock();

    runtime = ((double)t_stop - t_start) / CLOCKS_PER_SEC; // in seconds
    printf("Runtime %lf for Quake alg \n", runtime);

    printf("... just some print to fake usage of res to avoid optimization %f \n", res);
}

int main(void)
{
    benchmarkISqrtAlgs();
    return 0;
}
