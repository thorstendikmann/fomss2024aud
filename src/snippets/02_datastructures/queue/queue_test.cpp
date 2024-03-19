#include <iostream>
#include <string>

#include "queue.h"

int main()
{
    fom::AuD::Queue s;

    std::cout << "## --- Enqueue some values to the Queue" << std::endl;
    int ansi_start = 97; // 65 = 'A' | 97 = 'a | 48 = '0'
    for (int i = ansi_start; i < 10 + ansi_start; ++i)
    {
        s.enqueue((char) i);
    }
    std::cout << s.toString() << std::endl;

    std::cout << "## --- Dequeue & Print" << std::endl;
    std::cout << "Dequeue: " << s.dequeue() << std::endl;
    std::cout << s.toString() << std::endl;
    std::cout << "Dequeue: " << s.dequeue() << std::endl;
    std::cout << s.toString() << std::endl;
    std::cout << "Dequeue: " << s.dequeue() << std::endl;
    std::cout << s.toString() << std::endl;
    std::cout << "Dequeue: " << s.dequeue() << std::endl;
    std::cout << s.toString() << std::endl;
    std::cout << "Dequeue: " << s.dequeue() << std::endl;
    std::cout << s.toString() << std::endl;

    return 0;
}