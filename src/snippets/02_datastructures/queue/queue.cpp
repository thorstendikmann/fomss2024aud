#include <iostream>
#include <string>
#include <sstream>

#include "queue.h"
extern "C"
{
    // # This will reference linkedlist from snippets/02_datastructures !
    #include "../linkedlist/linkedlist.h"
    // // # This will reference linkedlist from chapter/02_datastructures !
    // #include "../linkedlist/linkedlist.h"
}
#if defined(__GNUC__) || defined(__clang__)
#  pragma GCC diagnostic push
#  pragma GCC diagnostic ignored "-Wunused-parameter"
#endif

// avoid prefixing std::
using namespace std;

namespace fom
{
    namespace AuD
    {
        Queue::Queue()
        {
            // TODO
            this->l = 0;  // initialize me !!!
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

#if defined(__GNUC__) || defined(__clang__)
#  pragma GCC diagnostic pop
#endif
