#include <iostream>
#include <string>

#include "binsearchtree.h"

int main()
{    
    typedef fom::AuD::BinSearchTree<int> BinSearchTreeInt;
    //typedef fom::AuD::BinSearchTree<int> node;

    BinSearchTreeInt tree(15);

    tree.insert(10);
    tree.insert(25);
    tree.insert(13);
    tree.insert(21);
    tree.insert(22);
    tree.insert(23);
    tree.insert(24);
    tree.insert(9);
    tree.insert(12);
    //tree.insert(13); // Adding multiple identical entries not supported.
    tree.insert(8);
    tree.insert(7);
    tree.insert(26);
    tree.insert(27);

    std::cout << tree.toString() << std::endl;
    std::cout << tree.toGraphViz() << std::endl;

    std::cout << "#----- Creating an unbalanced tree." << std::endl;
    fom::AuD::BinTree<int> *tree2 = new BinSearchTreeInt(10);
    for (int i = 11; i < 15; ++i)
    {
        tree2->insert(i);
    }
    for (int i = 1; i < 9; ++i)
    {
        tree2->insert(i);
    }
    for (int i = 20; i < 25; ++i)
    {
        tree2->insert(i);
    }
    std::cout << tree2->toString() << std::endl;
    std::cout << tree2->toGraphViz() << std::endl;

    delete(tree2);

    return 0;
}