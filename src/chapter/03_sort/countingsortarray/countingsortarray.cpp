#include <iomanip>
#include <iostream>
#include <algorithm>

#include "countingsortarray.h"

namespace fom
{
    namespace AuD
    {

        CountingSortArray::CountingSortArray() : Array<unsigned int>()
        {
        }

        CountingSortArray::~CountingSortArray()
        {
            // superclass destructor called automatically!
        }

        void CountingSortArray::sort_countingsort()
        {
            std::cout << "    Counting sort" << std::endl;

            // Get max to determine the distribution limit
            unsigned int max = this->getMax();
            std::cout << "    Max: " << max << std::endl;

            // Build distribution
            fom::AuD::DistributionMap distribution;
            for (const_iterator it = this->begin(); it != this->end(); ++it)
            {
                distribution[*it]++;
            }
            std::cout << "    Distribution: " << std::endl
                      << distribution << std::endl;

            // Calculate prefix sum (cumulative sum)
            fom::AuD::DistributionMap prefixSum;
            prefixSum[0] = distribution[0];
            for (unsigned int i = 1; i < distribution.size(); ++i)
            {
                prefixSum[i] = prefixSum[i - 1] + distribution[i];
            }
            std::cout << "    PrefixSum: " << std::endl
                      << prefixSum;

            // fill temp output, create size() elements!
            std::vector<unsigned int> outputArray(this->size());
            std::cout << "    Sorting: " << std::endl;
            // Iterating back to fron preserves "in place" ... when it matters
            for (int i = this->size() - 1; i >= 0; i--)
            {
                std::cout << "      i: [" << i << "] -> " << this->at(i) << std::endl;
                std::cout << "      Current PrefixSum: " << std::endl
                          << prefixSum;
                std::cout << "      PrefixSum[" << this->at(i) << "]: " << prefixSum[this->at(i)];
                std::cout << " -> New pos: " << prefixSum[this->at(i)] - 1 << " | Dec-- prefixSum[" << this->at(i) << "]" << std::endl;
                
                // Define new position ... this is the relevant part, all other is debug output :)
                outputArray[prefixSum[this->at(i)] - 1] = this->at(i);
                prefixSum[this->at(i)]--;
                
                std::cout << "      outputArray: " << outputArray;
                std::cout << std::endl;
            }

            // overwrite current elements with sorted ones
            this->fromVector(outputArray);
        }

        unsigned int CountingSortArray::getMax() const
        {
            unsigned int max = 0;
            for (const_iterator it = this->begin(); it != this->end(); ++it)
            {
                if (*it > max)
                    max = *it;
            }
            return max;
        }

    }
}

std::ostream &operator<<(std::ostream &os, const std::vector<unsigned int> &o)
{
    for (std::vector<unsigned int>::const_iterator it = o.begin(); it != o.end(); ++it)
    {
        os << *it << " ";
    }
    os << std::endl;
    return os;
}

std::ostream &operator<<(std::ostream &os, const fom::AuD::CountingSortArray &o)
{
    os << o.toString();
    return os;
}

std::ostream &operator<<(std::ostream &os, const fom::AuD::DistributionMap &o)
{
    os << "        ";
    for (fom::AuD::DistributionMap::const_iterator it = o.begin(); it != o.end(); ++it)
    {
        os << std::setw(2) << it->first << " ";
    }
    os << std::endl;
    os << "        ";
    for (fom::AuD::DistributionMap::const_iterator it = o.begin(); it != o.end(); ++it)
    {
        os << std::setw(2) << it->second << " ";
    }
    os << std::endl;
    return os;
}
