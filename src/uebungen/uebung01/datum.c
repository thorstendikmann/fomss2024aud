#include <stdio.h>

int main(void)
{
    int days = 1331;

    int tmp, y, w, d;

    tmp = days; // Save origin

    y = days / 365;         // how many years in "tage"?
    tmp = days - (y * 365); // tmp now contains remaining days

    w = tmp / 7;       // how many weeks in remaining days?
    d = tmp - (w * 7); // d contains rest

    printf("%d days: %d Y, %d wks, %d d\n", days, y, w, d);

    return 0;
}
