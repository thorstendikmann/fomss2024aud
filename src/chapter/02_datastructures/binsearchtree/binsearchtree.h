#ifndef BINSEARCHTREE_H
#define BINSEARCHTREE_H

#include <iostream>
#include <string>
#include <sstream>

#include "bintree/bintree.h"

namespace fom
{
    namespace AuD
    {
        /**
         * Templated Binary Tree implementation in C++.
         */
        template <typename T>
        class BinSearchTree : public BinTree<T>
        {
            typedef BinSearchTree<T> node;

        public:
            /** Constructor. */
            explicit BinSearchTree(const T &val);
            /** Destructor, free's resources. */
            virtual ~BinSearchTree();

            /**
             * Insert an element at a position to fulfill criteria of a Binary Search Tree.
             *
             * @param val the value of the new node.
             * @return reference to new node.
             */
            virtual BinTree<T> *insert(const T &val) override;

            /**
             * Helper to output a BinTree.
             *
             * @return a String representation of the contents.
             */
            std::string toString() const;

            /**
             * Outputs a BinTree in GraphViz-readable format for visualization.
             *
             * @return a graphViz input.
             */
            std::string toGraphViz() const;

        protected:
            /**
             * Helper to create a new node and reserve memory for it.
             * This instantiation creates a BinSearchTree<T> node.
             * @param val reference to value to be stored internally.
             * @return pointer of the new object, can be added as child then.
             */
            virtual BinTree<T> *getNewNode(const T &val) override;
        };
    }
}

/**
 * Output function for fom::AuD::BinSearchTree<T>.
 * Needs to be defined in header, see https://stackoverflow.com/questions/8752837/undefined-reference-to-template-class-constructor .
 */
template <typename T>
std::ostream &operator<<(std::ostream &os, const fom::AuD::BinSearchTree<T> &o)
{
    os << o.toString();
    return os;
}

namespace fom
{
    namespace AuD
    {

        template <typename T>
        BinSearchTree<T>::BinSearchTree(const T &val) : BinTree<T>(val)
        {
        }

        template <typename T>
        BinSearchTree<T>::~BinSearchTree()
        {
            // superclass destructor called automatically!
        }

        template <typename T>
        BinTree<T> *BinSearchTree<T>::getNewNode(const T &val)
        {
            BinSearchTree<T> *newNode = new BinSearchTree<T>(val);
            return newNode;
        }

        template <typename T>
        BinTree<T> *BinSearchTree<T>::insert(const T &val)
        {
            if (val == this->getValue())
            {
                std::cerr << "Adding identical values not supported by this data structure. Ignoring." << std::endl;
                return 0;
            }

            std::cout << "Inserting " << val << " [Current: " << this->getValue() << "] | BST" << std::endl;

            if (val > this->getValue())
            {
                // right node

                if (!this->right)
                {
                    // if no right node, add it
                    return BinTree<T>::addRight(val);
                }
                else
                {
                    // otherwise: recursive call, but on inherited class
                    return this->right->insert(val);
                }
            }
            else
            {
                // left node

                if (!this->left)
                {
                    // if no left node, add it
                    return BinTree<T>::addLeft(val);
                }
                else
                {
                    // otherwise: recursive call, but on inherited class
                    return this->left->insert(val);
                }
            }
        }

        template <typename T>
        std::string BinSearchTree<T>::toString() const
        {
            return BinTree<T>::toString();
        }

        template <typename T>
        std::string BinSearchTree<T>::toGraphViz() const
        {
            return BinTree<T>::toGraphViz();
        }
    }
}

#endif // BINSEARCHTREE_H