#include <stdio.h>
#include <stdlib.h>

#include "gcd.h"

#if defined(__GNUC__) || defined(__clang__)
// Surpress "warning: ‘y’ is used uninitialized [-Wuninitialized]"
// https://gcc.gnu.org/onlinedocs/gcc/Diagnostic-Pragmas.html
#  pragma GCC diagnostic push
#  pragma GCC diagnostic ignored "-Wunused-parameter"
#endif

int gcd_bf(int g, int k)
{
    // Implement here
    return 0;
}

int gcd_euklid(int g, int k)
{
    // Implement here
    return 0;
}

#if defined(__GNUC__) || defined(__clang__)
#  pragma GCC diagnostic pop
#endif
