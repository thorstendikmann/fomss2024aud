#include <iostream>
#include <string>

#include "stack.h"

int main()
{
    fom::AuD::Stack s;

    std::cout << "## --- Push some values to the Stack" << std::endl;
    int ansi_start = 97; // 65 = 'A' | 97 = 'a | 48 = '0'
    for (int i = ansi_start; i < 10 + ansi_start; ++i)
    {
        s.push((char) i);
    }
    std::cout << s.toString() << std::endl;

    std::cout << "## --- Pop & Print" << std::endl;
    std::cout << "Pop: " << s.pop() << std::endl;
    std::cout << s.toString() << std::endl;
    std::cout << "Pop: " << s.pop() << std::endl;
    std::cout << s.toString() << std::endl;
    std::cout << "Pop: " << s.pop() << std::endl;
    std::cout << s.toString() << std::endl;
    std::cout << "Pop: " << s.pop() << std::endl;
    std::cout << s.toString() << std::endl;
    std::cout << "Pop: " << s.pop() << std::endl;
    std::cout << s.toString() << std::endl;
    
    std::cout << "## --- Push & Top" << std::endl;
    s.push('1');
    std::cout << s.toString() << std::endl;
    std::cout << "Top: " << s.top() << std::endl;
    std::cout << s.toString() << std::endl;
    s.push('2');
    s.push('3');
    std::cout << s.toString() << std::endl;
    std::cout << "Pop: " << s.pop() << std::endl;
    std::cout << s.toString() << std::endl;

    return 0;
}