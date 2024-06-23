#include <iostream>
#include <string>

#include "countingsortarray/countingsortarray.h"

int main()
{
    std::cout << "#---- CountingSort (ages)." << std::endl;
    {
        fom::AuD::CountingSortArray array;
        array.fromVector({25, 27, 22, 23, 33, 21, 24, 29, 27, 23, 25});

        std::cout << array << std::endl;
        array.sort_countingsort();
        std::cout << array << std::endl;
    }

    return 0;
}