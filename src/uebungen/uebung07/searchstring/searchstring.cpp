#include <iostream>
#include <string>
#include <cassert>

#include "stringsearch/fomstring.h"

int main()
{
    {
        fom::AuD::FomString s("GCGGCTGCGGCTGCGGCA");
        size_t pos;
        std::string pattern = "GCGGCA";

        std::cout << "String: " << s << std::endl;

        pos = s.find_kmp(pattern);
        if (pos != std::string::npos)
            std::cout << "Pattern: " << pattern << " found at pos " << pos << std::endl;

        pos = s.find_horspool(pattern);
        if (pos != std::string::npos)
            std::cout << "Pattern: " << pattern << " found at pos " << pos << std::endl;
    }
    {
        fom::AuD::FomString s("GCGGCMTGCGMGCTMGCGGCA");
        size_t pos;
        std::string pattern = "GCGGCA";

        std::cout << "String: " << s << std::endl;

        pos = s.find_kmp(pattern);
        if (pos != std::string::npos)
            std::cout << "Pattern: " << pattern << " found at pos " << pos << std::endl;

        pos = s.find_horspool(pattern);
        if (pos != std::string::npos)
            std::cout << "Pattern: " << pattern << " found at pos " << pos << std::endl;
    }

    return 0;
}