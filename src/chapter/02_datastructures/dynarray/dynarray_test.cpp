#include <iostream>
#include <string>

#include "dynarray.h"

int main()
{
    typedef fom::AuD::Array<int> Array;

    Array array;

    std::cout << "#---- Adding some elements." << std::endl;

    array.push_back(10);
    array.push_back(15);
    array.push_back(1);
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

    return 0;
}