#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <string>
#include <sstream>

#include "dynarray/dynarray.h"

namespace fom
{
    namespace AuD
    {
        /**
         * Templated Heap implementation in C++ based on
         * an array (see Array) as data structure.
         *
         * Type T has to implement operator<< to allow output.
         */
        template <typename T>
        class Heap : public Array<T>
        {
            typedef Heap<T> node;

        public:
            /** Default constructor. */
            Heap();
            /** Destructor, free's resources. */
            virtual ~Heap();

            /**
             * "Heapify" - ensure heap condition in this data structure.
             *
             * This ensures the maxheap condition by recursively calling itself with subnodes.
             *
             * This function is identical to heapify() in heapsort.c
             *
             * @param N the maximum number of elements to consider ()
             * @param i the index of the node to consider root node for this heapify operation.
             */
            void heapify(size_t N, size_t i);

            /**
             * Output a Heap into a std::string.
             *
             * This will print the internal array from "left to right".
             *
             * @return a String representation of the contents.
             */
            std::string toString() const;

            /**
             * Output tree structure in Graphviz-readable format for visualization.
             *
             * @return a graphViz input.
             */
            std::string toGraphViz() const;

        protected:
            /** An internal indicator for printing if we're on the left or right node. */
            enum LR
            {
                /** Left node indicator. */
                Left = 0,
                /** Right node indicator. */
                Right = 1
            };

            /**
             * Internal function for highlighting some nodes in Graphviz output.
             * This is kind'a hardcoded for the examples of the lecture.
             *
             * Currently not yet implemented here.
             *
             * @param val the value of the current node.
             * @return string with additional style information (or empty).
             */
            std::string getGraphVizColorInfo(T val) const;

            /**
             * Internal function for printing a child element in Graphviz syntax.
             *
             * @param index index of the child element. 2i+1 for left child, 2i+2 for right child.
             * @param lr indicator if this child node is its parent's left or right node.
             * @param parentNodeName the "label" of the parent node as used for graphviz.
             * @return a string in graphviz syntax for the given node.
             */
            std::string toGraphVizChild(size_t index, const Heap<T>::LR &lr, const std::string &parentNodeName) const;
        };
    }
}

/**
 * Output function for fom::AuD::Heap<T>.
 * Needs to be defined in header, see https://stackoverflow.com/questions/8752837/undefined-reference-to-template-class-constructor .
 */
template <typename T>
std::ostream &operator<<(std::ostream &os, const fom::AuD::Heap<T> &o)
{
    os << o.toString();
    return os;
}

namespace fom
{
    namespace AuD
    {
        template <typename T>
        Heap<T>::Heap() : Array<T>()
        {
        }

        template <typename T>
        Heap<T>::~Heap()
        {
        }

        template <typename T>
        void Heap<T>::heapify(size_t N, size_t i)
        {
            // Debug
            std::cout << "    heapify: i:" << i << " N:" << N << " | a[i]: " << (*this)[i] << std::endl;

            // Find largest element: root, root->left or root->right child

            // Initialize
            size_t largest = i;

            // position of left and right elements in array
            size_t left = 2 * i + 1;
            size_t right = 2 * i + 2;

            // left child is larger than root
            if (left < N && (*this)[left] > (*this)[largest])
                largest = left;

            // right child is larger than root and largest (= root or left child)
            if (right < N && (*this)[right] > (*this)[largest])
                largest = right;

            // If larger element found in children: swap
            if (largest != i)
            {
                std::cout << "       swap: i:" << i << " lg:" << largest << " | a[i]: " << (*this)[i] << " a[lg]: " << (*this)[largest] << std::endl;
                //  Largest element is now at root, "remove" it by placing it to end position
                this->swap(i, largest);

                // Recursively heapify the sub-tree below the affected node
                heapify(N, largest);
            }
        }

        template <typename T>
        std::string Heap<T>::toString() const
        {
            std::stringstream ss;
            ss << Array<T>::toString();
            return ss.str();
        }

        template <typename T>
        std::string Heap<T>::getGraphVizColorInfo(T val) const
        {
            // Not (yet?) implemented
            std::stringstream thisVal;
            thisVal << val;
            std::string thisValStr = thisVal.str();
            if (thisValStr == "some value")
            {
            }
            return std::string();
        }

        template <typename T>
        std::string Heap<T>::toGraphVizChild(size_t index, const Heap<T>::LR &lr, const std::string &parentNodeName) const
        {
            std::stringstream ss;

            std::stringstream thisVal;
            thisVal << this->at(index);
            std::string thisValStr = thisVal.str();

            ss << "    \"" << this->at(index) << "\" [label = \"<f0> |<f1>" << thisValStr << "|<f2> \" " << this->getGraphVizColorInfo(this->at(index)) << "];" << std::endl;

            if (lr == Heap<T>::Left)
            {
                ss << "    \"" << parentNodeName << "\":f0 -> \"" << thisValStr << "\":f1; " << std::endl;
            }
            else
            {
                ss << "    \"" << parentNodeName << "\":f2 -> \"" << thisValStr << "\":f1; " << std::endl;
            }

            size_t left = 2 * index + 1;
            size_t right = 2 * index + 2;
            if (this->size() > left)
                ss << this->toGraphVizChild(left, Heap<T>::Left, thisValStr);
            if (this->size() > right)
                ss << this->toGraphVizChild(right, Heap<T>::Right, thisValStr);

            return ss.str();
        }

        template <typename T>
        std::string Heap<T>::toGraphViz() const
        {
            std::stringstream ss;

            std::stringstream thisVal;
            thisVal << this->at(0);
            std::string thisValStr = thisVal.str();

            ss << "digraph Tree {" << std::endl;
            ss << "    node [shape = record,height=.1];" << std::endl;
            ss << "    \"root\" [label = \"<f0> |<f1>" << thisValStr << "|<f2> \" " << this->getGraphVizColorInfo(this->at(0)) << "];" << std::endl;

            size_t left = 1;
            size_t right = 2;
            if (this->size() > left)
                ss << this->toGraphVizChild(left, Heap<T>::Left, "root");
            if (this->size() > right)
                ss << this->toGraphVizChild(right, Heap<T>::Right, "root");

            ss << "}" << std::endl;
            return ss.str();
        }
    }
}

#endif // HEAP_H