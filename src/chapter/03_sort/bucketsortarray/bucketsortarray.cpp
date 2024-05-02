#include <iomanip>
#include <iostream>
#include <algorithm>

#include "bucketsortarray.h"

namespace fom
{
    namespace AuD
    {

        BucketSortArray::BucketSortArray() : Array<double>()
        {
        }

        BucketSortArray::~BucketSortArray()
        {
            // superclass destructor called automatically!
        }

        void BucketSortArray::sort_bucketsort()
        {
            std::cout << "    Bucket sort" << std::endl;
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
            // Put numbers into buckets according to first digit after comma
            for (const_iterator it = this->begin(); it != this->end(); ++it)
            {
                // digit = container to choose
                unsigned short digit = *it * 10;
                std::cout << "        " << std::setw(5) << *it << " * 10 -> " << digit << std::endl;

                buckets[digit].push_back(*it);
            }
            std::cout << "    Buckets after run " << std::endl;
            std::cout << buckets << std::endl;

            // Sorting phase.
            // Sort each bucket using a traditional sort algorithm.
            for (fom::AuD::Buckets::iterator it = buckets.begin(); it != buckets.end(); ++it)
            {
                fom::AuD::digitcontainer& dc = it->second;
                // // stdlib functionality:
                // std::sort(dc.begin(), dc.end());
                // // own implementation:
                dc.sort_simple();
            }
            std::cout << "    Buckets after sort " << std::endl;
            std::cout << buckets << std::endl;

            // Collection Phase
            // Write back sorted array to this one
            size_t position = 0;
            for (fom::AuD::Buckets::const_iterator it = buckets.begin(); it != buckets.end(); ++it)
            {
                fom::AuD::digitcontainer dc = it->second;
                for (fom::AuD::digitcontainer::const_iterator dit = dc.begin(); dit != dc.end(); ++dit)
                {
                    this->operator[](position++) = *dit;
                }
            }
        }

    }
}

std::ostream &operator<<(std::ostream &os, const fom::AuD::BucketSortArray &o)
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
