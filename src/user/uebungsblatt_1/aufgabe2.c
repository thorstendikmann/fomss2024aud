#include <stdio.h>
typedef struct
{
    float breite;
    float laenge;
} rechteck;
void calcAndPrintUmfang(rechteck *r)
{
    float umfang = 2*(r->breite + r->laenge);
    printf("Umfang des Rechtecks: %f\n", umfang);
}
void calcAndPrintFlaeche(rechteck *r)
{
    float flaeche = r->breite * r->laenge;
    printf("Flaeche des Rechtecks: %f\n", flaeche);
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