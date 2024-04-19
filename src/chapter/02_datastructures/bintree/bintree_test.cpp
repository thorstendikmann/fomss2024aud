#include <iostream>
#include <string>

#include "bintree.h"

int main()
{
    typedef fom::AuD::BinTree<char> BinTreeChar;
    typedef fom::AuD::BinTree<char> node;

    BinTreeChar tree('*');

    node *n = tree.addLeft('+');
    n->addLeft('3');
    n->addRight('4');

    n = tree.addRight('-');
    n->addLeft('7');
    n->addRight('2');

    std::cout << "DFS Pre : " << tree.traverseDFS_preorder() << " | Height: " << tree.getLongestPath() -1 << std::endl;
    std::cout << "DFS Post: " << tree.traverseDFS_postorder() << " | Height: " << tree.getLongestPath() -1 << std::endl;
    std::cout << "DFS In  : " << tree.traverseDFS_inorder() << " | Height: " << tree.getLongestPath() -1 << std::endl;
    std::cout << "BFS     : " << tree.traverseBFS() << " | Height: " << tree.getLongestPath() -1 << std::endl;
    std::cout << "Graphviz:" << std::endl;
    std::cout << tree.toGraphViz() << std::endl;

    return 0;
}