#ifndef SEARCHARRAY_H
#define SEARCHARRAY_H

#include <iostream>

#include "dynarray/dynarray.h"

namespace fom
{
    namespace AuD
    {
        /**
         * Templated Array implementation in C++ for illustrating search functions.
         */
        template <typename T>
        class SearchArray : public Array<T>
        {

        public:
            /** Default constructor. */
            SearchArray();
            /** Destructor, free's resources. */
            virtual ~SearchArray();

            /**
             * "Sequential" search, searching the Array "from left to right".
             * @return position of the found element. -1 if not found.
             */
            int search_sequential(const T &val) const;

            /**
             * "Binary" search algorithms.
             * Internally calls search_binary_rec() recursively.
             * @return position of the found element. -1 if not found.
             */
            int search_binary(const T &val) const;

            /**
             * Interpolation search.
             * Internally calls search_interpolation_rec() recursively
             * @return position of the found element. -1 if not found.
             */
            int search_interpolation(const T &val) const;

            /**
             * Exponential search.
             * @return position of the found element. -1 if not found.
             */
            int search_exponential(const T &val) const;

        protected:
            /**
             * Recursive implementation of the binary search algorithms.
             * @param steps just a counter for keeping track of the steps.
             * @param val the value to be searched for.
             * @param left the "lower" limit in the binary search algorithm.
             * @param right the "upper" limit in the binary search algorithm.
             */
            int search_binary_rec(std::size_t& steps, const T &val, std::size_t left, std::size_t right) const;

            /**
             * Recursive implementation of the interpolation search algorithms.
             *
             *   \f[
             *          i = l + \frac{r-l}{a[r]-a[l]}\cdot\left( x-a[l] \right)
             *   \f]
             * where \f$ x \f$ the value we're looking for, \f$ i \f$ is the next "probing" position,
             * \f$ a \f$ this array, \f$ l \f$ the left boundary and \f$ r \f$ the right boundary.
             * @param steps just a counter for keeping track of the steps.
             * @param val the value to be searched for.
             * @param left the "lower" limit in the search algorithm.
             * @param right the "upper" limit in the search algorithm.
             */
            int search_interpolation_rec(std::size_t& steps, const T &val, std::size_t left, std::size_t right) const;
        };
    }
}

/**
 * Output function for fom::AuD::SearchArray<T>.
 * Needs to be defined in header, see https://stackoverflow.com/questions/8752837/undefined-reference-to-template-class-constructor .
 */
template <typename T>
std::ostream &operator<<(std::ostream &os, const fom::AuD::SearchArray<T> &o)
{
    os << o.toString();
    return os;
}

namespace fom
{
    namespace AuD
    {

        template <typename T>
        SearchArray<T>::SearchArray() : Array<T>()
        {
        }

        template <typename T>
        SearchArray<T>::~SearchArray()
        {
            // superclass destructor called automatically!
        }

        template <typename T>
        int SearchArray<T>::search_sequential(const T &val) const
        {
            std::size_t idx = 0;
            for (typename Array<T>::const_iterator cItr = this->begin(); cItr != this->end(); ++cItr)
            {
                this->callback({idx});
                if (*cItr == val)
                {
                    return idx;
                }
                ++idx;
            }

            return -1;
        }

        template <typename T>
        int SearchArray<T>::search_binary(const T &val) const
        {
            this->callback({0, this->size() - 1});
            std::size_t steps = 0;
            int returnVal = search_binary_rec(steps, val, 0, this->size() - 1);

            return returnVal;
        }

        template <typename T>
        int SearchArray<T>::search_binary_rec(std::size_t& steps, const T &val, std::size_t left, std::size_t right) const
        {
            steps++;
            if (right >= left)
            {
                std::cout << "    Step " << steps << std::endl;
                std::size_t mid = left + (right - left) / 2;
                this->callback({mid, left, right});

                // element is at the middle
                if (this->at(mid) == val)
                    return mid;

                // element < mid, then consider "left" subarray [with mid-1 as right border]
                if (this->at(mid) > val)
                    return search_binary_rec(steps, val, left, mid - 1);

                // element > mid, then consider "right" subarray [with mid+1 as left border]
                return search_binary_rec(steps, val, mid + 1, right);
            }

            return -1;
        }

        template <typename T>
        int SearchArray<T>::search_interpolation(const T &val) const
        {
            this->callback({0, this->size() - 1});
            std::size_t steps = 0;
            return search_interpolation_rec(steps, val, 0, this->size() - 1);
        }

        template <typename T>
        int SearchArray<T>::search_interpolation_rec(std::size_t& steps, const T &val, std::size_t left, std::size_t right) const
        {
            std::size_t pos;
            steps++;

            // Value must be found in boundaries > left && < right
            if (left <= right && (val >= this->at(left) && val <= this->at(right)))
            {
                std::cout << "    Step " << steps << std::endl;
                
                // Probing - see formula in function description
                pos = left + (((double)(right - left) / (this->at(right) - this->at(left))) * (val - this->at(left)));
                this->callback({pos, left, right});

                // Found?
                if (this->at(pos) == val)
                    return pos;

                // val is larger => val in right sub array
                if (this->at(pos) < val)
                    return search_interpolation_rec(steps, val, pos + 1, right);

                // val is smaller => val in left sub array
                if (this->at(pos) > val)
                    return search_interpolation_rec(steps, val, left, pos - 1);
            }
            return -1;
        }

        template <typename T>
        int SearchArray<T>::search_exponential(const T &val) const
        {
            size_t n = this->size();
            // found at first position?
            if (this->at(0) == val)
                return 0;

            // Determine range of binary search
            // Repeat doubling interval and check if searched value in it.
            std::size_t i = 1;
            while (i < n && this->at(i) <= val)
            {
                i = i * 2;
                this->callback({i, i / 2});
            }

            //  binary search for the found range.
            std::size_t steps;
            return this->search_binary_rec(steps, val, i / 2, std::min(i, n - 1));
        }
    }
}

#endif // SEARCHARRAY_H