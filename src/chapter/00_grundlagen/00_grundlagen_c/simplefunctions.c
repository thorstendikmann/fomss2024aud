#include <stdio.h>

void simplePrints()
{
	printf("String: %s\n", "a string");
	printf("Int: %i\n", 42);
	printf("Float: %f\n", 33.33);
}

void simpleVariables()
{
	char *telnummer;
	telnummer = "02513315";
	telnummer = "0251 91 55 846";
	printf("Telefon: %s\n", telnummer);
}

#include <math.h>
void simpleArithmetic()
{
	int answer = 46 - 4;
	printf("... the answer to life, the universe and everything - %d\n", answer);
	printf("... is the answer true? - %d\n", (17 + 4) * 2 == 42);

	printf("Power 2^4: %f\n", pow(2, 4));
}

#include <stdlib.h>
#include <time.h>
void simpleBranch()
{
	srand(time(NULL)); // <- <time.h>, init randomizer
	int num = rand() % 10;

	if (num > 5)
	{
		printf("Random number %d is >5.\n", num);
	}
	else if (num < 5)
		printf("Random number %d is <5.\n", num);
	else
		printf("Random number %d is exactly 5!\n", num);
}

#include <stdlib.h>
#include <time.h>
void simpleSwitch()
{
	srand(time(NULL));
	// 65 = 'A', 66 = 'B' ... ASCII !!
	char c = 65 + rand() % 26;

	switch (c)
	{
	case 'A':
		printf("%c is an \"A\"!\n", c);
		break;
	case 'B':
		printf("%c is a \"B\"!\n", c);
		break;
	case 'C':
		printf("%c is a \"C\"!\n", c);
		break;
	default:
		printf("%c is an something else!\n", c);
		break;
	}
}

void simpleLoops(int maxRuns)
{
	int i = maxRuns;
	while (i-- > 0)
	{
		printf("while %d!\n", i);
	}

	int j;
	for (j = 0; j < maxRuns; j++)
	{
		printf("for %d!\n", j);
	}

	do
	{
		printf("do .. while %d!\n", j);
		if (j < 3)
		{
			printf("breaking...\n");
			break;
		}
	} while (j-- > 0);
}

/**
 * Print the size in bytes of common datatypes.
 */
void sizeOfs()
{
	printf("The size of char is %d byte\n", (int)sizeof(char));
	printf("The size of short is %d bytes\n", (int)sizeof(short));
	printf("The size of int is %d bytes\n", (int)sizeof(int));
	printf("The size of long is %d bytes\n", (int)sizeof(long));
	printf("The size of int* is %d bytes\n", (int)sizeof(int *));
	printf("The size of void* is %d bytes\n", (int)sizeof(void *));
	printf("The size of float is %d bytes\n", (int)sizeof(float));
}

/**
 * Print degrees in Celcius and Fahrenheit.
 * Inspired by: The C Programming Language, Brian W. Kernighan, Dennis M. Ritchie, 1988
 */
void c_fahrenheit()
{
	int fahr, celsius;
	int lower, upper, step;

	lower = -40;
	upper = 300;
	step = 20;

	fahr = lower;
	while (fahr <= upper)
	{
		celsius = 5 * (fahr - 32) / 9;
		printf("%3.1d F\t%4.1d C\n", fahr, celsius);
		fahr += step;
	}
}

#include <string.h>
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
 * Prints the result of some binary operations in C.
 */
void bitwiseOperations()
{
	// 11111111 -> 0xFF || 0b1011 -> 0x0B
	printf("11111111 & 0b1011 -> ");
	display_binary(0xFF & 0x0B);

	// 0b010101010 -> 0xAA
	printf("0b010101010 | 0b1011 -> ");
	display_binary(0xAA | 0x0B);

	printf("0b010101010 ^ 0b1011 -> ");
	display_binary(0xAA ^ 0x0B);

	// 0b11101010 -> 0xEA
	printf("0b11101010 << 2 -> ");
	display_binary(0xEA << 2);

	printf("0b11101010 >> 3 -> ");
	display_binary(0xEA >> 3);

	printf("0xFFFF << 2 -> ");
	display_binary(0xFFFF << 2);
}

/**
 * Goto. Considered harmful.
 * Demonstration of the goto command - which almost never should be used.
 * See: https://homepages.cwi.nl/~storm/teaching/reader/Dijkstra68.pdf
 */
void gotoConsideredHarmful()
{
	int i, j, k;
	// Deeply nested loop .. jump out early when conditions met.
	for (i = 1; i < 10; i++)
	{
		for (j = 1; j < 10; j++)
		{
			for (k = 1; k < 10; k++)
			{
				if (i == 5 && j == 8 && k == 6)
					goto OUT;
			}
		}
	}
OUT:
	printf("Went out at: i=%d, j=%d, k=%d \n", i, j, k);
}

// Macros
#define VALUE 134.3
#define max(A, B) ((A) > (B) ? (A) : (B))

/**
 * Shows how preprocessor macros can be used.
 */
void preprocessorMacros()
{
	float a = VALUE;
	printf("a has the value: %f\n", a);

	printf("max(3, 5)? -> %d\n", max(3, 5));
	printf("max(66.9, 78.3)? -> %f\n", max(66.9, 78.3));
}

/**
 * Example for error handling in C based on return code.. There are no Exceptions in C!!
 */
void errorHandling()
{
	int destInt = 0;
	char sentence[] = "This does not contain a number.";
	int result = sscanf(sentence, "%d", &destInt);
	if (result)
		printf("Found a number: \"%d\"", destInt);
	else
		printf("Something went wrong while parsing \"%s\" for a number.", sentence);
}

#include <errno.h>
/**
 * A bit more sophisticated error handling with errno.
 */
void errorHandlingWithErrno()
{
	FILE *file;
	file = fopen("iDoNotExist.txt", "r");

	if (file == NULL)
	{
		fprintf(stderr, "Value of errno: %d\n", errno);
		perror("Error printed by perror");
		fprintf(stderr, "Error opening file: %s\n", strerror(errno));
	}
	else
		fclose(file);
}

int main()
{
	simplePrints();
	simpleVariables();
	simpleArithmetic();
	simpleBranch();
	simpleSwitch();
	simpleLoops(5);
	sizeOfs();
	c_fahrenheit();
	bitwiseOperations();
	gotoConsideredHarmful();
	preprocessorMacros();
	errorHandling();
	errorHandlingWithErrno();
	return 0;
}