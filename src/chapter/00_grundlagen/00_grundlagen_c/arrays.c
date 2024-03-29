#include <stdio.h>

// Do as preprocessor const due to C2057
#define MAX_ELEM 6

/**
 * Just defining and filling a 1D array with some elements and printing them afterwards.
 */
void arrays1d(void)
{
    float measurements[MAX_ELEM];

    measurements[0] = 17.0;
    measurements[1] = 17.9;
    measurements[2] = 18.2;
    measurements[3] = 18.7;
    measurements[4] = 19.2;
    measurements[5] = 20.0;

    printf("First measurement (Index 0): %.2f\n", measurements[0]);

    // Iterate over array elements
    for (int i = 0; i < MAX_ELEM; i++)
    {
        printf("%d. measurement: %.2f\n", i, measurements[i]);
    }
}

/**
 * Calculate the length of an array.
 */
void arraysLength(void)
{
    float measurements[3];

    measurements[0] = 17.0;
    measurements[1] = 17.9;
    measurements[2] = 18.2;

    int arrayLength = sizeof(measurements) / sizeof(float);

    printf("Length of measurement: %d Elements\n", arrayLength);
    for (int i = 0; i < arrayLength; i++)
    {
        printf("%d. measurement: %.2f\n", i, measurements[i]);
    }
}

// C2057
#define MAX_X 15
#define MAX_Y 15
/**
 * Show usage of 2D arrays in C - iterate over them, put some values in and print the final result.
 */
void arrays2d(void)
{
    int x[MAX_X][MAX_Y];

    for (int i = 0; i < MAX_X; i++)
    {
        for (int j = 0; j < MAX_Y; j++)
        {
            x[i][j] = i + j;
        }
    }

    // Output
    for (int i = 0; i < MAX_X; i++)
    {
        for (int j = 0; j < MAX_Y; j++)
        {
            printf("%2.1d ", x[i][j]);
        }
        printf("\n");
    }
}

int main(void)
{
    arrays1d();
    arraysLength();
    arrays2d();
    return 0;
}
