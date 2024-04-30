#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "treeptr.h"

void tree_initialize(TreePtr *t)
{
    t->left = 0;
    t->right = 0;
    t->value = '\0';
}

void tree_destroy(TreePtr *t)
{
    if (t->left)
    {
        tree_destroy(t->left);
        free(t->left);
        t->left = 0;
    }
    if (t->right)
    {
        tree_destroy(t->right);
        free(t->right);
        t->right = 0;
    }

    t->value = '\0';
}

void tree_set(TreePtr *node, char value)
{
    node->value = value;
}

TreePtr *tree_set_left(TreePtr *parent, char value)
{
    // delete any current note if present
    if (parent->left)
        tree_destroy(parent->left);

    TreePtr *newNode = (TreePtr *)malloc(sizeof(TreePtr));
    tree_initialize(newNode);
    newNode->value = value;
    parent->left = newNode;
    return newNode;
}

TreePtr *tree_set_right(TreePtr *parent, char value)
{
    // delete any current note if present
    if (parent->right)
        tree_destroy(parent->right);

    TreePtr *newNode = (TreePtr *)malloc(sizeof(TreePtr));
    tree_initialize(newNode);
    newNode->value = value;
    parent->right = newNode;
    return newNode;
}

char tree_remove_left(TreePtr *node)
{
    char c;

    TreePtr *left = node->left;
    c = left->value;
    tree_destroy(left);
    free(left);
    node->left = 0;

    return c;
}

char tree_remove_right(TreePtr *node)
{
    char c;

    TreePtr *right = node->right;
    c = right->value;
    tree_destroy(right);
    free(right);
    node->right = 0;

    return c;
}

void tree_print(const TreePtr *t, size_t depth)
{
    if (t)
    {
        for (size_t i = 0; i < depth; ++i)
        {
            printf("    ");
        }
        printf("|---");
        printf("%c\n", t->value);
        if (t->left)
            tree_print(t->left, depth + 1);
        if (t->right)
            tree_print(t->right, depth + 1);
    }
}
