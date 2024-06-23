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
    std::cout << "#----- Tree Array." << std::endl;
    {
        TreeArray tree;

        size_t size = 13;
        char *values = (char *)malloc(size * sizeof(char));
        values[0] = 'M';
        values[1] = 'A';
        values[2] = 'T';
        values[3] = 'Q';
        values[4] = 'L';
        values[5] = 'U';
        values[6] = 'K';
        values[7] = 'N';
        values[8] = 'R';
        values[9] = 'W';
        values[10] = 'P';
        values[11] = 'H';
        values[12] = 'F';

        tree_initialize_fromArray(&tree, values, size);
        tree_print_array(&tree);
        tree_print_graphviz(&tree, 0);

        tree_destroy(&tree);
        free(values);
    }
    std::cout << "#----- Tree Array II." << std::endl;
    {
        TreeArray tree;

        size_t size = 18;
        char *values = (char *)malloc(size * sizeof(char));
        values[0] = 'A';
        values[1] = '4';
        values[2] = '7';
        values[3] = '*';
        values[4] = 'W';
        values[5] = '!';
        values[6] = 'L';
        values[7] = 'F';
        values[8] = '?';
        values[9] = '8';
        values[10] = '3';
        values[11] = 'M';
        values[12] = '1';
        values[13] = '=';
        values[14] = '&';
        values[15] = 'T';
        values[16] = 'D';
        values[17] = '9';

        tree_initialize_fromArray(&tree, values, size);
        tree_print_array(&tree);
        tree_print_graphviz(&tree, 0);

        tree_destroy(&tree);
        free(values);
    }

    std::cout << "#----- Binary Tree." << std::endl;
    {
        typedef fom::AuD::BinSearchTree<int> BinSearchTreeInt;

        BinSearchTreeInt tree(50);
        tree.insert(44);
        std::cout << tree.traverseBFS() << std::endl;
        std::cout << tree.toGraphViz() << std::endl;
        tree.insert(63);
        std::cout << tree.traverseBFS() << std::endl;
        std::cout << tree.toGraphViz() << std::endl;
        tree.insert(10);
        std::cout << tree.traverseBFS() << std::endl;
        std::cout << tree.toGraphViz() << std::endl;
        tree.insert(70);
        std::cout << tree.traverseBFS() << std::endl;
        std::cout << tree.toGraphViz() << std::endl;
        tree.insert(55);
        std::cout << tree.traverseBFS() << std::endl;
        std::cout << tree.toGraphViz() << std::endl;
        tree.insert(14);
        std::cout << tree.traverseBFS() << std::endl;
        std::cout << tree.toGraphViz() << std::endl;
        tree.insert(11);
        std::cout << tree.traverseBFS() << std::endl;
        std::cout << tree.toGraphViz() << std::endl;
        tree.insert(16);
        std::cout << tree.traverseBFS() << std::endl;
        std::cout << tree.toGraphViz() << std::endl;
        tree.insert(52);
        std::cout << tree.traverseBFS() << std::endl;
        std::cout << tree.toGraphViz() << std::endl;
        tree.insert(95);
        std::cout << tree.traverseBFS() << std::endl;
        std::cout << tree.toGraphViz() << std::endl;
        tree.insert(61);
        std::cout << tree.traverseBFS() << std::endl;
        std::cout << tree.toGraphViz() << std::endl;
        tree.insert(99);
        std::cout << tree.traverseBFS() << std::endl;
        std::cout << tree.toGraphViz() << std::endl;
    }

    std::cout << "#----- Balanced Tree." << std::endl;
    {
        fom::AuD::BinTree<int> *tree = new fom::AuD::AVLTree<int>(50);

        tree = tree->balancedInsert(44);
        std::cout << tree->traverseBFS() << std::endl;
        std::cout << tree->toGraphViz() << std::endl;
        tree = tree->balancedInsert(63);
        std::cout << tree->traverseBFS() << std::endl;
        std::cout << tree->toGraphViz() << std::endl;
        tree = tree->balancedInsert(10);
        std::cout << tree->traverseBFS() << std::endl;
        std::cout << tree->toGraphViz() << std::endl;
        tree = tree->balancedInsert(70);
        std::cout << tree->traverseBFS() << std::endl;
        std::cout << tree->toGraphViz() << std::endl;
        tree = tree->balancedInsert(55);
        std::cout << tree->traverseBFS() << std::endl;
        std::cout << tree->toGraphViz() << std::endl;
        tree = tree->balancedInsert(14);
        std::cout << tree->traverseBFS() << std::endl;
        std::cout << tree->toGraphViz() << std::endl;
        tree = tree->balancedInsert(11);
        std::cout << tree->traverseBFS() << std::endl;
        std::cout << tree->toGraphViz() << std::endl;
        tree = tree->balancedInsert(16);
        std::cout << tree->traverseBFS() << std::endl;
        std::cout << tree->toGraphViz() << std::endl;
        tree = tree->balancedInsert(52);
        std::cout << tree->traverseBFS() << std::endl;
        std::cout << tree->toGraphViz() << std::endl;
        tree = tree->balancedInsert(95);
        std::cout << tree->traverseBFS() << std::endl;
        std::cout << tree->toGraphViz() << std::endl;
        tree = tree->balancedInsert(61);
        std::cout << tree->traverseBFS() << std::endl;
        std::cout << tree->toGraphViz() << std::endl;
        tree = tree->balancedInsert(99);
        std::cout << tree->traverseBFS() << std::endl;
        std::cout << tree->toGraphViz() << std::endl;
        tree = tree->balancedInsert(12);
        std::cout << tree->traverseBFS() << std::endl;
        std::cout << tree->toGraphViz() << std::endl;

        delete(tree);
    }
}

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic pop
#endif
