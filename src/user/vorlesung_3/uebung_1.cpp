#include <stdio.h>
#include <math.h>
#include <time.h>

float inv_sqrt(float number)
{
    float sqrtN = pow(number, 0.5);
    return (1 / sqrtN);
}

void benchmarkISqrtAlgs()
{
    volatile float res = 0.0;
    float start = 0.00001;
    float stop = 15000;
    float increment = 0.0005;
    t_start = clock();
    for (volatile float i = start; i < stop; i += increment)
    {
        res = inv_sqrt(i);
    }
    t_stop = clock();
    runtime = ((double)t_stop - t_start) / CLOCKS_PER_SEC; // in seconds
    printf("Runtime %lf for inv_sqrt alg \n", runtime);
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}

