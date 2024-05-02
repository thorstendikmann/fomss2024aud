#include <iomanip>
#include <iostream>

#include "radixsortstringarray.h"

namespace fom
{
    namespace AuD
    {

        RadixSortStringArray::RadixSortStringArray() : Array<std::string>()
        {
        }

        RadixSortStringArray::~RadixSortStringArray()
        {
            // superclass destructor called automatically!
        }

        void RadixSortStringArray::sort_radixsort()
        {
            std::cout << "-- Radixsort for " << this->size() << " elements." << std::endl;

            // Get max to determine the amount of characters
            unsigned int max = this->getMaxLength();
            std::cout << "    Max: " << max << std::endl;

            // For each letter, call letterBucketing
            for (int pos = max - 1; pos >= 0; --pos)
            {
                this->letterBucketing(pos);
                std::cout << "    after letterBucketing (pos " << pos << "): " << *this << std::endl;
            }
        }

        unsigned int RadixSortStringArray::getMaxLength() const
        {
            unsigned int max = 0;
            for (const_iterator it = this->begin(); it != this->end(); ++it)
            {
                if (it->length() > max)
                    max = it->length();
            }
            return max;
        }

        void RadixSortStringArray::letterBucketing(unsigned short position)
        {
            std::cout << "    String sort: pos " << position << std::endl;

            // Create a "bucket" for each digit
            Buckets buckets;
            for (unsigned int i = 0; i < 255; ++i)
            {
                buckets[i] = {};
            }

            // Partition-Phase
            // Put numbers into buckets according to the currently relevant letter.
            for (const_iterator it = this->begin(); it != this->end(); ++it)
            {
                unsigned int c = 0; // Default bucket, when string not long enough
                if (it->length() >= position)
                    c = (unsigned int)(*it)[position];

                std::cout << "        " << *it << " - Pos " << position << ": -> " << (char) c << std::endl;
                buckets[c].push_back(*it);
            }
            std::cout << "    Buckets after run for pos " << position << std::endl;
            std::cout << buckets << std::endl;

            // Collection Phase
            // Write back sorted array to this one
            size_t posInArray = 0;
            for (fom::AuD::Buckets::const_iterator it = buckets.begin(); it != buckets.end(); ++it)
            {
                const fom::AuD::digitcontainer &dc = it->second;
                for (fom::AuD::digitcontainer::const_iterator dit = dc.begin(); dit != dc.end(); ++dit)
                {
                    this->operator[](posInArray++) = *dit;
                }
            }
        }

    }
}

std::ostream &operator<<(std::ostream &os, const fom::AuD::RadixSortStringArray &o)
{
    os << o.toString();
    return os;
}

std::ostream &operator<<(std::ostream &os, const fom::AuD::Buckets &o)
{
    for (fom::AuD::Buckets::const_iterator it = o.begin(); it != o.end(); ++it)
    {
        // ignore unprintable chars - but include 0 - includes all not sorted elements.
        if (it->first == 0 || (it->first >= 33 && it->first <= 126))
        {
            // ignore empty containers
            if (it->second.size() > 0)
            {
                os << "        " << it->first << ": ";

                fom::AuD::digitcontainer dc = it->second;
                for (fom::AuD::digitcontainer::const_iterator dit = dc.begin(); dit != dc.end(); ++dit)
                {
                    os << *dit << ", ";
                }

                os << std::endl;
            }
        }
    }
    return os;
}
