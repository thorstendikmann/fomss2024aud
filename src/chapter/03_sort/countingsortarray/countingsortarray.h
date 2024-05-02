#ifndef COUNTINGSORTARRAY_H
#define COUNTINGSORTARRAY_H

#include <iostream>
#include <map>
#include <vector>

#include "dynarray/dynarray.h"

namespace fom
{
    namespace AuD
    {
        /** Helper to get the distribution of all elements. */
        typedef std::map<unsigned int, unsigned int> DistributionMap;

        /**
         * Array with counting sort implementation.
         */
        class CountingSortArray : public Array<unsigned int>
        {

        public:
            /** Default constructor. */
            CountingSortArray();
            /** Destructor, free's resources. */
            virtual ~CountingSortArray();

            /** Copy constructur. Not implemented here. */
            CountingSortArray(const CountingSortArray &) = delete;
            /** Assignment operator. Not implemented here. */
            CountingSortArray &operator=(const CountingSortArray &other) = delete;
            
            /**
             * Countingsort implementation to sort this array.
            */
            void sort_countingsort();

        protected:
            /**
             * Helper function to get the maximal element.
             *
             * @return the maximal element.
             */
            unsigned int getMax() const;
        };
    }
}

/** 
 * Helper for printing std::vector. 
 */
std::ostream &operator<<(std::ostream &os, const std::vector<unsigned int> &o);

/**
 * Output function for fom::AuD::CountingSortArray.
 */
std::ostream &operator<<(std::ostream &os, const fom::AuD::CountingSortArray &o);

/**
 * Output function for fom::AuD::DistributionMap.
 */
std::ostream &operator<<(std::ostream &os, const fom::AuD::DistributionMap &o);

#endif // COUNTINGSORTARRAY_H
