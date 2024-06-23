#include <iostream>
#include <string>

#include "searcharray.h"

int main()
{
    typedef fom::AuD::SearchArray<int> SearchArray;

    std::cout << "#---- Some search tests on SearchArray" << std::endl;
    {
        SearchArray array;

        array.push_back(10);
        array.push_back(15);
        array.push_back(1);
        array.push_back(3);
        array.push_back(5);
        array.push_back(7);
        array.push_back(9);
        array.push_back(25);
        array.push_back(13);
        array.push_back(9);
        array.push_back(45);
        array.push_back(46);
        array.push_back(33);
        array.push_back(42);

        std::cout << array.toString() << std::endl;

        std::cout << "Random access of some elements: " << std::endl;
        std::cout << "  [0] - " << array[0] << std::endl;
        std::cout << "  [3] - " << array[2] << std::endl;

        std::cout << "Test some other functions: " << std::endl;
        std::cout << "  Size: " << array.size() << std::endl;

        std::cout << "#---- Sorting array (no particular algorithm)." << std::endl;
        array.sort_simple();
        std::cout << array.toString() << std::endl;

        std::cout << "#---- Searching Sequential." << std::endl;
        std::cout << "   Pos of 33: " << std::endl << array.search_sequential(33) << std::endl;

        std::cout << "#---- Searching Binary." << std::endl;
        std::cout << "   Pos of 33: " << std::endl << array.search_binary(33) << std::endl;

        std::cout << "#---- Searching Interpolation." << std::endl;
        std::cout << "   Pos of 33: " << std::endl << array.search_interpolation(33) << std::endl;

        std::cout << "#---- Searching Exponential." << std::endl;
        std::cout << "   Pos of 33: " << std::endl << array.search_exponential(33) << std::endl;
    }

    std::cout << "#---- Excercise from slides" << std::endl;
    {
        SearchArray array;

        array.fromVector({10, 14, 33, 41, 45, 59, 73, 82, 90, 101, 118, 119, 134, 141, 150});
        std::cout << "       Searching Binary." << std::endl;
        std::cout << "   Pos of 45: " << std::endl << array.search_binary(45) << std::endl;
    
        std::cout << "       Comparing interpolation search in two lists." << std::endl;
        
        std::cout << "       Searching Interpolation." << std::endl;
        std::cout << "   Pos of 45: " << std::endl << array.search_interpolation(45) << std::endl;

        std::cout << "       Loading second array." << std::endl;
        array.fromVector({10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 45, 150});
        std::cout << "       Searching Interpolation." << std::endl;
        std::cout << "   Pos of 45: " << std::endl << array.search_interpolation(45) << std::endl;
    }

    return 0;
}