#include <iostream>
#include <string>

int main()
{
    std::size_t maxElementsPerRow = 10;
    std::size_t curIdx = 0;

    for(std::size_t i = 33; i <=255; ++i){
        if(curIdx == maxElementsPerRow)
        {
            std::cout << std::endl;
            curIdx = 0;
        }

        std::cout << i << " - " << (char) i << "\t";
        curIdx++;
    }

    return 0;
}