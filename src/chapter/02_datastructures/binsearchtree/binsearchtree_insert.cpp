#include <iostream>
#include <string>

#include "binsearchtree.h"

int main()
{    
    std::cout << "#----- BST insert as in script." << std::endl;
    typedef fom::AuD::BinSearchTree<int> BinSearchTreeInt;

    BinSearchTreeInt tree(20);
    tree.insert(10);
    std::cout << tree.toString() << std::endl;
    std::cout << tree.toGraphViz() << std::endl;

    tree.insert(9);
    std::cout << tree.toString() << std::endl;
    std::cout << tree.toGraphViz() << std::endl;
    tree.insert(11);
    std::cout << tree.toString() << std::endl;
    std::cout << tree.toGraphViz() << std::endl;
    tree.insert(21);
    std::cout << tree.toString() << std::endl;
    std::cout << tree.toGraphViz() << std::endl;
    tree.insert(6);
    std::cout << tree.toString() << std::endl;
    std::cout << tree.toGraphViz() << std::endl;
    tree.insert(7);
    std::cout << tree.toString() << std::endl;
    std::cout << tree.toGraphViz() << std::endl;
    tree.insert(24);
    std::cout << tree.toString() << std::endl;
    std::cout << tree.toGraphViz() << std::endl;
    tree.insert(29);
    std::cout << tree.toString() << std::endl;
    std::cout << tree.toGraphViz() << std::endl;

    return 0;
}