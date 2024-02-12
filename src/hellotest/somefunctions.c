#include "somefunctions.h"
#include <stdio.h>

/**
 * Calculates the factorial of n.
*/
int factorial(int n)
{
    // printf("calling factorial %d\n", n);
    if (n == 0)
        return 1;
    else
        return (n * factorial(n - 1));
    return 0;
}

/**
 * Returns true if n is a prime number.
*/
int isPrime(int n)
{
    if (n <= 1)
        return 0;
    if (n % 2 == 0)
        return n == 2;


    // Divide n by every odd number i, starting from 3
    for (int i = 3;; i += 2)
    {
        // Terminate i when reaching square root of n
        if (i > n / i)
            break;

        // Found a divisor?
        if (n % i == 0)
            return 0;
    }

    // n is prime
    return 1;
}