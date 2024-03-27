#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>

/**
 * Inverse square root \f$ \frac{1}{\sqrt{(\mathrm{number})}} \f$ utilizing libc's sqrt().
 * @return the inverse square root of number
 * @param number the input.
 */
float inv_sqrt_lib(float number)
{
    return (1 / sqrt(number));
}

/**
 * Calculates the inverse square root \f$ \frac{1}{\sqrt{(\mathrm{number})}} \f$ "by feet" - using pow and division.
 * @return the inverse square root of number
 * @param number the input.
 */
float inv_sqrt(float number)
{
    float sqrtN = pow(number, 0.5);
    return (1 / sqrtN);
}

// Surpress "warning: ‘y’ is used uninitialized [-Wuninitialized]"
// https://gcc.gnu.org/onlinedocs/gcc/Diagnostic-Pragmas.html
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wuninitialized"
/**
 * This is the id-Software Quake III "inverse squareroot" algorithm.
 * @return the inverse square root of number
 * @param number the input.
 * Origin: https://github.com/id-Software/Quake-III-Arena/blob/dbe4ddb10315479fc00086f08e25d968b4b43c49/code/game/q_math.c#L552
 */
float Q_rsqrt(float number)
{
    long i;
    float x2, y;
    const float threehalfs = 1.5F;

    x2 = number * 0.5F;
    y = number;
    // cppcheck-suppress [invalidPointerCast]
    i = *(long *)&y;           // evil floating point bit level hacking
    i = 0x5f3759df - (i >> 1); // what the f*ck?
    // cppcheck-suppress [invalidPointerCast]
    y = *(float *)&i;
    y = y * (threehalfs - (x2 * y * y));       // 1st iteration
    /* y = y * (threehalfs - (x2 * y * y)); */ // 2nd iteration, this can be removed

    return y;
}

// Return back to diagnostics settings before.
#pragma GCC diagnostic pop

/**
 * Helper function to printf a given int in binary representation.
 */
void display_binary(int n)
{
    char arr[32];
    int top = -1;

    while (n)
    {
        if (n & 0x01)
            arr[++top] = 1;
        else
            arr[++top] = 0;

        n >>= 1;
    }
    printf("0b");
    for (int i = top; i > -1; i--)
    {
        printf("%d", arr[i]);
    }
    printf("\n");
}

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

    // ------------- inv_sqrt

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

    printf("Faking usage of res to avoid optimization %f \n", res);
}

/**
 * Compares the two algorithms and calculates the maximal difference between the results.
 */
void compareISqrtAlgs(void)
{
    printf("- %s, %d\n", __func__, __LINE__);

    // iteration control
    float start = 0.00001;
    float stop = 15000;
    float increment = 0.0005;

    float maxDifference = 0.0;
    float maxDifferencePz = 0.0;
    float totalDifference = 0.0;
    float totalDifferencePz = 0.0;
    long iterations = 0;
    for (float i = start; i < stop; i += increment)
    {
        float resA = inv_sqrt_lib(i);
        float resB = Q_rsqrt(i);
        float difference = fabs(resB - resA);
        float differencePz = (fabs(resB - resA) / resB) * 100;

        totalDifference += difference;
        totalDifferencePz += differencePz;
        iterations++;

        maxDifference = ((difference) > (maxDifference) ? difference : maxDifference);
        maxDifferencePz = ((differencePz) > (maxDifferencePz) ? differencePz : maxDifferencePz);
    }

    float meanDiff = totalDifference / iterations;
    float meanDiffPz = totalDifferencePz / iterations;

    printf("Maximal difference in algorithms: %f (%f%%). Mean: %f (%f%%) \n", maxDifference, maxDifferencePz, meanDiff, meanDiffPz);
}

#include <stdint.h>
#include <limits.h> /* for CHAR_BIT */
/**
 * Formatted output of ieee-754 representation of float.
 * @param f the float to be printed.
 * Source: https://stackoverflow.com/questions/44609743/obtaining-bit-representation-of-a-float-in-c
 */
void show_ieee754(float f)
{
    union
    {
        // cppcheck-suppress [unusedStructMember]
        float f;
        uint32_t u;
    } fu = {.f = f};
    int i = sizeof f * CHAR_BIT;

    printf("  ");
    while (i--)
        printf("%u ", (fu.u >> i) & 0x1);

    putchar('\n');
    printf(" |- - - - - - - - - - - - - - - - - - - - - - "
           "- - - - - - - - - -|\n");
    printf(" |s|      exp      |                  mantissa"
           "                   |\n\n");
}

/**
 * Struct to split up Floating Point numbers.
 *
 * Source / Idea: https://stackoverflow.com/questions/15685181/how-to-get-the-sign-mantissa-and-exponent-of-a-floating-point-number
 * There are more sophisticated methods than the one below ...
 */
typedef union
{
    /** The actual float number. */
    float f;
    struct
    {
        /** Mantisa part of the float. */
        unsigned int mantisa : 23;
        /** Exponent part of the float. */
        unsigned int exponent : 8;
        /** Sign bit of the float. */
        // cppcheck-suppress [unusedStructMember]
        unsigned int sign : 1;
    }
    /** ... what the float internally bitwise consists of. */ 
    parts;
} float_cast;

/**
 * Some demonstration how IEEE 754 floating point numbers internally work.
 */
void funWithIEEE754(void)
{
    printf("\n\n");
    printf("Some binary numbers:\n");
    printf("  %4d ->:", 4);
    display_binary(4);
    printf("  %4d ->:", 8);
    display_binary(8);
    printf("  %4d ->:", 16);
    display_binary(16);

    {
        printf("\n\n");
        float_cast fc = {.f = 2.0};
        printf("Float representation of %5.2f\n", fc.f);
        show_ieee754(fc.f);
        printf(" %5.2f -> Chr: %3u | Man:   %3u\n", fc.f, fc.parts.exponent, fc.parts.mantisa);
        printf("          Exp: %3u | Man: 1,%3u\n", fc.parts.exponent - 127, fc.parts.mantisa);
    }

    {
        printf("\n\n");
        float_cast fc = {.f = 4.0};
        printf("Float representation of %5.2f\n", fc.f);
        show_ieee754(fc.f);
        printf(" %5.2f -> Chr: %3u | Man:   %3u\n", fc.f, fc.parts.exponent, fc.parts.mantisa);
        printf("          Exp: %3u | Man: 1,%3u\n", fc.parts.exponent - 127, fc.parts.mantisa);
    }

    {
        printf("\n\n");
        float_cast fc = {.f = 8.0};
        printf("Float representation of %5.2f\n", fc.f);
        show_ieee754(fc.f);
        printf(" %5.2f -> Chr: %3u | Man:   %3u\n", fc.f, fc.parts.exponent, fc.parts.mantisa);
        printf("          Exp: %3u | Man: 1.%u\n", fc.parts.exponent - 127, fc.parts.mantisa);
    }

    {
        printf("\n\n");
        float_cast fc = {.f = 16.0};
        printf("Float representation of %5.2f\n", fc.f);
        show_ieee754(fc.f);
        printf(" %5.2f -> Chr: %3u | Man:   %3u\n", fc.f, fc.parts.exponent, fc.parts.mantisa);
        printf("          Exp: %3u | Man: 1.%u\n", fc.parts.exponent - 127, fc.parts.mantisa);
        printf("\n");

        printf("Reduce Exp by 1:\n");
        // Reducing Exp by 1 = Number from 16 (2^4) -> 8 (2^3)
        fc.parts.exponent = fc.parts.exponent - 1;
        printf("Float representation of %5.2f\n", fc.f);
        show_ieee754(fc.f);
        printf(" %5.2f -> Chr: %3u | Man:   %3u\n", fc.f, fc.parts.exponent, fc.parts.mantisa);
        printf("          Exp: %3u | Man: 1.%u\n", fc.parts.exponent - 127, fc.parts.mantisa);

        printf("Inc mantisa by 1:\n");
        // Reducing Exp by 1 = Number from 16 (2^4) -> 8 (2^3)
        fc.parts.mantisa = fc.parts.mantisa + (1 << 22);
        printf("Float representation of %5.2f\n", fc.f);
        show_ieee754(fc.f);
        printf(" %5.2f -> Chr: %3u | Man:   %3u\n", fc.f, fc.parts.exponent, fc.parts.mantisa);
        printf("          Exp: %3u | Man: 1.%u\n", fc.parts.exponent - 127, fc.parts.mantisa);

        // Example how to "shift the comma" by the exponent
        int result = 1; // IEEE 754 ignors the 1, so let's add it.
        // Iterate over all digits from the mantisa as indicated by the exponent ("move the comma")
        for(int i = 0; i < fc.parts.exponent - 127; ++i){
            result = result << 1; // next bit in result ...
            int bitmaskFirstBit = (1 << 22);
            if(fc.parts.mantisa & bitmaskFirstBit) // ... depends on the currently first bit of the mantisa
            {
                result++;
            }
            fc.parts.mantisa = fc.parts.mantisa << 1; // shift left the mantisa one bit.
        }
        printf("   Digits (before comma): %d\n", result);
    }
}

int main(void)
{
    benchmarkISqrtAlgs();
    compareISqrtAlgs();
    funWithIEEE754();

    return 0;
}
