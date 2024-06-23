#include <iostream>
#include <string>

#include "searcharray/searcharray.h"

int main()
{
    typedef fom::AuD::SearchArray<int> SearchArray;

    std::cout << "#---- Binary Search" << std::endl;
    {
        SearchArray array;

        array.fromVector({3, 7, 9, 10, 11, 13, 18, 23, 26, 28, 34, 37, 41, 45, 48, 52, 58, 61, 66, 71, 77, 83, 88, 92, 97});
        std::cout << "       Searching Binary." << std::endl;
        std::cout << "   Pos of 61: " << std::endl << array.search_binary(61) << std::endl;

        std::cout << "       Searching Interpolation." << std::endl;
        std::cout << "   Pos of 61: " << std::endl << array.search_interpolation(61) << std::endl;
    }

    return 0;
}