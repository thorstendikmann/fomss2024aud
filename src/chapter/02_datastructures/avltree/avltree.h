#ifndef AVLTREE_H
#define AVLTREE_H

#include <iostream>
#include <string>
#include <sstream>

#include "binsearchtree/binsearchtree.h"

namespace fom
{
    namespace AuD
    {
        /**
         * Templated Binary Tree implementation in C++.
         */
        template <typename T>
        class AVLTree : public BinSearchTree<T>
        {
            typedef AVLTree<T> node;

        public:
            /** Constructor. */
            explicit AVLTree(T val);
            /** Destructor, free's resources. */
            virtual ~AVLTree();

            /**
             * Insert an element at a position to fulfill criteria of a AVL Tree.
             * This will rotate nodes if necessary to keep the tree balanced.
             *
             * Always returns the newest root node of the whole tree.
             *
             * @param val the value of the new node.
             * @return reference to new root node of the tree.
             */
            virtual BinTree<T> *balancedInsert(const T &val) override;

            /**
             * Right rotate nodes.
             *
             * This is only public here so we can manually call it for the rotation examples.
             * A AVL tree user does not need to see this internal feature.
             *
             * @param y to work on
             * @return reference to the new base node.
             */
            BinTree<T> *rightRotate(BinTree<T> *y);

            /**
             * Left rotate nodes.
             *
             * This is only public here so we can manually call it for the rotation examples.
             * A AVL tree user does not need to see this internal feature.
             *
             * @param x to work on
             * @return reference to the new base node.
             */
            BinTree<T> *leftRotate(BinTree<T> *x);

        protected:
            /**
             * Helper to create a new node and reserve memory for it.
             * This instantiation creates a AVLTree<T> node.
             * @param val reference to value to be stored internally.
             * @return pointer of the new object, can be added as child then.
             */
            virtual BinTree<T> *getNewNode(const T &val) override;
        };
    }
}

/**
 * Output function for fom::AuD::AVLTree<T>.
 * Needs to be defined in header, see https://stackoverflow.com/questions/8752837/undefined-reference-to-template-class-constructor .
 */
template <typename T>
std::ostream &operator<<(std::ostream &os, const fom::AuD::AVLTree<T> &o)
{
    os << o.toString();
    return os;
}

namespace fom
{
    namespace AuD
    {

        template <typename T>
        AVLTree<T>::AVLTree(T val) : BinSearchTree<T>(val)
        {
        }

        template <typename T>
        AVLTree<T>::~AVLTree()
        {
            // superclass destructor called automatically!
        }

        template <typename T>
        BinTree<T> *AVLTree<T>::getNewNode(const T &val)
        {
            // std::cout << "New node of type AVLTree." << std::endl;
            AVLTree<T> *newNode = new AVLTree<T>(val);
            return newNode;
        }

        template <typename T>
        BinTree<T> *AVLTree<T>::balancedInsert(const T &val)
        {
            std::cout << "  # -- Inserting " << val << " [Current: " << this->getValue() << "]" << std::endl;

            // Perform normal "Binary search tree" insertion

            // BinTree<T> *node = 0;
            if (val > this->getValue())
            {
                // right node

                if (!this->right)
                {
                    // std::cout << " R add" << std::endl;
                    // if no right node, add it
                    BinTree<T>::addRight(val);
                }
                else
                {
                    // std::cout << " R rek" << std::endl;
                    // otherwise: recursive call, but on inherited class
                    this->setRight(this->right->balancedInsert(val));
                }
            }
            else
            {
                // left node

                if (!this->left)
                {
                    // std::cout << " L add" << std::endl;
                    // if no left node, add it
                    BinTree<T>::addLeft(val);
                }
                else
                {
                    // std::cout << " L rek" << std::endl;
                    // otherwise: recursive call, but on inherited class
                    this->setLeft(this->left->balancedInsert(val));
                }
            }

            int balance = BinTree<T>::getBalance();
            // std::cout << "Balance " << balance << std::endl;
            if (balance > 1)
            {
                // rotate
                // std::cout << "Balance " << balance << " -> rotating." << std::endl;

                if (this->getLeft())
                {
                    // Left Left Case
                    if (val < this->getLeft()->getValue())
                    {
                        std::cout << "    # -- Left Left Rotation on " << this->getValue() << std::endl;
                        return this->rightRotate(this);
                    }
                    // Left Right Case
                    if (val > this->getLeft()->getValue())
                    {
                        std::cout << "    # -- Left Right Rotation L->" << this->getLeft()->getValue() << " then R->" << this->getValue() << std::endl;
                        this->setLeft(this->leftRotate(this->getLeft()));
                        return this->rightRotate(this);
                    }
                }
            }
            else if (balance < -1)
            {
                // rotate
                // std::cout << "Balance " << balance << " -> rotating." << std::endl;

                if (this->getRight())
                {
                    // Right Left Case
                    if (val < this->getRight()->getValue())
                    {
                        std::cout << "    # -- Right Left Rotation R->" << this->getRight()->getValue() << " then L->" << this->getValue() << std::endl;
                        this->setRight(this->rightRotate(this->getRight()));
                        return this->leftRotate(this);
                    }
                    // Right Right Case
                    if (val > this->getRight()->getValue())
                    {
                        std::cout << "    # -- Right Right Rotation on " << this->getValue() << std::endl;
                        return this->leftRotate(this);
                    }
                }
            }

            return this;
        }

        template <typename T>
        BinTree<T> *AVLTree<T>::rightRotate(BinTree<T> *y)
        {
            BinTree<T> *x;
            BinTree<T> *T2;
            // std::cout << "Right Rotation with " << y->getValue() << std::endl;
            x = y->getLeft();
            if (x)
                T2 = x->getRight();
            else
                T2 = 0;

            // Perform rotation
            if (x)
                x->setRight(y);
            if (y)
                y->setLeft(T2);

            return x;
        }

        template <typename T>
        BinTree<T> *AVLTree<T>::leftRotate(BinTree<T> *x)
        {
            BinTree<T> *y;
            BinTree<T> *T2;

            // std::cout << "Left Rotation with " << x->getValue() << std::endl;
            y = x->getRight();
            if (y)
                T2 = y->getLeft();
            else
                T2 = 0;

            // Perform rotation
            if (y)
                y->setLeft(x);
            if (x)
                x->setRight(T2);

            return y;
        }
    }
}

#endif // AVLTREE_H