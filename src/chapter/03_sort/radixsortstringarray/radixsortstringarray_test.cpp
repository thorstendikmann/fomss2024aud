#include <iostream>
#include <string>

#include "radixsortstringarray.h"

int main()
{
    std::cout << "#---- Radixsort on strings." << std::endl;
    {
        fom::AuD::RadixSortStringArray array;
        array.fromVector(
            {
                "hello",
                "world",
                "test",
                "c++",
                "hallo",
                "algorithm",
                "hejho",
                "datastructure"
            }
        );

        std::cout << array << std::endl;

        array.sort_radixsort();
        std::cout << array << std::endl;
    }

    return 0;
}