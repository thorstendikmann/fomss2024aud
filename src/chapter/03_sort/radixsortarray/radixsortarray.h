#ifndef RADIXSORTARRAY_H
#define RADIXSORTARRAY_H

#include <iostream>
#include <map>
#include <vector>

#include "dynarray/dynarray.h"

namespace fom
{
    namespace AuD
    {
        /** Internal container each individual digit used in sort_radixsort(). */
        typedef fom::AuD::Array<unsigned int> digitcontainer;
        /** Internal container for storing all elements in sort_radixsort(). */
        typedef std::map<unsigned short, digitcontainer > Buckets;

        /**
         * RadixSortArray array class.
         * 
         * This is based on Array, but as unsigned ints give us
         * the simplest "basis" (=radix) with each digit=[0..9],
         * we stick to this data type in this class for demonstration
         * purposes!
         * 
         * Implementation based on Bucket Sort, therefore similar
         * to BucketSortArray.
         */
        class RadixSortArray : public Array<unsigned int>
        {

        public:
            /** Default constructor. */
            RadixSortArray();
            /** Destructor, free's resources. */
            virtual ~RadixSortArray();

            /** Copy constructur. Not implemented here. */
            RadixSortArray(const RadixSortArray&) = delete;
            /** Assignment operator. Not implemented here. */
            RadixSortArray& operator=(const RadixSortArray& other) = delete;

            /**
             * Radixsort implementation to sort this array, based on a bucket sort.
             * 
             * This implementation first gets the maximal number within this array (-> O(n)).
             * For each digit of this number, digitBucketing() will be called.
             * 352 -> has three digits, 26 -> has two digits.
            */
            void sort_radixsort();

        protected:
            /** 
             * Helper function to get the maximal element.
             * 
             * @return the maximal element.
             */
            unsigned int getMax() const;

            /**
             * Helper within sort_radixsort() to put every element into a bucket,
             * according to a given exponent exp.
             * 
             * This algorithms contains of two phases:
             * 1) Partition phase - put all numbers into buckets
             * 2) Collection phase - overwrite current RadixSortArray contents with elements from the buckets "in order".
             * 
             * @param exp the exponent to be considered. Specify as 1, 10, 100, 1000, 10000 etc.
            */
            void digitBucketing(unsigned int exp);
        };
    }
}

/**
 * Output function for fom::AuD::RadixSortArray.
 */
std::ostream &operator<<(std::ostream &os, const fom::AuD::RadixSortArray &o);

/**
 * Output function for fom::AuD::Buckets.
 */
std::ostream &operator<<(std::ostream &os, const fom::AuD::Buckets &o);

#endif // RADIXSORTARRAY_H
