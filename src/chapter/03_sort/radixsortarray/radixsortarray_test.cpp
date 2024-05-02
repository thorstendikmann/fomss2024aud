#include <iostream>
#include <string>

#include "radixsortarray.h"

int main()
{
    std::cout << "#---- Radixsort." << std::endl;
    {
        fom::AuD::RadixSortArray array;

        array.push_back(170);
        array.push_back(45);
        array.push_back(75);
        array.push_back(90);
        array.push_back(802);
        array.push_back(24);
        array.push_back(2);
        array.push_back(66);
        std::cout << array << std::endl;

        array.sort_radixsort();
        std::cout << array << std::endl;
    }

    std::cout << "#---- Example from slides" << std::endl;
    {
        fom::AuD::RadixSortArray array;

        array.push_back(429);
        array.push_back(3309);
        array.push_back(65);
        array.push_back(7439);
        array.push_back(954);
        array.push_back(30);
        array.push_back(4567);
        array.push_back(8);
        std::cout << array << std::endl;

        array.sort_radixsort();
        std::cout << array << std::endl;
    }

    std::cout << "#---- Excercise from slides" << std::endl;
    {
        fom::AuD::RadixSortArray array;
        array.fromVector({9413, 56, 1, 7645, 341, 103, 83, 2435});

        std::cout << array << std::endl;
        array.sort_radixsort();
        std::cout << array << std::endl;
    }

    return 0;
}