#include <stdio.h>
#include <stdlib.h>

#include "gcd.h"

int gcd_bf(int g, int k)
{
    int maxGCD = 1;
    int divisor = 1;

    while (divisor <= g && divisor <= k)
    {
        int rest1 = g % divisor;
        int rest2 = k % divisor;

        if (rest1 == 0 && rest2 == 0)
        {
            maxGCD = divisor;
        }

        divisor++;
    }

    return maxGCD;
}

int gcd_euklid(int g, int k)
{
    int t; // temp swap variable

    while (g > 0)
    {
        // We want g > k, swap numbers otherwise
        if (g < k)
        {
            t = g;
            g = k;
            k = t;
        }
        g = g - k;
    }
    return k;
}

int gcd_modern(int g, int k)
{
    int t, rest;

    if (g < k)
    {
        t = g;
        g = k;
        k = t;
    }

    while (1)
    {
        rest = g % k;

        if (rest == 0)
        {
            return (k);
        }
        else
        {
            g = k;
            k = rest;
        }
    }
}

int gcd_recursive(int g, int k)
{
    if (k == 0)
    {
        return g;
    }

    return gcd_recursive(k, g % k);
}
