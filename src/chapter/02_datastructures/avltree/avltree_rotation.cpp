#include <iostream>
#include <string>
#include <random>
#include <fstream>

#include "avltree.h"

#if defined(__GNUC__) || defined(__clang__)
#  pragma GCC diagnostic push
#  pragma GCC diagnostic ignored "-Wunused-variable"
#  pragma GCC diagnostic ignored "-Wunused-local-typedefs"
#endif

int main()
{
    // typedef fom::AuD::AVLTree<std::string> AVLTreeInt;
    typedef fom::AuD::BinTree<std::string> node;
    typedef fom::AuD::AVLTree<std::string> avlnode;

    node *newRoot = 0;
    std::cout << "#----- Simple rotation demo" << std::endl;
    {
        fom::AuD::AVLTree<std::string> *y = new fom::AuD::AVLTree<std::string>(std::string("y"));

        node *x = y->addLeft(std::string("x"));
        node *T3 = y->addRight(std::string("T3"));
        node *T1 = x->addLeft(std::string("T1"));
        node *T2 = x->addRight(std::string("T2"));

        std::cout << "#   --- pre Rotation" << std::endl;
        std::cout << y->toGraphViz() << std::endl;

        std::cout << "#   --- post Right Rotation" << std::endl;
        newRoot = y->rightRotate(y);
        std::cout << newRoot->toGraphViz() << std::endl;

        std::cout << "#   --- post Left Rotation" << std::endl;
        newRoot = dynamic_cast<avlnode *>(newRoot)->leftRotate(newRoot); // we need the derived class here!
        std::cout << newRoot->toGraphViz() << std::endl;                 // should look like the initial graph!!

        delete (newRoot); // that's the "new z" .. the new root node. Always delete root node!
    }

    std::cout << "#----- Left Left Case" << std::endl;
    {
        fom::AuD::AVLTree<std::string> *z = new fom::AuD::AVLTree<std::string>(std::string("z"));

        node *y = z->addLeft(std::string("y"));
        node *T4 = z->addRight(std::string("T4"));
        node *x = y->addLeft(std::string("x"));
        node *T3 = y->addRight(std::string("T3"));
        node *T1 = x->addLeft(std::string("T1"));
        node *T2 = x->addRight(std::string("T2"));

        std::cout << "#   --- pre Rotation" << std::endl;
        std::cout << z->toGraphViz() << std::endl;

        std::cout << "#   --- post Right Rotation" << std::endl;
        newRoot = z->rightRotate(z);
        std::cout << newRoot->toGraphViz() << std::endl;

        delete (newRoot); // that's the "new z" .. the new root node. Always delete root node!
    }

    std::cout << "#----- Right Right Case" << std::endl;
    {
        fom::AuD::AVLTree<std::string> *z = new fom::AuD::AVLTree<std::string>(std::string("z"));
        node *T1 = z->addLeft(std::string("T1"));
        node *y = z->addRight(std::string("y"));
        node *T2 = y->addLeft(std::string("T2"));
        node *x = y->addRight(std::string("x"));
        node *T3 = x->addLeft(std::string("T3"));
        node *T4 = x->addRight(std::string("T4"));

        std::cout << "#   --- pre Rotation" << std::endl;
        std::cout << z->toGraphViz() << std::endl;

        std::cout << "#   --- post Left Rotation" << std::endl;
        newRoot = z->leftRotate(z);
        std::cout << newRoot->toGraphViz() << std::endl;

        delete (newRoot);
    }

    std::cout << "#----- Left Right Case" << std::endl;
    {
        fom::AuD::AVLTree<std::string> *z = new fom::AuD::AVLTree<std::string>(std::string("z"));
        node *y = z->addLeft(std::string("y"));
        node *T4 = z->addRight(std::string("T4"));
        node *T1 = y->addLeft(std::string("T1"));
        node *x = y->addRight(std::string("x"));
        node *T2 = x->addLeft(std::string("T2"));
        node *T3 = x->addRight(std::string("T3"));

        std::cout << "#   --- pre Rotation" << std::endl;
        std::cout << z->toGraphViz() << std::endl;

        std::cout << "#   --- post Left Rotation on y" << std::endl;
        z->setLeft(dynamic_cast<avlnode *>(y)->leftRotate(y)); // on y !! Dynamic cast to get derived class.
        std::cout << z->toGraphViz() << std::endl;

        std::cout << "#   --- post Right Rotation on z" << std::endl;
        newRoot = z->rightRotate(z);
        std::cout << newRoot->toGraphViz() << std::endl;

        delete (newRoot);
    }

    std::cout << "#----- Right Left Case" << std::endl;
    {
        fom::AuD::AVLTree<std::string> *z = new fom::AuD::AVLTree<std::string>(std::string("z"));
        node *T1 = z->addLeft(std::string("T1"));
        node *y = z->addRight(std::string("y"));
        node *x = y->addLeft(std::string("x"));
        node *T4 = y->addRight(std::string("T4"));
        node *T2 = x->addLeft(std::string("T2"));
        ;
        node *T3 = x->addRight(std::string("T3"));

        std::cout << "#   --- pre Rotation" << std::endl;
        std::cout << z->toGraphViz() << std::endl;

        std::cout << "#   --- post Right Rotation on y" << std::endl;
        z->setRight(dynamic_cast<avlnode *>(y)->rightRotate(y)); // on y !! Dynamic cast to get derived class.
        std::cout << z->toGraphViz() << std::endl;

        std::cout << "#   --- post Left Rotation on z" << std::endl;
        newRoot = z->leftRotate(z);
        std::cout << newRoot->toGraphViz() << std::endl;

        delete (newRoot);
    }

    return 0;
}

#if defined(__GNUC__) || defined(__clang__)
#  pragma GCC diagnostic pop
#endif
