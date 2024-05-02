#include <iostream>
#include <string>

#include "bucketsortarray.h"

int main()
{
    std::cout << "#---- BucketSort." << std::endl;
    {
        fom::AuD::BucketSortArray array;
        array.fromVector({0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68});

        std::cout << array << std::endl;

        array.sort_bucketsort();
        std::cout << array << std::endl;
    }

    return 0;
}