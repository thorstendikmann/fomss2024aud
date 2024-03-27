#ifndef ZEIT_H
#define ZEIT_H

#include <iostream>

/**
 * Demo C++ Klasse zur Speicherung der Uhrzeit.
 */
class Zeit
{
private:
    /** Internal storage: stunde. */
    int stunde;
    /** Internal storage: minute. */
    int minute;

public:
    /**
     * Constructor mit Initialisierung.
     * @param st Stunde.
     * @param mi Minute.
     */
    Zeit(int st, int mi);

    /**
     * @return Intern gespeicherte Stunde.
     */
    int getStunde() const;

    /**
     * @return Intern gespeicherte Minute.
     */
    int getMinute() const;

    /**
     * Setze Stunde und Minute.
     * @param st neuer Wert für Stunde
     * @param mi neuer Wert für Minute
     */
    void set(int st, int mi);

    /**
     * Gibt eine String-Repräsentation der Zeit zurück.
     * @return Zeit als string.
     */
    std::string toString() const;
};

/**
 * Überlade "<<" Operator für Klasse Zeit.
 * @param os der Ziel-Ausgabestream
 * @param o die Klasse Zeit
 */
std::ostream &operator<<(std::ostream &os, const Zeit &o);

#endif // ZEIT_H