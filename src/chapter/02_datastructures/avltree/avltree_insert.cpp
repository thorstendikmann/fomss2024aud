#include <iostream>
#include <string>

#include "avltree.h"

#if defined(__GNUC__) || defined(__clang__)
#  pragma GCC diagnostic push
#  pragma GCC diagnostic ignored "-Wunused-variable"
#  pragma GCC diagnostic ignored "-Wunused-local-typedefs"
#endif

int main()
{
    {
        typedef fom::AuD::BinTree<int> node;
        typedef fom::AuD::AVLTree<int> avlnode;
        node *newRoot = 0;

        std::cout << "#----- AVL insert as in script." << std::endl;
        fom::AuD::AVLTree<int> *root = new fom::AuD::AVLTree<int>(20);
        newRoot = root->balancedInsert(10);

        newRoot = newRoot->balancedInsert(9);
        std::cout << newRoot->toString() << std::endl;
        std::cout << newRoot->toGraphViz() << std::endl;
        newRoot = newRoot->balancedInsert(11);
        std::cout << newRoot->toString() << std::endl;
        std::cout << newRoot->toGraphViz() << std::endl;
        newRoot = newRoot->balancedInsert(21);
        std::cout << newRoot->toString() << std::endl;
        std::cout << newRoot->toGraphViz() << std::endl;
        newRoot = newRoot->balancedInsert(6);
        std::cout << newRoot->toString() << std::endl;
        std::cout << newRoot->toGraphViz() << std::endl;
        newRoot = newRoot->balancedInsert(7);
        std::cout << newRoot->toString() << std::endl;
        std::cout << newRoot->toGraphViz() << std::endl;
        newRoot = newRoot->balancedInsert(24);
        std::cout << newRoot->toString() << std::endl;
        std::cout << newRoot->toGraphViz() << std::endl;
        newRoot = newRoot->balancedInsert(29);

        std::cout << newRoot->toString() << std::endl;
        std::cout << newRoot->toGraphViz() << std::endl;

        delete (newRoot); // the new root node. Always delete root node!
    }

    std::cout << "#----- Some manual intermediate steps." << std::endl;
    {
        typedef fom::AuD::BinTree<int> node;
        typedef fom::AuD::AVLTree<int> avlnode;
        node *newRoot = 0;

        std::cout << "#----- AVL insert as in script." << std::endl;
        fom::AuD::AVLTree<int> *root = new fom::AuD::AVLTree<int>(20);
        newRoot = root->balancedInsert(10);

        newRoot = newRoot->balancedInsert(9);
        std::cout << newRoot->toString() << std::endl;
        std::cout << newRoot->toGraphViz() << std::endl;
        newRoot = newRoot->balancedInsert(11);
        std::cout << newRoot->toString() << std::endl;
        std::cout << newRoot->toGraphViz() << std::endl;
        newRoot = newRoot->balancedInsert(21);
        std::cout << newRoot->toString() << std::endl;
        std::cout << newRoot->toGraphViz() << std::endl;
        newRoot = newRoot->balancedInsert(6);
        std::cout << newRoot->toString() << std::endl;
        std::cout << newRoot->toGraphViz() << std::endl;

        // Get some nodes from the graph
        node *n10 = newRoot;
        node *n9 = n10->getLeft();
        node *n6 = n9->getLeft();

        // manually add 7
        n6->addRight(7);

        // Now we need to rebalance ... let's do this manually here

        std::cout << "#   --- pre manual Rotation I" << std::endl;
        std::cout << newRoot->toGraphViz() << std::endl;

        std::cout << "#   --- post manual Left Rotation on 6" << std::endl;
        n9->setLeft(dynamic_cast<avlnode *>(n6)->leftRotate(n6));
        std::cout << newRoot->toGraphViz() << std::endl;

        std::cout << "#   --- post manual Right Rotation on 9" << std::endl;
        n10->setLeft(dynamic_cast<avlnode *>(n9)->rightRotate(n9));
        std::cout << newRoot->toGraphViz() << std::endl;

        // Continue
        newRoot = newRoot->balancedInsert(24);
        std::cout << newRoot->toGraphViz() << std::endl;

        // Get some nodes from the graph
        n10 = newRoot;
        node *n20 = n10->getRight();
        node *n21 = n20->getRight();
        node *n24 = n21->getRight();

        // manually add 29
        n24->addRight(29);

        // Now we need to rebalance ... let's do this manually here

        std::cout << "#   --- pre manual Rotation II" << std::endl;
        std::cout << newRoot->toGraphViz() << std::endl;

        std::cout << "#   --- post manual Right Rotation on 21" << std::endl;
        n20->setRight(dynamic_cast<avlnode *>(n21)->leftRotate(n21));
        std::cout << newRoot->toGraphViz() << std::endl;

        delete (newRoot);
    }
}

#if defined(__GNUC__) || defined(__clang__)
#  pragma GCC diagnostic pop
#endif
