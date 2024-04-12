#include <iostream>
#include <string>
#include <sstream>

#include "queue.h"
extern "C"
{
#include "linkedlist/linkedlist.h"
}

// avoid prefixing std::
using namespace std;

namespace fom
{
    namespace AuD
    {
        Queue::Queue()
        {
            this->l = new LinkedList;
            linkedlist_init(this->l);
        }

        Queue::~Queue()
        {
            linkedlist_destroy(this->l);
            delete (this->l);
            this->l = 0;
        }

        void Queue::enqueue(const char element)
        {
            linkedlist_push_back(this->l, element);
        }

        char Queue::dequeue()
        {
            // ... pretty much the only difference to a Stack:
            // Return the "oldest" element
            return linkedlist_pop_front(this->l);
        }

        const std::string Queue::toString()
        {
            std::stringstream returnStr;
            for (size_t i = 0; i < linkedlist_size(this->l); i++)
            {
                const char c = *((linkedlist_at(this->l, i))->value);

                returnStr << "[" << c << "]"; // << std::endl;
            }

            return returnStr.str();
        }

        std::string Queue::toGraphviz() const
        {
            std::stringstream returnStr;

            returnStr << ("digraph g {\n");
            returnStr << ("graph [\n");
            returnStr << ("  rankdir = \"LR\"\n");
            returnStr << ("];\n");

            for (size_t i = 0; i < linkedlist_size(this->l); i++)
            {
                node* n = linkedlist_at(this->l, i);
                const char c = *(n->value);

                returnStr << "\"" << (void *)n << "\" [\n";
                returnStr << "    label = \"<f0> " << c << "\"\n";
                returnStr << "    shape = \"record\"\n";
                returnStr << ("];\n");
            }

            for (size_t i = 0; i < linkedlist_size(this->l) -1; i++)
            {
                node* n = linkedlist_at(this->l, i);
                returnStr << "\"" << (void *)n << "\" -> \"" << (void *)n->next  << "\"\n";
            }

            returnStr << ("}\n") << std::endl;
            return returnStr.str();
        }
    }
}
