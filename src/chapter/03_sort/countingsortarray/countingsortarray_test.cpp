#include <iostream>
#include <string>

#include "countingsortarray.h"

int main()
{
    std::cout << "#---- CountingSort." << std::endl;
    {
        fom::AuD::CountingSortArray array;
        array.fromVector({2, 5, 3, 0, 2, 3, 0, 3});

        std::cout << array << std::endl;
        array.sort_countingsort();
        std::cout << array << std::endl;
    }
    std::cout << "#---- CountingSort with playing cards example." << std::endl;
    {
        // Example from slides with playing cards
        fom::AuD::CountingSortArray array;
        array.fromVector({5, 6, 3, 3, 2, 4, 6, 14, 3});

        std::cout << array << std::endl;
        array.sort_countingsort();
        std::cout << array << std::endl;
    }
    std::cout << "#---- CountingSort with playing cards - exercise from slides." << std::endl;
    {
        // Excercise from slides with playing cards
        fom::AuD::CountingSortArray array;
        array.fromVector({13, 6, 14, 12, 4, 12, 13});

        std::cout << array << std::endl;
        array.sort_countingsort();
        std::cout << array << std::endl;
    }

    return 0;
}