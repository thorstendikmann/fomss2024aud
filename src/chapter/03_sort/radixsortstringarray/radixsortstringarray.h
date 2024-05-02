#ifndef RADIXSORTSTRINGARRAY_H
#define RADIXSORTSTRINGARRAY_H

#include <iostream>
#include <map>
#include <vector>

#include "dynarray/dynarray.h"

namespace fom
{
    namespace AuD
    {
        /** Internal container each individual digit used in sort_radixsort(). */
        typedef fom::AuD::Array<std::string> digitcontainer;
        /** Internal container for storing all elements in sort_radixsort(). */
        typedef std::map<unsigned short, digitcontainer > Buckets;

        /**
         * Radix Sort implementation on string-Array.
         */
        class RadixSortStringArray : public Array<std::string>
        {

        public:
            /** Default constructor. */
            RadixSortStringArray();
            /** Destructor, free's resources. */
            virtual ~RadixSortStringArray();

            /** Copy constructur. Not implemented here. */
            RadixSortStringArray(const RadixSortStringArray&) = delete;
            /** Assignment operator. Not implemented here. */
            RadixSortStringArray& operator=(const RadixSortStringArray& other) = delete;

            /**
             * Radixsort implementation to sort this array, based on a bucket sort.
             * 
             * This implementation first gets the maximal length of a string.
             * For each letter, letterBucketing() will be called.
            */
            void sort_radixsort();

        protected:
            /** 
             * Helper function to get the maximal length of all string elements.
             * 
             * @return the maximal number of letters.
             */
            unsigned int getMaxLength() const;

            /**
             * Put all elements of this array into buckets based on the letter indicated by position.
             * "hello" -> letterBucketing(1) -> "h[e]llo", e is considered.
             * 
             * This algorithms contains of two phases:
             * 1) Partition phase - put all strings from array into buckets based on letter at position.
             * 2) Collection phase - overwrite current array contents with elements from the buckets "in order".
             * 
             * @param position indicate the relevant letter for bucketing.
            */
            void letterBucketing(unsigned short position);
        };
    }
}

/**
 * Output function for fom::AuD::RadixSortStringArray.
 */
std::ostream &operator<<(std::ostream &os, const fom::AuD::RadixSortStringArray &o);

/**
 * Output function for fom::AuD::Buckets.
 */
std::ostream &operator<<(std::ostream &os, const fom::AuD::Buckets &o);

#endif // RADIXSORTSTRINGARRAY_H
