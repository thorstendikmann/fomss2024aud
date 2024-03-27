#include <stdio.h>

void errorHandling(char *input) {
    float destFloat;
    int result = sscanf(input, "%f", &destFloat);
    if (result == 1) {
        float celsius = (destFloat - 32) * 5 / 9;
        printf("Das entspricht: %.2f Grad Celsius.\n", celsius);
    } else {
        printf("Etwas ist schiefgegangen bei der Eingabe \"%s\". Bitte geben Sie eine gültige Zahl ein.\n", input);
    }
}

int main() {
    char input[100];
    printf("Bitte geben Sie die Temperatur in Grad Fahrenheit ein: ");
    fgets(input, 100, stdin);

    errorHandling(input);

    return 0;
}

