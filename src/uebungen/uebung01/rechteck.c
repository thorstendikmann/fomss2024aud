#include <stdio.h>

/** Datenstruktur zum Speichern eines Rechtecks. */
typedef struct rechteck
{
    /** Breite */
    float breite;
    /** Länge */
    float laenge;
} rechteck;

/** Gebe den Umfang des übergebenen rechtecks aus. */
void calcAndPrintUmfang(rechteck *r)
{
    float umfang = 2 * r->breite + 2 * r->laenge;
    printf("Umfang: %f\n", umfang);
}
/** Gebe die Fläche des übergebenen rechtecks aus. */
void calcAndPrintFlaeche(rechteck *r)
{
    float flaeche = r->breite * r->laenge;
    printf("Flache: %f\n", flaeche);
}

int main(void)
{
    rechteck reck;
    reck.breite = 10.0;
    reck.laenge = 5.0;

    printf("Rechteck: Länge: %f, Breite: %f\n", reck.laenge, reck.breite);

    calcAndPrintUmfang(&reck);
    calcAndPrintFlaeche(&reck);
    return 0;
}
