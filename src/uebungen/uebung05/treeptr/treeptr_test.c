#include <stdio.h>
#include <stdlib.h>

#include "treeptr.h"

#if defined(__GNUC__) || defined(__clang__)
#  pragma GCC diagnostic push
#  pragma GCC diagnostic ignored "-Wunused-parameter"
#  pragma GCC diagnostic ignored "-Wunused-variable"
#  pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#endif

int main(void)
{
    printf("- %s, %d\n", __func__, __LINE__);

    TreePtr t;
    tree_initialize(&t);

    printf("\n--- Adding some elements\n");
    tree_set(&t, '0');
    TreePtr *A = tree_set_left(&t, 'A');
    TreePtr *M = tree_set_left(A, 'M');
    TreePtr *N = tree_set_right(A, 'N');
    TreePtr *B = tree_set_right(&t, 'B');
    tree_set_left(B, 'O');
    tree_set_right(B, 'P');
    tree_set_left(M, '1');
    tree_set_right(M, '2');

    tree_print(&t, 0);
    
    printf("\n--- Adding some children and then deleting parent [N].\n");
    tree_set_left(N, 'X');
    tree_set_right(N, 'Y');
    tree_print(&t, 0);
    printf("\nRemoved: %c\n", tree_remove_right(A));
    tree_print(&t, 0);
    printf("\nRemoved: %c\n", tree_remove_left(M));
    tree_print(&t, 0);

    tree_destroy(&t);

    return 0;
}

#if defined(__GNUC__) || defined(__clang__)
#  pragma GCC diagnostic pop
#endif
