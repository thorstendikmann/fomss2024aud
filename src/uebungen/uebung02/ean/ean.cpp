#include <iostream>
#include <string>
#include <vector>
#include <list>

/** Some data structure for the EAN. */
typedef std::vector<unsigned int> EAN;

/**
 * Does the internal calculation for the check digit.
 * @param ean the EAN number, given as EAN datastructure.
 * @return unsigned digit with the "Prüfziffer"
*/
unsigned int getPruefziffer(const EAN &ean)
{
    // Calculate pruefziffer
    // summe01 = 1. + 3. + 5. ... + 11. digit
    unsigned int summe01 = ean[0] + ean[2] + ean[4] + ean[6] + ean[8] + ean[10];
    // summe02 = 2. + 4. + 6. ... + 12. digit
    unsigned int summe02 = ean[1] + ean[3] + ean[5] + ean[7] + ean[9] + ean[11];

    unsigned int addResult = summe01 + 3 * summe02;

    // Search for next number dividable by 10.
    unsigned int next10 = addResult;
    for (std::size_t i = 0; i < 10; ++i)
    {
        if (next10 % 10 == 0)
            break;
        next10++;
    }

    // Result is the difference of both numbers
    return (next10 - addResult);
}

std::ostream &operator<<(std::ostream &os, const EAN &o)
{
    for (EAN::const_iterator it = o.begin(); it != o.end(); ++it)
    {
        os << (char)(48 + *it); // 48 = ASCII "0"
    }
    return os;
}

int main()
{
    std::list<EAN> listOfEANs;
    listOfEANs.push_back({4, 0, 1, 2, 7, 0, 0, 9, 6, 3, 1, 0, 9});
    listOfEANs.push_back({4, 0, 1, 7, 0, 7, 4, 0, 5, 6, 5, 5, 6});
    listOfEANs.push_back({4, 0, 0, 1, 7, 2, 4, 0, 3, 3, 4, 6, 2}); // ... some pizza ...
    listOfEANs.push_back({3, 7, 7, 0, 0, 0, 0, 0, 1, 0, 6, 0, 2}); // ... a cardgame

    for (std::list<EAN>::const_iterator it = listOfEANs.begin();
         it != listOfEANs.end();
         ++it)
    {
        std::cout << "Prüfziffer für " << *it << " lautet: " << getPruefziffer(*it) << " - Check: " << (*it)[12] << std::endl;
    }

    return 0;
}