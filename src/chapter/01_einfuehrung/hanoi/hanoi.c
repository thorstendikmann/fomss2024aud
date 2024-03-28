#include <stdio.h>
#include <stdlib.h>

int steps = 0;

/**
 * Recursive implementation of the Towers of Hanoi problem.
 * @param n Number of discs
 * @param A Name of Tower "A"
 * @param B Name of Tower "B"
 * @param C Name of Tower "CC"
 */
void hanoi(int n, char A, char B, char C)
{
    if (n == 1)
    {
        steps++;
        printf("%5d - Move %c -> %c\n", steps, A, C);
        return;
    }
    hanoi(n - 1, A, C, B);
    hanoi(1, A, B, C);
    hanoi(n - 1, B, A, C);
}

int main(void)
{
    hanoi(5, 'A', 'B', 'C');
    return 0;
}
