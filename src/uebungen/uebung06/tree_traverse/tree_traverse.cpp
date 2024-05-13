#include <iostream>
#include <string>

extern "C"
{
#include "treearray/treearray.h"
}
#include "avltree/avltree.h"
#include "binsearchtree/binsearchtree.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
#endif

int main()
{
    std::cout << "#----- Traverse Tree." << std::endl;
    {
        typedef fom::AuD::BinSearchTree<char> BinSearchTreeChar;
        typedef fom::AuD::BinTree<char> * node;

        BinSearchTreeChar tree('A');
        node B = tree.addLeft('B');
        node C = tree.addRight('C');
        node D = B->addLeft('D');
        node G = D->addLeft('G');
        node H = D->addRight('H');
        node E = C->addLeft('E');
        node I = E->addRight('I');
        node F = C->addRight('F');
        node J = F->addLeft('J');
        node K = F->addRight('K');

        std::cout << "BFS     : " << tree.traverseBFS() << std::endl;
        std::cout << "DFS io  : " << tree.traverseDFS_inorder() << std::endl;
        std::cout << "DFS pre : " << tree.traverseDFS_preorder() << std::endl;
        std::cout << "DFS post: " << tree.traverseDFS_postorder() << std::endl;
        std::cout << tree.toGraphViz() << std::endl;
    }

}

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic pop
#endif
