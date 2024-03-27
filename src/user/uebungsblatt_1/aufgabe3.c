#include <stdio.h>

int main() {
    int days = 1331;
    int years, weeks, remainingDays;

    // Ein Jahr hat 365 Tage
    years = days / 365;
    // Verbleibende Tage nach Umrechnung in Jahre
    days = days % 365;
    // Eine Woche hat 7 Tage
    weeks = days / 7;
    // Verbleibende Tage nach Umrechnung in Wochen
    remainingDays = days % 7;

    printf("%d Tage = %d Jahre, %d Wochen und %d Tage\n", 1331, years, weeks, remainingDays);

    return 0;
}
