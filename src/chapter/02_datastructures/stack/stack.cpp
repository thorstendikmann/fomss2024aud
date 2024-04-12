#include <iostream>
#include <string>
#include <sstream>

#include "stack.h"
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
        Stack::Stack()
        {
            this->l = new LinkedList;
            linkedlist_init(this->l);
        }

        Stack::~Stack()
        {
            linkedlist_destroy(this->l);
            delete (this->l);
            this->l = 0;
        }

        void Stack::push(const char element)
        {
            linkedlist_push_back(this->l, element);
        }

        char Stack::pop()
        {
            return linkedlist_pop_back(this->l);
        }

        char Stack::top()
        {
            char c;
            c = *(l->tail->next->value);
            return c;
        }

        const std::string Stack::toString()
        {
            std::stringstream returnStr;
            for (size_t i = 0; i < linkedlist_size(this->l); i++)
            {
                const char c = *((linkedlist_at(this->l, i))->value);

                returnStr << "[" << c << "]"; // << std::endl;
            }

            return returnStr.str();
        }

        std::string Stack::toGraphviz() const
        {
            std::stringstream returnStr;

            returnStr << "graph array \n";
            returnStr << "{ \n";

            returnStr << "Array [ shape = record, label = \"{";

            size_t i = 0;
            for (i = linkedlist_size(this->l) - 1; i > 0; i--)
            {
                const char c = *((linkedlist_at(this->l, i))->value);
                returnStr << c << " | ";
            }

            const char c = *((linkedlist_at(this->l, i))->value);
            returnStr << c << " ";

            returnStr << "}\"] ; \n";

            returnStr << "} \n";
            return returnStr.str();
        }
    }
}
