#ifndef BINTREE_H
#define BINTREE_H

#include <iostream>
#include <string>
#include <sstream>

namespace fom
{
    namespace AuD
    {
        // #define node BinTree<T>;

        /**
         * Templated Binary Tree implementation in C++.
         *
         * Type has to implement operator<< to allow output.
         */
        template <typename T>
        class BinTree
        {
            typedef BinTree<T> node;

        public:
            /** Constructor. */
            explicit BinTree(const T &val);
            /** Destructor, free's resources. */
            virtual ~BinTree();

            /**
             * Update the value of the current object.
             * @param val reference to value to be stored internally.
             */
            void setValue(const T &val);

            /**
             * Add a left child note with a given value.
             * @param val reference to value to be stored internally.
             * @return pointer of the new child object.
             */
            BinTree<T> *addLeft(const T &val);

            /**
             * Add a right child note with a given value.
             * @param val reference to value to be stored internally.
             * @return pointer of the new child object.
             */
            BinTree<T> *addRight(const T &val);

            /**
             * Returns a textual representation of the BinTree, following
             *   depth-first-search, preorder
             * algorithms.
             * @return textual representation of the tree.
             */
            std::string traverseDFS_preorder() const;

            /**
             * Returns a textual representation of the BinTree, following
             *   depth-first-search, postorder
             * algorithms.
             * @return textual representation of the tree.
             */
            std::string traverseDFS_postorder() const;

            /**
             * Returns a textual representation of the BinTree, following
             *   depth-first-search, inorder
             * algorithms.
             * @return textual representation of the tree.
             */
            std::string traverseDFS_inorder() const;

            /**
             * Returns a textual representation of the BinTree, following
             *   breadth-first-search
             * algorithms.
             * @return textual representation of the tree.
             */
            std::string traverseBFS() const;

            /**
             * Returns the longest path length from the root to any leaf.
             * Note: height = getLongestPath - 1 // don't count root node!
             * @return longest path of the tree. If only root node, this will return 1!
             */
            size_t getLongestPath() const;

            /**
             * Returns the value of the current element.
             * @return element's value.
             */
            const T &getValue() const;

            /**
             * Helper to output a BinTree.
             *
             * @return a String representation of the contents.
             */
            std::string toString() const;

            /**
             * Outputs a BinTree in GraphViz-readabke format.
             * Only call this on the root node.
             *
             * @return a graphViz input.
             */
            std::string toGraphViz() const;

            /**
             * Insert an element - the implementation chooses where to place it best.
             * This function in this class is defined here with having in mind to overload it in derived classes.
             *
             * DOES NOTHING HERE!
             *
             * @param val the value of the new node.
             * @return reference to new node.
             */
            virtual BinTree<T> *insert(const T &val);

            /**
             * Insert an element at a position to fulfill criteria of a AVL Tree.
             *
             * DOES NOTHING HERE!
             *
             * @param val the value of the new node.
             * @return reference to new node.
             */
            virtual BinTree<T> *balancedInsert(const T &val);

            /**
             * Returns the balance of the number of left and right children.
             * @return balance. < 0 if more elements on right side, >0 if more elements on left side
             */
            int getBalance() const;

            /**
             * Getter for internal left variable.
             * @return left
             */
            BinTree<T> *getLeft() const;

            /**
             * Getter for internal right variable.
             * @return right
             */
            BinTree<T> *getRight() const;

            /**
             * Manually set the left child node.
             * @param n the new child node.
             */
            void setLeft(BinTree<T> *n);

            /**
             * Manually set the right child node.
             * @param n the new child node.
             */
            void setRight(BinTree<T> *n);

            /**
             * Right rotate nodes.
             * Defined here, but will be implemented in AVLTree subclass (necessary due to templating).
             *
             * DOES NOTHING HERE!
             *
             * @param y to work on
             * @return reference to the new base node.
             */
            BinTree<T> *rightRotate(BinTree<T> *y);

            /**
             * Left rotate nodes.
             * Defined here, but will be implemented in AVLTree subclass (necessary due to templating).
             *
             * DOES NOTHING HERE!
             *
             * @param x to work on
             * @return reference to the new base node.
             */
            BinTree<T> *leftRotate(BinTree<T> *x);

        protected:
            /**
             * Helper to create a new node and reserve memory for it.
             * Virtual to allow overriding in child classes.
             * @param val reference to value to be stored internally.
             * @return pointer of the new object, can be added as child then.
             */
            virtual BinTree<T> *getNewNode(const T &val);

            /**
             * Internal helper to print all nodes on the given level.
             * @param n current node.
             * @param level the level to be printed.
             * @return a String representation of the contents.
             */
            std::string printLevel(const BinTree<T> *n, size_t level) const;

            /** An internal indicator for printing if we're on the left or right node. */
            enum LR
            {
                /** Left node indicator. */
                Left = 0,
                /** Right node indicator. */
                Right = 1
            };

            /**
             * Internal function for printing a child element in Graphviz syntax.
             * @param lr indicator if this child node is its parent's left or right node.
             * @param parentNodeName the "label" of the parent node as used for graphviz.
             * @return a string in graphviz syntax for the given node.
             */
            std::string toGraphVizChild(BinTree<T>::LR lr, const std::string &parentNodeName) const;

            /**
             * Internal function for highlighting some nodes in Graphviz output.
             * This is kind'a hardcoded for the examples of the lecture.
             * @param val the value of the current node.
             * @return string with additional style information (or empty).
             */
            std::string getGraphVizColorInfo(const T &val) const;

            /** Pointer to left child item. */
            node *left;
            /** Pointer to right child item. */
            node *right;
            /** Stored data element. */
            T value;
        };
    }
}

/**
 * Output function for fom::AuD::BinTree<T>.
 * Needs to be defined in header, see https://stackoverflow.com/questions/8752837/undefined-reference-to-template-class-constructor .
 */
template <typename T>
std::ostream &operator<<(std::ostream &os, const fom::AuD::BinTree<T> &o)
{
    os << o.toString();
    return os;
}

namespace fom
{
    namespace AuD
    {

        template <typename T>
        BinTree<T>::BinTree(const T &val)
        {
            this->left = 0;
            this->right = 0;
            setValue(val);
        }

        template <typename T>
        BinTree<T>::~BinTree()
        {
            delete (this->left);
            delete (this->right);
            this->left = 0;
            this->right = 0;
        }

        template <typename T>
        void BinTree<T>::setValue(const T &val)
        {
            this->value = val;
        }

        template <typename T>
        BinTree<T> *BinTree<T>::getNewNode(const T &val)
        {
            BinTree<T> *newNode = new BinTree<T>(val);
            newNode->left = 0;
            newNode->right = 0;
            return newNode;
        }

        template <typename T>
        BinTree<T> *BinTree<T>::addLeft(const T &val)
        {
            this->left = getNewNode(val);
            return this->left;
        }

        template <typename T>
        BinTree<T> *BinTree<T>::addRight(const T &val)
        {
            this->right = getNewNode(val);
            return this->right;
        }

#if defined(__GNUC__) || defined(__clang__)
#  pragma GCC diagnostic push
#  pragma GCC diagnostic ignored "-Wunused-parameter"
#endif

        template <typename T>
        BinTree<T> *BinTree<T>::insert(const T &val)
        {
            // None here, implement in subclasses
            std::cerr << "#########################  Not implemented" << std::endl;
            return 0;
        }

        template <typename T>
        BinTree<T> *BinTree<T>::balancedInsert(const T &val)
        {
            // None here, implement in subclasses
            std::cerr << "#########################  Not implemented" << std::endl;
            return 0;
        }

        template <typename T>
        BinTree<T> *BinTree<T>::rightRotate(BinTree<T> *y)
        {
            // None here, implement in subclasses
            std::cerr << "#########################  Not implemented" << std::endl;
            return 0;
        }

        template <typename T>
        BinTree<T> *BinTree<T>::leftRotate(BinTree<T> *y)
        {
            // None here, implement in subclasses
            std::cerr << "#########################  Not implemented" << std::endl;
            return 0;
        }

#if defined(__GNUC__) || defined(__clang__)
#  pragma GCC diagnostic pop
#endif

        template <typename T>
        int BinTree<T>::getBalance() const
        {
            int lHeight = 0;
            int rHeight = 0;

            if (this->left)
                lHeight = (int)this->left->getLongestPath();
            if (this->right)
                rHeight = (int)this->right->getLongestPath();

            int returnInt = lHeight - rHeight;
            return returnInt;
        }

        template <typename T>
        BinTree<T> *BinTree<T>::getLeft() const
        {
            if (this->left) // added for debugging.
                return this->left;
            else
                return 0;
        }
        template <typename T>
        BinTree<T> *BinTree<T>::getRight() const
        {
            if (this->right) // added for debugging.
                return this->right;
            else
                return 0;
        }

        template <typename T>
        void BinTree<T>::setLeft(BinTree<T> *n)
        {
            this->left = n;
        }

        template <typename T>
        void BinTree<T>::setRight(BinTree<T> *n)
        {
            this->right = n;
        }

        template <typename T>
        std::string BinTree<T>::traverseDFS_preorder() const
        {
            std::stringstream ss;

            // Root
            ss << "[" << this->value << "] ";
            // Left
            if (this->left)
                ss << this->left->traverseDFS_preorder();
            // Right
            if (this->right)
                ss << this->right->traverseDFS_preorder();
            return ss.str();
        }

        template <typename T>
        std::string BinTree<T>::traverseDFS_postorder() const
        {
            std::stringstream ss;

            // Left
            if (this->left)
                ss << this->left->traverseDFS_postorder();
            // Right
            if (this->right)
                ss << this->right->traverseDFS_postorder();
            // Root
            ss << "[" << this->value << "] ";
            return ss.str();
        }

        template <typename T>
        std::string BinTree<T>::traverseDFS_inorder() const
        {
            std::stringstream ss;

            // Left
            if (this->left)
                ss << this->left->traverseDFS_inorder();
            // Root
            ss << "[" << this->value << "] ";
            // Right
            if (this->right)
                ss << this->right->traverseDFS_inorder();
            return ss.str();
        }

        template <typename T>
        std::string BinTree<T>::printLevel(const BinTree<T> *n, size_t level) const
        {
            std::stringstream ss;

            if (n == NULL)
                return ss.str();
            if (level == 1)
                ss << "[" << n->value << "] ";
            else if (level > 1)
            {
                ss << printLevel(n->left, level - 1);
                ss << printLevel(n->right, level - 1);
            }
            return ss.str();
        }

        template <typename T>
        std::string BinTree<T>::traverseBFS() const
        {
            std::stringstream ss;

            size_t h = this->getLongestPath();
            size_t i;
            for (i = 1; i <= h; i++)
                ss << printLevel(this, i);

            return ss.str();
        }

        template <typename T>
        size_t BinTree<T>::getLongestPath() const
        {
            // Compute the longest path of each subtree ... that's pretty much the hight incl. root node
            size_t lheight = 0;
            size_t rheight = 0;
            if (this->left)
                lheight = this->left->getLongestPath();
            if (this->right)
                rheight = this->right->getLongestPath();

            // Use the larger one
            if (lheight > rheight)
                return (lheight + 1);
            else
                return (rheight + 1);
        }

        template <typename T>
        const T &BinTree<T>::getValue() const
        {
            // std::cout << "Value: " << this->value << std::endl;
            return this->value;
        }

        template <typename T>
        std::string BinTree<T>::toString() const
        {
            std::stringstream ss;
            ss << this->traverseDFS_inorder();
            return ss.str();
        }

        template <typename T>
        std::string BinTree<T>::getGraphVizColorInfo(const T &val) const
        {
            std::stringstream ssVal;
            ssVal << val;
            std::string valAsStr = ssVal.str();

            std::stringstream ss;
            if (valAsStr == "z")
                ss << "fontcolor=\"#7030A0\" color=\"#7030A0\"";
            if (valAsStr == "y")
                ss << "fontcolor=\"#A10010\" color=\"#A10010\"";
            if (valAsStr == "x")
                ss << "fontcolor=\"#00A7E4\" color=\"#00A7E4\"";
            if (valAsStr.rfind("T", 0) == 0) // starts_with "T"
                ss << "fontcolor=\"#c0c0c0\" color=\"#c0c0c0\"";

            return ss.str();
        }

        template <typename T>
        std::string BinTree<T>::toGraphVizChild(BinTree<T>::LR lr, const std::string &parentNodeName) const
        {
            std::stringstream ss;

            std::stringstream thisVal;
            thisVal << this->value;
            std::string thisValStr = thisVal.str();

            ss << "    \"" << this->value << "\" [label = \"<f0> |<f1>" << thisValStr << "|<f2> \" " << this->getGraphVizColorInfo(this->value) << "];" << std::endl;

            if (lr == BinTree<T>::Left)
            {
                ss << "    \"" << parentNodeName << "\":f0 -> \"" << thisValStr << "\":f1; " << std::endl;
            }
            else
            {
                ss << "    \"" << parentNodeName << "\":f2 -> \"" << thisValStr << "\":f1; " << std::endl;
            }

            if (this->left)
                ss << this->left->toGraphVizChild(BinTree<T>::Left, thisValStr);
            if (this->right)
                ss << this->right->toGraphVizChild(BinTree<T>::Right, thisValStr);

            return ss.str();
        }

        template <typename T>
        std::string BinTree<T>::toGraphViz() const
        {
            std::stringstream ss;

            std::stringstream thisVal;
            thisVal << this->value;
            std::string thisValStr = thisVal.str();

            ss << "digraph Tree {" << std::endl;
            ss << "    node [shape = record,height=.1];" << std::endl;
            ss << "    \"root\" [label = \"<f0> |<f1>" << thisValStr << "|<f2> \" " << this->getGraphVizColorInfo(this->value) << "];" << std::endl;

            if (this->left)
                ss << this->left->toGraphVizChild(BinTree<T>::Left, "root");
            if (this->right)
                ss << this->right->toGraphVizChild(BinTree<T>::Right, "root");

            ss << "}" << std::endl;
            return ss.str();
        }

    }
}

#endif // BINTREE_H