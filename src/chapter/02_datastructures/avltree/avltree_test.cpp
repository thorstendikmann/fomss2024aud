#include <iostream>
#include <string>
#include <random>
#include <fstream>

#include "avltree.h"

int main()
{
    // typedef fom::AuD::AVLTree<int> AVLTreeInt;
    // typedef fom::AuD::AVLTree<int> node;

    std::cout << "#----- Adding elements and iteratively printing results." << std::endl;
    fom::AuD::BinTree<int> *tree = new fom::AuD::AVLTree<int>(10);
    tree = tree->balancedInsert(20);
    tree = tree->balancedInsert(30);
    std::cout << tree->toString() << std::endl;
    std::cout << tree->toGraphViz() << std::endl;
    tree = tree->balancedInsert(40);
    std::cout << tree->toString() << std::endl;
    std::cout << tree->toGraphViz() << std::endl;
    tree = tree->balancedInsert(50);
    std::cout << tree->toString() << std::endl;
    std::cout << tree->toGraphViz() << std::endl;
    tree = tree->balancedInsert(25);
    std::cout << tree->toString() << std::endl;
    std::cout << tree->toGraphViz() << std::endl;

    std::cout << std::endl
              << "#----- Trying the \"creating unbalanced tree\" example." << std::endl;
    fom::AuD::BinTree<int> *tree2 = new fom::AuD::AVLTree<int>(10);
    for (int i = 11; i < 15; ++i)
    {
        tree2 = tree2->balancedInsert(i);
    }
    for (int i = 1; i < 9; ++i)
    {
        tree2 = tree2->balancedInsert(i);
    }
    for (int i = 20; i < 25; ++i)
    {
        tree2 = tree2->balancedInsert(i);
    }
    std::cout << tree2->toString() << std::endl;
    std::cout << tree2->toGraphViz() << std::endl;

    std::cout << std::endl
              << "#----- Adding elements as in Binary Search Tree test program." << std::endl;
    fom::AuD::BinTree<int> *treebst = new fom::AuD::AVLTree<int>(15);
    treebst = treebst->balancedInsert(10);
    treebst = treebst->balancedInsert(25);
    treebst = treebst->balancedInsert(13);
    treebst = treebst->balancedInsert(21);
    treebst = treebst->balancedInsert(22);
    treebst = treebst->balancedInsert(23);
    treebst = treebst->balancedInsert(24);
    treebst = treebst->balancedInsert(9);
    treebst = treebst->balancedInsert(12);
    treebst = treebst->balancedInsert(8);
    treebst = treebst->balancedInsert(7);
    treebst = treebst->balancedInsert(26);
    treebst = treebst->balancedInsert(27);
    treebst = treebst->balancedInsert(6);
    treebst = treebst->balancedInsert(3);
    treebst = treebst->balancedInsert(1);
    // treebst = treebst->balancedInsert(4);
    // treebst = treebst->balancedInsert(2);
    std::cout << treebst->toString() << std::endl;
    std::cout << treebst->toGraphViz() << std::endl;

    std::string filename = "graph.out";
    std::cout << std::endl
              << "#----- Adding many random elements to tree and printing to file: " << filename << std::endl;

    std::random_device rd;                               // obtain random number from hardware
    std::mt19937 gen(rd());                              // seed the generator
    std::uniform_int_distribution<> distr(0, 100000000); // define the range

    for (int n = 0; n < 100; ++n)
    {
        treebst = treebst->balancedInsert(distr(gen));
    }

    std::ofstream myfile(filename);
    if (myfile.is_open())
    {
        myfile << treebst->toGraphViz();
        myfile.close();
    }
    else
        std::cout << "Unable to open file";

    delete(tree);
    delete(tree2);
    delete(treebst);    

    return 0;
}