#include <stdio.h>
#include <stdlib.h>

#include "gcd.h"

int main(void)
{
    printf("gcf(15,5) -> %d\n", gcd_bf(15, 5));
    printf("gcf(24,12) -> %d\n", gcd_bf(24, 12));
    printf("gcf(99,88) -> %d\n", gcd_bf(99, 88));
    printf("gcf(27972,9100) -> %d\n", gcd_bf(27972, 9100));
    printf("gcf(3464,3463) -> %d\n", gcd_bf(3464, 3463));
    printf("\n");
    printf("gcf(15,5) -> %d\n", gcd_euklid(15, 5));
    printf("gcf(24,12) -> %d\n", gcd_euklid(24, 12));
    printf("gcf(99,88) -> %d\n", gcd_euklid(99, 88));
    printf("gcf(27972,9100) -> %d\n", gcd_euklid(27972, 9100));
    printf("gcf(3464,3463) -> %d\n", gcd_euklid(3464, 3463));
    return 0;
}
