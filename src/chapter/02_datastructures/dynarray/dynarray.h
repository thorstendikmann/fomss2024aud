#ifndef DYNARRAY_H
#define DYNARRAY_H

#include <iostream>
#include <vector>
#include <list>
#include <sstream>
#include <algorithm>
#include <iterator>

namespace fom
{
    namespace AuD
    {
        /**
         * Templated Array implementation in C++.
         * This is a wrapper for a std::vector, where only the essential functions are available.
         * Will be used for showing search and sort algorithms.
         */
        template <typename T>
        class Array
        {

        public:
            /** Iterator for this container. */
            typedef typename std::vector<T>::iterator iterator;
            /** Const Iterator for this container. */
            typedef typename std::vector<T>::const_iterator const_iterator;

            /** Default constructor. */
            Array();
            /** Destructor, free's resources. */
            virtual ~Array();

            /**
             * Add an element to the container.
             * @param val the new element.
             */
            void push_back(const T &val);

            /**
             * Random access an element of the container.
             * @param index position of element to be accessed.
             * @return element at this index.
             */
            T &operator[](std::size_t index);

            /**
             * Random access an element of the container - const version.
             * @param index position of element to be accessed.
             * @return element at this index.
             */
            const T &operator[](std::size_t index) const;

            /**
             * Random access an element of the container - const version.
             * Same as operator[] in its const variant.
             * @param index position of element to be accessed.
             * @return element at this index.
             */
            const T &at(std::size_t index) const;

            /**
             * Empties the data structure.
             */
            void clear();

            /**
             * Returns the current container size.
             * @return number of elements in container.
             */
            std::size_t size() const;

            /**
             * "Triangle swap" of two elements within the Array.
             *
             * The position of i and j internally will have switched after this function.
             *
             * @param i first element.
             * @param j second element.
             */
            void swap(std::size_t i, std::size_t j);

            /**
             * A simple sorting of this data structure.
             * This does not implement any specific algorithms.
             * This array is just sorted, not necessarily fast or elegant.
             */
            void sort_simple();

            /** Iterator, pointing to first element. */
            iterator begin();
            /** Const Iterator, pointing to first element. */
            const_iterator begin() const;
            /** Iterator, pointing to "behind last" element. */
            iterator end();
            /** Const Iterator, pointing to "behind last" element. */
            const_iterator end() const;

            /**
             * Prints the content of this iterator into a string and returns it.
             * @return string representation of the elements of this container.
             */
            std::string toString() const;

            /**
             * Initializes internal data from a C++ standard-vector.
             *
             * Convenience function to quickly demo some algorithms
             * without multiple "push_back()".
             * Calls like fromVector({5,8,3,2}) are possible with this.
             *
             * @param vector the vector to copy data from.
             */
            void fromVector(const std::vector<T> &vector);

        protected:
            /** Internal storage. */
            std::vector<T> vector;

            /** Shortcut for a list of positions in the array to be highlighted, e.g. in a visualization of search algorithms. */
            typedef std::list<std::size_t> highlights;
            /**
             * Callback used to visualize updates in this array for demonstrating
             * search and sorting algorithms.
             * There are several options to highlight elements - and the implementation
             * decides <em>how</em> to highlight, e.g. choose a different color
             * for element 01 than 02 etc.
             * @param highlightPost list of positions of all elements you want to highlight.
             */
            void callback(const highlights &highlightPost) const;
        };
    }
}

/**
 * Output function for fom::AuD::Array<T>.
 * Needs to be defined in header, see https://stackoverflow.com/questions/8752837/undefined-reference-to-template-class-constructor .
 */
template <typename T>
std::ostream &operator<<(std::ostream &os, const fom::AuD::Array<T> &o)
{
    os << o.toString();
    return os;
}

namespace fom
{
    namespace AuD
    {

        template <typename T>
        Array<T>::Array()
        {
        }

        template <typename T>
        Array<T>::~Array()
        {
            // superclass destructor called automatically!
        }

        template <typename T>
        void Array<T>::push_back(const T &val)
        {
            this->vector.push_back(val);
        }

        template <typename T>
        T &Array<T>::operator[](std::size_t index)
        {
            return this->vector[index];
        }

        template <typename T>
        const T &Array<T>::operator[](std::size_t index) const
        {
            return this->vector[index];
        }

        template <typename T>
        const T &Array<T>::at(std::size_t index) const
        {
            return this->vector[index];
        }

        template <typename T>
        std::string Array<T>::toString() const
        {
            std::stringstream ss;

            for (const_iterator cItr = this->begin();
                 cItr != this->end();
                 ++cItr)
            {
                ss << "[" << *cItr << "] ";
            }

            return ss.str();
        }

        template <typename T>
        void Array<T>::clear()
        {
            this->vector.clear();
        }

        template <typename T>
        std::size_t Array<T>::size() const
        {
            return vector.size();
        }

        template <typename T>
        void Array<T>::swap(std::size_t i, std::size_t j)
        {
            T tmpVal = (*this)[j];
            (*this)[j] = (*this)[i];
            (*this)[i] = tmpVal;
        }

        template <typename T>
        void Array<T>::sort_simple()
        {
            std::sort(vector.begin(), vector.end());
            // callback(highlights({3})); // show how to call callback
        }

        template <typename T>
        typename Array<T>::iterator Array<T>::begin()
        {
            return this->vector.begin();
        }

        template <typename T>
        typename Array<T>::const_iterator Array<T>::begin() const
        {
            return this->vector.begin();
        }

        template <typename T>
        typename Array<T>::iterator Array<T>::end()
        {
            return this->vector.end();
        }

        template <typename T>
        typename Array<T>::const_iterator Array<T>::end() const
        {
            return this->vector.end();
        }

        template <typename T>
        void Array<T>::fromVector(const std::vector<T> &vector)
        {
            this->clear();
            std::copy(vector.begin(), vector.end(), back_inserter(this->vector));
        }

#if defined(__GNUC__) || defined(__clang__)
#  pragma GCC diagnostic push
#  pragma GCC diagnostic ignored "-Wunused-parameter"
#endif

        template <typename T>
        void Array<T>::callback(const highlights &highlightPost) const
        {
            // Do nothing here.
            std::size_t i = 0;
            for (highlights::const_iterator it = highlightPost.begin(); it != highlightPost.end(); ++it, ++i)
            {
                std::cout << "  > " << i << " -> " << *it << " " << std::endl;
            }
            std::cout << std::endl;
        }
#if defined(__GNUC__) || defined(__clang__)
#  pragma GCC diagnostic pop
#endif
    }
}

#endif // DYNARRAY_H