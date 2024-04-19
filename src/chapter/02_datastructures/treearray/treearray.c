#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "treearray.h"

size_t tree_getMaxNumberOfElements(size_t max_depth)
{
    // max_depth + 1 -> consider root node as depth 0
    // -1 -> root node is alone, no l+r
    size_t maxElements = pow(2, max_depth + 1) - 1;
    return maxElements;
}

void tree_initialize(TreeArray *t, size_t max_depth)
{
    size_t maxElements = tree_getMaxNumberOfElements(max_depth);
    t->elements = (char *)calloc(maxElements, sizeof(char));
    t->max_depth = max_depth;
}

void tree_destroy(TreeArray *t)
{
    free(t->elements);
    t->max_depth = 0;
}

void tree_set_root(TreeArray *t, char value)
{
    t->elements[0] = value;
}

size_t tree_set_left(TreeArray *t, char value, size_t parent)
{
    if (parent < tree_getMaxNumberOfElements(t->max_depth))
    {
        size_t elemPosition = (2 * parent) + 1; // l = +1
        t->elements[elemPosition] = value;
        return elemPosition;
    }
    return 0; // error
}

size_t tree_set_right(TreeArray *t, char value, size_t parent)
{
    if (parent < tree_getMaxNumberOfElements(t->max_depth))
    {
        size_t elemPosition = (2 * parent) + 2; // r = +2
        t->elements[elemPosition] = value;
        return elemPosition;
    }
    return 0; // error
}

char tree_remove(TreeArray *t, size_t parent)
{
    // printf("Remove: %zu [%c] \n", parent, t->elements[parent]);
    char c = '\0';
    if (parent < tree_getMaxNumberOfElements(t->max_depth))
    {
        c = t->elements[parent];

        t->elements[parent] = '\0';       // = Delete from tree
        tree_remove(t, (2 * parent) + 1); // Delete l
        tree_remove(t, (2 * parent) + 2); // Delete r

        return c;
    }
    return c;
}

void tree_print_node(TreeArray *t, size_t parent, size_t curDepth)
{
    if (curDepth <= t->max_depth)
    {
        if (t->elements[parent])
        {
            for (size_t i = 0; i < curDepth; ++i)
            {
                printf("   ");
            }
            printf("|--");
            printf("%c\n", t->elements[parent]);
            tree_print_node(t, (parent * 2) + 1, curDepth + 1);
            tree_print_node(t, (parent * 2) + 2, curDepth + 1);
        }
    }
}

void tree_print(TreeArray *t)
{
    tree_print_node(t, 0, 0);
}

void tree_print_dfs_preorder(TreeArray *t, size_t i)
{
    if (i >= tree_getMaxNumberOfElements(t->max_depth))
        return;

    if (t->elements[i])
    {
        printf("%c ", t->elements[i]);
        tree_print_dfs_preorder(t, 2 * i + 1);
        tree_print_dfs_preorder(t, 2 * i + 2);
    }
}

void tree_print_dfs_postorder(TreeArray *t, size_t i)
{
    if (i >= tree_getMaxNumberOfElements(t->max_depth))
        return;

    if (t->elements[i])
    {
        tree_print_dfs_postorder(t, 2 * i + 1);
        tree_print_dfs_postorder(t, 2 * i + 2);
        printf("%c ", t->elements[i]);
    }
}


void tree_print_dfs_inorder(TreeArray *t, size_t i)
{
    if (i >= tree_getMaxNumberOfElements(t->max_depth))
        return;

    if (t->elements[i])
    {
        tree_print_dfs_inorder(t, 2 * i + 1);
        printf("%c ", t->elements[i]);
        tree_print_dfs_inorder(t, 2 * i + 2);
    }
}

void tree_print_array(TreeArray *t)
{
    size_t maxElements = tree_getMaxNumberOfElements(t->max_depth);
    for (size_t i = 0; i < maxElements; ++i)
    {
        if (t->elements[i])
        {
            printf("[%c]", t->elements[i]);
        }
        else
        {
            printf("[-]");
        }
    }
    printf("\n");
}
