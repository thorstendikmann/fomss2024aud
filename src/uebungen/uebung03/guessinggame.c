#include <stdio.h>

int secret_number = -1;

/**
 * Response of player A in the guessing game.
 *
 * @param guess the guess from player B.
 * @param steps pointer to an int to count the number of times player A has been asked.
 * @return  0, if the guess is correct;
 *          1, if the guess is less than the secret number;
 *          -1, if the guess is greater than the secret number
 */
int response(int guess, int *steps)
{
    // printf("- %s, %d\n", __func__, __LINE__);
    (*steps)++; // increment every time being asked ...

    //printf("Current guess: %d\n", guess);

    if (guess == secret_number)
        return 0; // Correct!
    else if (guess < secret_number)
        return 1; // Bigger!
    else
        return -1; // Smaller!
}

/**
 * Find number of guessing game using a brute-force approach.
 * @param min_number starting point of the function
 * @param max_number upper limit of the function
 * @param steps pointer to an int to count the number of times player A has been asked.
 * @return the guessed number (if found ...)
 */
int find_number_bf(int min_number, int max_number, int *steps)
{
    // printf("- %s, %d\n", __func__, __LINE__);
    for (int guess = min_number; guess <= max_number; guess++)
    {
        if (response(guess, steps) == 0)
        {
            return guess;
        }
    }
    return -1; // Number not found. Should never happen.
}

/**
 * Find number of guessing game using a divide-and-conquer approach.
 * 
 * Idea: Choose number in half of interval. If larger, half again in the upper part - if smaller, half again in the lower part.
 * 
 * @param min_number starting point of the function
 * @param max_number upper limit of the function
 * @param steps pointer to an int to count the number of times player A has been asked.
 * @return the guessed number (if found ...)
 */
int find_number_dc(int min_number, int max_number, int *steps)
{
    //printf("- %s, %d\n", __func__, __LINE__);
    int result = 0;
    int guess = 0;
    do
    {
        guess = (max_number + min_number) / 2;
        result = response(guess, steps);
        if (result > 0)
        {
            // Number is greater than guess, increase min_number (by 1/2 of the remaining interval)
            min_number = guess + 1;
        }
        else if (result < 0)
        {
            // Number is less than guess, decrease max_number (by 1/2 of the remaining interval)
            max_number = guess - 1;
        }
    } while (result != 0);

    return guess;
}

/**
 * Find number of guessing game using a recursive divide-and-conquer approach.
 * @param min_number starting point of the function
 * @param max_number upper limit of the function
 * @param steps pointer to an int to count the number of times player A has been asked.
 * @return the guessed number (if found ...)
 */
int find_number_dcr(int min_number, int max_number, int *steps)
{
    //printf("- %s, %d\n", __func__, __LINE__);
    int guess = (max_number + min_number) / 2;
    int result = response(guess, steps);
    if (result > 0)
    {
        // Number is greater than guess, increase min_number
        return find_number_dcr(guess + 1, max_number, steps);
    }
    else if (result < 0)
    {
        // Number is less than guess, decrease max_number
        return find_number_dcr(min_number, guess - 1, steps);
    }
    else // result == 0
    {
        return guess;
    }
}

int main(void)
{
    printf("- %s, %d\n", __func__, __LINE__);
    int min_number = 0;
    int max_number = 200;
    secret_number = 73;

    int t_steps = -1;

    printf("Brute-force solution:        %5d", find_number_bf(min_number, max_number, &t_steps));
    printf("- %5d steps\n", t_steps);
    t_steps = 0;

    printf("Divide-and-conquer solution: %5d", find_number_dc(min_number, max_number, &t_steps));
    printf("- %5d steps\n", t_steps);
    t_steps = 0;

    printf("Rec Div-and-Cq solution:     %5d", find_number_dcr(min_number, max_number, &t_steps));
    printf("- %5d steps\n", t_steps);
    t_steps = 0;

    return 0;
}