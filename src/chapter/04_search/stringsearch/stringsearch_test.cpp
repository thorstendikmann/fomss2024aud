#include <iostream>
#include <string>
#include <cassert>

#include "fomstring.h"

int main()
{
    {
        // Check for not found string
        fom::AuD::FomString s("aaa");
        size_t pos;
        std::string pattern = "b";

        pos = s.find_naive(pattern);
        assert(pos == std::string::npos);
        if (pos == std::string::npos)
            std::cout << "Pattern: " << pattern << " not found in " << s << " (good!)." << std::endl;
    }
    {
        fom::AuD::FomString s("Hello, World!");
        size_t pos;
        std::string pattern = "orl";

        std::cout << "String: " << s << std::endl;

        pos = s.find_naive(pattern);
        assert(pos == 8);
        if (pos != std::string::npos)
            std::cout << "Pattern: " << pattern << " found at pos " << pos << std::endl;

        pos = s.find_kmp(pattern);
        assert(pos == 8);
        if (pos != std::string::npos)
            std::cout << "Pattern: " << pattern << " found at pos " << pos << std::endl;

        pos = s.find_horspool(pattern);
        assert(pos == 8);
        if (pos != std::string::npos)
            std::cout << "Pattern: " << pattern << " found at pos " << pos << std::endl;
    }
    {
        fom::AuD::FomString s("ABABDABACDABABCABAB");
        size_t pos;
        std::string pattern = "ABABCABAB";

        std::cout << "String: " << s << std::endl;

        pos = s.find_naive(pattern);
        assert(pos == 10);
        if (pos != std::string::npos)
            std::cout << "Pattern: " << pattern << " found at pos " << pos << std::endl;

        pos = s.find_kmp(pattern);
        assert(pos == 10);
        if (pos != std::string::npos)
            std::cout << "Pattern: " << pattern << " found at pos " << pos << std::endl;

        pos = s.find_horspool(pattern);
        assert(pos == 10);
        if (pos != std::string::npos)
            std::cout << "Pattern: " << pattern << " found at pos " << pos << std::endl;
    }
    {
        // C - cytosine, G - guanine, A - adenine, T - thyminin
        fom::AuD::FomString s("AATCCGCTATCGAGAATCCGATCCAGT");
        size_t pos;
        std::string pattern = "AATCCGAT";

        std::cout << "String: " << s << std::endl;

        pos = s.find_naive(pattern);
        assert(pos == 14);
        if (pos != std::string::npos)
            std::cout << "Pattern: " << pattern << " found at pos " << pos << std::endl;

        pos = s.find_kmp(pattern);
        assert(pos == 14);
        if (pos != std::string::npos)
            std::cout << "Pattern: " << pattern << " found at pos " << pos << std::endl;

        pos = s.find_horspool(pattern);
        assert(pos == 14);
        if (pos != std::string::npos)
            std::cout << "Pattern: " << pattern << " found at pos " << pos << std::endl;
    }
    {
        fom::AuD::FomString s("barbaras barbaren baten");
        size_t pos;
        std::string pattern = "barbaren";

        std::cout << "String: " << s << std::endl;

        pos = s.find_kmp(pattern);
        if (pos != std::string::npos)
            std::cout << "Pattern: " << pattern << " found at pos " << pos << std::endl;

        pos = s.find_horspool(pattern);
        if (pos != std::string::npos)
            std::cout << "Pattern: " << pattern << " found at pos " << pos << std::endl;
    }
    {
        fom::AuD::FomString s("ddaabcacbabc");
        size_t pos;
        std::string pattern = "acbabc";

        std::cout << "String: " << s << std::endl;

        pos = s.find_horspool(pattern);
        if (pos != std::string::npos)
            std::cout << "Pattern: " << pattern << " found at pos " << pos << std::endl;
    }
    {

        std::cout << std::endl
                  << "#---- Exercise from slide: " << std::endl;
        fom::AuD::FomString s("");

        std::string pattern;

        // will print LPS only ...
        pattern = "tottototto";
        s.find_kmp(pattern);

        // will print LPS only ...
        pattern = "bebende";
        s.find_kmp(pattern);

        // will print shift table only ...
        pattern = "bebende";
        s.find_horspool(pattern);

        // will print shift table only ...
        pattern = "oleola";
        s.find_horspool(pattern);
    }
    {

        std::cout << std::endl
                  << "#---- Exercise from slide: " << std::endl;
        fom::AuD::FomString s("olaolelaola");

        std::string pattern = "laola";
        size_t pos = s.find_kmp(pattern);
        if (pos != std::string::npos)
            std::cout << "Pattern: " << pattern << " found at pos " << pos << std::endl;

        pos = s.find_horspool(pattern);
        if (pos != std::string::npos)
            std::cout << "Pattern: " << pattern << " found at pos " << pos << std::endl;
    }

    return 0;
}