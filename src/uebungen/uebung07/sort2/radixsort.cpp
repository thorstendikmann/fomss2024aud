#include <iostream>
#include <string>

#include "radixsortarray/radixsortarray.h"

int main()
{
    std::cout << "#---- Radixsort." << std::endl;
    {
        fom::AuD::RadixSortArray array;

        array.push_back(319);
        array.push_back(4938);
        array.push_back(17);
        array.push_back(476);
        array.push_back(127);
        array.push_back(14);
        array.push_back(9572);
        array.push_back(3);
        array.push_back(1597);
        array.push_back(751);
        array.push_back(198);
        array.push_back(374);
        array.push_back(263);
        array.push_back(42);
        std::cout << array << std::endl;

        array.sort_radixsort();
        std::cout << array << std::endl;
    }

    return 0;
}