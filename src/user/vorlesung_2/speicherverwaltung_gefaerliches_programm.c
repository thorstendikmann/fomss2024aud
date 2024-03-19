#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr = (int*)malloc(5 * sizeof(int)); // Speicher reservieren

    if (ptr == NULL) {
        printf("Speicher konnte nicht reserviert werden.\n");
        return 1;
    }

    // Werte 10 bis 14 in den Speicher schreiben
    for (int i = 0; i < 5; i++) {
        *(ptr + i) = 10 + i;
    }

    // Werte rückwärts ausgeben
    printf("Werte rückwärts: ");
    for (int i = 4; i >= 0; i--) {
        printf("%d ", *(ptr + i));
    }
    printf("\n");

    free(ptr); // Reservierten Speicher freigeben

    return 0;
}
