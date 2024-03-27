#include <stdio.h>

/**
 * a) Schreiben Sie ein Programm, welches die geraden Nummern zwischen 1 und 50 (inkl.) ausgibt.
 */
void evenNumbers(void)
{
    printf("- %s, %d\n", __func__, __LINE__);

    for (int i = 2; i <= 50; i = i + 2)
    {
        printf("Current value: %d\n", i);
    }
}

#include <math.h>
/**
 * Checks for z being prime.
 * @param z the number to be checked
 * @return 1 if z is prime, 0 otherwise
 */
int isPrime(int z)
{
    // Abbruchbedingung - suche bis zur Quadratwurzel
    int sqrtZ = (int)ceil(sqrt(z));

    if (z > 1)
    {
        for (int i = 2; i <= sqrtZ; i++)
        {
            // printf("z: %d | i: %d\n", z, i);
            if ((z % i) == 0)
            {
                // Teiler gefunden
                // printf("Weiterer Teiler von %d: %d\n", z, i);
                return (0);
            }
        }
    }
    else
    {
        printf("Außerhab gültigen Bereichs.");
        return (0);
    }

    // Kein anderer Teiler gefunden
    return (1);
}

/**
 * Schreiben Sie ein Programm, welches die Primzahlen zwischen 2 und 1000 ausgibt.
 * Implementieren Sie hierzu eine Funktion isPrime(int), welche "herkömmlich" mit einer Schleife alle möglichen Teiler ausfindig macht.
 *
 * @param maxNumber Upper boundary to check until.
 * @param output Set to 1 for printf the result.
 */
void primeNumbers(int maxNumber, char output)
{
    printf("- %s, %d\n", __func__, __LINE__);

    for (int i = 2; i <= maxNumber; i++)
    {
        if (isPrime(i))
        {
            if (output)
                printf("Primzahl: %d\n", i);
        }
    }
}

#include <string.h>
/**
 * c)	Schreiben Sie ein weiteres Programm, welches die Primzahlen zwischen 2 und 1000 ausgibt.
 * Verwenden Sie dieses Mal den Algorithmus „Sieb von Eratosthenes“.
 *
 * @param maxNumber Upper boundary to check until.
 * @param output Set to 1 for printf the result.
 */
void primeNumbersSieveOfEratosthenes(int maxNumber, char output)
{
    printf("- %s, %d\n", __func__, __LINE__);

    // Create array where we keep track of a number having dividers
    // "1" at a position => number is prime.
    char prime[maxNumber + 1];
    // Initialize all with "is prime"
    memset(prime, 1, sizeof(prime));

    // Loop until sqrt(maxNumber) => p * p <= maxNumber faster than sqrt!
    for (int p = 2; p * p <= maxNumber; p++)
    {
        // printf("Current number: %d - %d\n", p, prime[p]);

        // If current number already detected as not prime,
        // we do not need to check. E.g. 6 -> 3 already checked.
        if (prime[p] == 1)
        {
            // Update all multiples of p
            for (int i = p + p; i <= maxNumber; i += p)
            {
                // printf("    -- %d multiplier of %d \n", i, p);
                prime[i] = 0;
            }
        }
    }

    // Print all prime numbers
    if (output)
    {
        for (int p = 2; p <= maxNumber; p++)
            if (prime[p])
                printf("Prime: %d\n", p);
    }
}

#include <time.h>
/**
 * d)	Erweitern Sie c) und d) um eine Funktion zum Messen der Ausführungsgeschwindigkeit und starten sie einen Geschwindigkeitsvergleich (ohne Ausgabe!).
 */
void timeMeasurements(void)
{

    // With time measurements
    int maxNumer = 3000000;
    clock_t t_start, t_stop;
    double runtime;

    printf("Starting benchmark ... \n");

    // ------------- Traditional

    t_start = clock();
    primeNumbers(maxNumer, 0);
    t_stop = clock();

    runtime = ((double)t_stop - t_start) / CLOCKS_PER_SEC; // in seconds
    printf("Runtime %lf for traditional function \n", runtime);

    // ------------- Sieve of Eratosthenes

    t_start = clock();
    primeNumbersSieveOfEratosthenes(maxNumer, 0);
    t_stop = clock();

    runtime = ((double)t_stop - t_start) / CLOCKS_PER_SEC; // in seconds
    printf("Runtime %lf for SieveOfEratosthenes function \n", runtime);
}

int main(void)
{
    evenNumbers();
    primeNumbers(100, 1);
    primeNumbersSieveOfEratosthenes(100, 1);

    // Aufgabe d)
    timeMeasurements();

    return 0;
}
