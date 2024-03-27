#include <stdio.h>
#include <math.h>

int main() {
    int x, y;
    printf("Geben Sie zwei ganze Zahlen ein: ");
    scanf("%d %d", &x, &y);
    printf("Multiplikationsergebnis: %d\n", x * y);
    printf("Potenzergebnis: %.0f\n", pow(x, y));
    return 0;
}
