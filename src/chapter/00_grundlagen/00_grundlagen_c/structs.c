#include <stdio.h>
#include <string.h>

struct address
{
    char name[100];
    char street[100];
    short number;
    int postal;
    char city[50];
};

/**
 * Illustrates how to use the previously defined struct "address".
 */
void structUsage()
{
    struct address addressInstance;

    // strcpy - copy string to string array destination
    strcpy(addressInstance.name, "Jansch Mustermann");
    strcpy(addressInstance.street, "Baumallee");
    addressInstance.number = 42;
    addressInstance.postal = 48165;
    strcpy(addressInstance.city, "Münster");

    printf("Struct name: %s\n", addressInstance.name);
    printf("Struct street: %s\n", addressInstance.street);
    printf("Struct number: %d\n", addressInstance.number);
    printf("Struct postal: %d\n", addressInstance.postal);
    printf("Struct city: %s\n", addressInstance.city);
}

int main()
{
    structUsage();
    return 0;
}