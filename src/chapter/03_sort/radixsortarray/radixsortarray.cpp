#include <iomanip>
#include <iostream>

#include "radixsortarray.h"

namespace fom
{
    namespace AuD
    {

        RadixSortArray::RadixSortArray() : Array<unsigned int>()
        {
        }

        RadixSortArray::~RadixSortArray()
        {
            // superclass destructor called automatically!
        }

        void RadixSortArray::sort_radixsort()
        {
            std::cout << "-- Radixsort for " << this->size() << " elements." << std::endl;

            // Get max to determine the amount of digits
            unsigned int max = this->getMax();
            std::cout << "    Max: " << max << std::endl;

            // For each digit, call digitBucketing
            for (unsigned int exp = 1; max / exp > 0; exp *= 10)
            {
                this->digitBucketing(exp);
                std::cout << "    after digitBucketing (exp " << exp << "): " << *this << std::endl;
            }
        }

        unsigned int RadixSortArray::getMax() const
        {
            unsigned int max = 0;
            for (const_iterator it = this->begin(); it != this->end(); ++it)
            {
                if (*it > max)
                    max = *it;
            }
            return max;
        }

        void RadixSortArray::digitBucketing(unsigned int exp)
        {
            std::cout << "    Digit sort: exp " << exp << std::endl;

            // Create a "bucket" for each digit
            Buckets buckets =
                {
                    {0, {}},
                    {1, {}},
                    {2, {}},
                    {3, {}},
                    {4, {}},
                    {5, {}},
                    {6, {}},
                    {7, {}},
                    {8, {}},
                    {9, {}}};

            // Partition-Phase
            // Put numbers into buckets according to the currently relevant digit.
            for (const_iterator it = this->begin(); it != this->end(); ++it)
            {
                // digit = container to choose
                unsigned short digit = (*it / exp) % 10;
                std::cout << "        " << std::setw(5) << *it << " / " << exp << " % 10 -> " << digit << std::endl;

                buckets[digit].push_back(*it);
            }
            std::cout << "    Buckets after run for exp " << exp << std::endl;
            std::cout << buckets << std::endl;

            // Collection Phase
            // Write back sorted array to this one
            size_t position = 0;
            for (fom::AuD::Buckets::const_iterator it = buckets.begin(); it != buckets.end(); ++it)
            {
                const fom::AuD::digitcontainer& dc = it->second;
                for (fom::AuD::digitcontainer::const_iterator dit = dc.begin(); dit != dc.end(); ++dit)
                {
                    this->operator[](position++) = *dit;
                }
            }
        }

    }
}

std::ostream &operator<<(std::ostream &os, const fom::AuD::RadixSortArray &o)
{
    os << o.toString();
    return os;
}

std::ostream &operator<<(std::ostream &os, const fom::AuD::Buckets &o)
{
    for (fom::AuD::Buckets::const_iterator it = o.begin(); it != o.end(); ++it)
    {
        os << "        " << it->first << ": " << it->second << std::endl;
    }
    return os;
}
