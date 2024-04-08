#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "gcd/gcd.h"

int main(void)
{
    printf("- %s, %d\n", __func__, __LINE__);

    //int max_runs = 1000000;
    int max_runs = 100000;
    int g = 17711;
    int k = 10946;
    volatile int result;

    printf("Starting gcd benchmark ... \n");

    clock_t t_start, t_stop;
    double runtime;

    // gcd_bf
    t_start = clock();
    for (volatile int i = 1; i < max_runs; i++)
    {
        result = gcd_bf(g, k);
    }
    t_stop = clock();
    runtime = ((double)t_stop - t_start) / CLOCKS_PER_SEC; // in seconds
    printf("Runtime gcd_bf:        %lfs \n", runtime);

    // gcd_euklid
    t_start = clock();
    for (volatile int i = 1; i < max_runs; i++)
    {
        result = gcd_euklid(g, k);
    }
    t_stop = clock();
    runtime = ((double)t_stop - t_start) / CLOCKS_PER_SEC; // in seconds
    printf("Runtime gcd_euklid:    %lfs \n", runtime);

    // gcd_modern
    t_start = clock();
    for (volatile int i = 1; i < max_runs; i++)
    {
        result = gcd_modern(g, k);
    }
    t_stop = clock();
    runtime = ((double)t_stop - t_start) / CLOCKS_PER_SEC; // in seconds
    printf("Runtime gcd_modern:    %lfs \n", runtime);

    // gcd_recursive
    t_start = clock();
    for (volatile int i = 1; i < max_runs; i++)
    {
        result = gcd_recursive(g, k);
    }
    t_stop = clock();
    runtime = ((double)t_stop - t_start) / CLOCKS_PER_SEC; // in seconds
    printf("Runtime gcd_recursive: %lfs \n", runtime);

    // fake usage
    result = 0;
    return result;
}