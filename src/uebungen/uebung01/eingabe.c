#include <stdio.h>

#include <math.h>
/**
 * a) Lesen Sie vom Benutzer zwei Zahlenwerte \f$ x,y \elem \Z \f$ ein (scanf).
 * Gebe aus: \f$ x+y \f$ sowie \f$ x^y \f$
 */
void a_zahlenwerte(void)
{
    int x;
    int y;

    printf("Gebe zwei ganze Zahlen ein: \n");
    if (scanf("%d %d", &x, &y) == 2)
    {
        printf("Eingabe: %d, %d. Summe: %d\n", x, y, x + y);
        // Implicit conversion in pow!
        printf("Eingabe: %d, %d. Potenz: %lf\n", x, y, pow(x, y));
    }
    else
        printf("Eingabefehler");
}

#ifdef UNIX
#include <sys/param.h>
#else
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#endif
/**
 * b)	Lesen Sie vom Benutzer drei Zahlenwerte (Float) ein. Geben Sie das größte Element aus.
 */
void b_max(void)
{
    float f, g, h;

    printf("Gebe drei Fließkommazahlen ein: \n");
    if (scanf("%f %f %f", &f, &g, &h) == 3)
    {
        printf("Eingabe: %f, %f, %f. max: %f\n", f, g, h, MAX(MAX(f, g), h));
    }
    else
        printf("Eingabefehler");
}

/** Struct für Aufgabe c) */
typedef struct ad
{
    /** Adresse - Name */
    char name[50];
    /** Adresse - Straße */
    char str[100];
    /** Adresse - Postleitzahl */
    char plz[10];
    /** Adresse - Stadt */
    char stadt[30];
} addresse;

void c_printAdresse(addresse *addr)
{
    printf("Adresse: %s, %s, %s, %s",
           addr->name, addr->str, addr->plz, addr->stadt);
}

#include <stdlib.h>
#include <string.h>
/**
 * c)	Lesen Sie vom Benutzer ein (scanf, fgets): Name, Adresse, PLZ, Stadt
 *      Legen Sie ein geeignetes struct zur Speicherung dieser Daten an. Schreiben Sie eine Funktion, die ein solches Struct als Referenz übergeben bekommt und alle Daten ausgibt.
 */
void c_adresse(void)
{
    addresse addr;

    printf("Gebe Vorname und Nachname ein: \n");
    // LINUX: Better use getline()
    if (!fgets(addr.name, sizeof(addr.name), stdin))
    {
        printf("Eingabefehler");
        exit(1);
    }
    // Chop eventual trailing newlines
    // .. simply by telling C to end the string here
    addr.name[strcspn(addr.name, "\n")] = '\0';

    printf("Gebe Straße ein: \n");
    if (!fgets(addr.str, sizeof(addr.str), stdin))
    {
        printf("Eingabefehler");
        exit(1);
    }
    addr.str[strcspn(addr.str, "\n")] = '\0';

    printf("Gebe PLZ ein: \n");
    if (!fgets(addr.plz, sizeof(addr.plz), stdin))
    {
        printf("Eingabefehler");
        exit(1);
    }
    addr.plz[strcspn(addr.plz, "\n")] = '\0';

    printf("Gebe Stadt ein: \n");
    if (!fgets(addr.stadt, sizeof(addr.stadt), stdin))
    {
        printf("Eingabefehler");
        exit(1);
    }
    addr.stadt[strcspn(addr.stadt, "\n")] = '\0';

    c_printAdresse(&addr);
}

/** d)	Lesen Sie vom Benutzer drei Fließkommazahlen ein. Geben Sie an, ob sich aus diesen drei Zahlen ein Dreieck konstruieren lässt. */
void d_dreiecke(void)
{
    float x, y, z;

    printf("\nInput three float numbers: ");
    if (scanf("%f %f %f", &x, &y, &z) != 3)
    {
        printf("Error!");
    }

    // Dreiecksungleichung für alle drei Seiten
    if (x < (y + z) && y < (x + z) && z < (y + x))
    {
        printf("The following form a triangle: %f, %f, %f", x, y, z);
    }
    else
    {
        printf("Not possible to form a triangle!");
    }
}

int main(void)
{
    printf("Uncomment parts in source code.\n");
    // a_zahlenwerte();
    // b_max();
    // c_adresse();
    // d_dreiecke();
    return 0;
}
