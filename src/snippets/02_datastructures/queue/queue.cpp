#include <iostream>
#include <string>
#include <sstream>

#include "queue.h"
extern "C"
{
#include "../linkedlist/linkedlist.h"
}
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"

// avoid prefixing std::
using namespace std;

namespace fom
{
    namespace AuD
    {
        Queue::Queue()
        {
            // TODO
        }

        Queue::~Queue()
        {
            // TODO
        }

        void Queue::enqueue(const char element)
        {
            // TODO
        }

        char Queue::dequeue()
        {
            // TODO
            return '-';
        }

        const std::string Queue::toString()
        {
            // TODO ... for convenience reasons.
            return std::string();
        }
    }
}

#pragma GCC diagnostic pop
