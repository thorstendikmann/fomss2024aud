#include <stdio.h>
#include <stdlib.h>

#include "treearray.h"

int main(void)
{
    printf("- %s, %d\n", __func__, __LINE__);

    TreeArray t;
    tree_initialize(&t, 3);

    size_t r = 0;
    size_t r2 = 0;
    size_t r4 = 0;

    tree_set_root(&t, '0');
    r = tree_set_left(&t, 'A', 0);
    r2 = tree_set_left(&t, 'M', r);
    r4 = tree_set_right(&t, 'N', r);
    r = tree_set_right(&t, 'B', 0);
    r2 = tree_set_left(&t, 'O', r);
    r2 = tree_set_right(&t, 'P', r);

    tree_set_left(&t, '1', r2);
    tree_set_right(&t, '2', r2);

    tree_print_array(&t);
    tree_print(&t);
    
    tree_set_left(&t, 'X', r4);
    tree_set_right(&t, 'Y', r4);

    tree_print_array(&t);
    tree_print(&t);

    printf("Removed: %c\n", tree_remove(&t, r4));

    tree_print_array(&t);
    tree_print(&t);

    tree_destroy(&t);
    tree_initialize(&t, 3);

    printf("--- Adding something for Traversal.\n");
    tree_set_root(&t, '*');
    tree_set_left(&t, '+', 0);
    tree_set_left(&t, '3', 1);
    tree_set_right(&t, '4', 1);
    tree_set_right(&t, '-', 0);
    tree_set_left(&t, '7', 2);
    tree_set_right(&t, '2', 2);
    tree_print(&t);
    printf("\n--- Traversal: Preorder\n");
    tree_print_dfs_preorder(&t,0);
    printf("\n--- Traversal: Postorder\n");
    tree_print_dfs_postorder(&t,0);
    printf("\n--- Traversal: Inorder\n");
    tree_print_dfs_inorder(&t,0);
    printf("\n");

    tree_destroy(&t);

    return 0;
}
