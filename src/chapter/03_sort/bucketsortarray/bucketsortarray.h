#ifndef BUCKETSORTARRAY_H
#define BUCKETSORTARRAY_H

#include <iostream>
#include <map>
#include <vector>

#include "dynarray/dynarray.h"

namespace fom
{
    namespace AuD
    {
        /** Internal container each individual digit used in sort_radixsort(). */
        typedef fom::AuD::Array<double> digitcontainer;
        /** Internal container for storing all elements in sort_radixsort(). */
        typedef std::map<unsigned short, digitcontainer> Buckets;

        /**
         * Array with bucket sort implementation.
         */
        class BucketSortArray : public Array<double>
        {

        public:
            /** Default constructor. */
            BucketSortArray();
            /** Destructor, free's resources. */
            virtual ~BucketSortArray();

            /** Copy constructur. Not implemented here. */
            BucketSortArray(const BucketSortArray&) = delete;
            /** Assignment operator. Not implemented here. */
            BucketSortArray& operator=(const BucketSortArray& other) = delete;

            /**
             * Sort this array using the bucket sort algorithm.
             * 
             * This algorithms contains of the following phases:
             * 1) Partition phase - put all numbers into buckets 0..9 - multiply by 10 for it!
             * 2) Sort phase - use a traditional comparing sorting algorithm for sorting each bucket
             * 3) Collection phase - overwrite current array contents with elements from the buckets "in order".
            */
            void sort_bucketsort();

        protected:
        };
    }
}

/**
 * Output function for fom::AuD::BucketSortArray.
 */
std::ostream &operator<<(std::ostream &os, const fom::AuD::BucketSortArray &o);

/**
 * Output function for fom::AuD::Buckets.
 */
std::ostream &operator<<(std::ostream &os, const fom::AuD::Buckets &o);

#endif // BUCKETSORTARRAY_H
