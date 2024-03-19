#ifndef TREEPTR_H_
#define TREEPTR_H_

/**
 * A Binary Tree implementation based on pointers.
 */
typedef struct TreePtr
{
    /** Left child. */
    struct TreePtr *left;
    /** Right child. */
    struct TreePtr *right;
    /** Node's data. */
    char value;
} TreePtr;

/**
 * Properly initialize the TreePtr element.
 * @param t TreePtr to initialize.
 */
void tree_initialize(TreePtr *t);

/**
 * Free memory.
 * @param t TreePtr to free.
 */
void tree_destroy(TreePtr *t);

/**
 * Set the value of a node. Useful for the root node.
 * @param node TreePtr the tree node.
 * @param value The new value of the element.
 */
void tree_set(TreePtr *node, char value);

/**
 * Add a new left element to the given tree node.
 * @param parent TreePtr the tree node.
 * @param value The new value of the element.
 * @return pointer to the new element.
 */
TreePtr *tree_set_left(TreePtr *parent, char value);

/**
 * Add a new right element to the given tree node.
 * @param parent TreePtr the tree node.
 * @param value The new value of the element.
 * @return pointer to the new element.
 */
TreePtr *tree_set_right(TreePtr *parent, char value);

/**
 * Removes a right child element from a tree node.
 * @param node the (parent) tree node which child will be removed.
 * @return the value of the deleted child node.
 */
char tree_remove_right(TreePtr *node);

/**
 * Removes a left child element from a tree node.
 * @param node the (parent) tree node which child will be removed.
 * @return the value of the deleted child node.
 */
char tree_remove_left(TreePtr *node);

/**
 * Prints a tree to the commandline.
 * @param t the tree element to be printed.
 * @param depth useful for recursive pretty printing.
 * If root note given, start with 0.
 */
void tree_print(const TreePtr *t, size_t depth);

#endif // TREEPTR_H_