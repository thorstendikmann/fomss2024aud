#include <stdio.h>

/**
 * Just defining and filling a 1D array with some elements and printing them afterwards.
 */
void arrays1d()
{
    int MAX_ELEM = 6;
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
void arraysLength()
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

/**
 * Show usage of 2D arrays in C - iterate over them, put some values in and print the final result.
 */
void arrays2d()
{
    int max_x = 15;
    int max_y = 15;
    int x[max_x][max_y];

    for (int i = 0; i < max_x; i++)
    {
        for (int j = 0; j < max_y; j++)
        {
            x[i][j] = i + j;
        }
    }

    // Output
    for (int i = 0; i < max_x; i++)
    {
        for (int j = 0; j < max_y; j++)
        {
            printf("%2.1d ", x[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    arrays1d();
    arraysLength();
    arrays2d();
    return 0;
}