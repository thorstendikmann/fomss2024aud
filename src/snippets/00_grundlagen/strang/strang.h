#ifndef STRANG_H
#define STRANG_H

#include <string>
#include <iostream>

/**
 * Demo C++ class, just containing a string.
 */
class Strang
{
private:
    /** Internal storage: str. */
    std::string str;

public:
    /**
     * Constructor mit Initialisierung.
     *
     * Hinweis: hier per Referenz übergeben, weil der Inhalt
     * ohnehin intern in str (automatisch) kopiert wird.
     *
     * @param val String zur internen Speicherung.
     */
    explicit  Strang(const std::string &val);

    /**
     * @return Intern gespeicherter String.
     */
    std::string getString() const;

    /**
     * Setze intern gespeicherten wert.
     * @param val neuer Wert für internen String.
     */
    void set(const std::string &val);

    /**
     * Gibt eine String-Repräsentation von Strang zurück.
     * @return Strang als string.
     */
    std::string toString() const;
};

/**
 * Überlade "<<" Operator für Klasse Strang.
 * @param os der Ziel-Ausgabestream
 * @param o die Klasse Strang
 */
std::ostream &operator<<(std::ostream &os, const Strang &o);

#endif // STRANG_H