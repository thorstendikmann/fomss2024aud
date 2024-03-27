#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    // Defaults
    float startMoney = 5000;
    float startInterest = 3.5;

    // User input
    if (argc == 2)
    {
        startMoney = atof(argv[1]);
    }
    if (argc == 3)
    {
        startMoney = atof(argv[1]);
        startInterest = atof(argv[2]);
    }
    // Some error handling
    if (startMoney <= 0 || startInterest <= 0)
    {
        std::cout << "Starting money and interest need to be positive to become richer .." << std::endl;
        return 1;
    }

    std::cout << "Starting with " << startMoney << " at " << startInterest << "%." << std::endl;

    float currentMoney = startMoney;
    std::size_t year = 0;
    while (currentMoney < 1000000)
    {
        ++year;
        currentMoney = currentMoney + ( (currentMoney * startInterest) / 100);
        std::cout << "Year " << year << ": " << currentMoney << std::endl;
    }

    std::cout << "Millionaire after " << year << " years" << std::endl;

    return 0;
}