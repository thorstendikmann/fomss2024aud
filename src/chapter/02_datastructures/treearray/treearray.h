#ifndef TREEARRAY_H_
#define TREEARRAY_H_

/**
 * A Binary Tree implemented on an array structure.
 *
 * This utilizes a fixed-size non-sophisticated array internally,
 * therefore we need to fix the max_depth of this data structure.
 */
typedef struct TreeArray
{
    /** Maximum Depth. */
    size_t max_depth;
    /** Memory location of the elements. */
    char *elements;
} TreeArray;

/**
 * Properly initialize the given TreeArray.
 * @param t the new TreeArray to be initialized.
 * @param max_depth fixed maximal depth of the tree
 */
void tree_initialize(TreeArray *t, size_t max_depth);

/**
 * Free internal resources
 * @param t TreeArray to be destroyed.
 */
void tree_destroy(TreeArray *t);

/**
 * Conveniently set the tree's root node.
 * @param t TreeArray to work with.
 * @param value the new root's value.
 */
void tree_set_root(TreeArray *t, char value);

/**
 * Set the value of the left child for a given parent.
 * @param t TreeArray to work with.
 * @param value the new root's value.
 * @param parent index (!) of the parent's value.
 * @return the index of the value in the TreeArray.
 *
 */
size_t tree_set_left(TreeArray *t, char value, size_t parent);

/**
 * Set the value of the right child for a given parent.
 * @param t TreeArray to work with.
 * @param value the new root's value.
 * @param parent index (!) of the parent's value.
 * @return the index of the value in the TreeArray.
 */
size_t tree_set_right(TreeArray *t, char value, size_t parent);

/**
 * Returns a value from a tree at a given position.
 * Will then delete the value and all it's children from the tree.
 *
 * @param t TreeArray to work with.
 * @param parent index (!) of the parent's value.
 * @return value at the given position.
 */
char tree_remove(TreeArray *t, size_t parent);

/**
 * Initializes a tree from a given array.
 * 
 * Note: <tt>values</tt> can be free'd right after this call.
 * All values will be deep copied to internal data structure.
 *
 * @param t TreeArray to work with.
 * @param values pointer to the first value of the array.
 * @return the number of elements in the array.
 */
void tree_initialize_fromArray(TreeArray *t, char* values, size_t size);

/**
 * Print the tree in a tree-like structure.
 * @param t TreeArray to work with.
 */
void tree_print(TreeArray *t);

/**
 * Print the tree's internal memory as "flat array" from "left to right".
 * @param t TreeArray to work with.
 */
void tree_print_array(TreeArray *t);

/**
 * Print the tree as graphviz source.
 * @param t TreeArray to work with.
 * @param rootElem the element in the array to start with. If rootElem == 0, the graphviz header will be printed.
 */
void tree_print_graphviz(TreeArray *t, size_t rootElem);

/**
 * "Low-level" print tree elements following DFS-traversal, preorder.
 * ("Low-level" because we utilize the internal array structure here.)
 * @param t TreeArray to work with.
 * @param position the element in the internal array. 0 for root node.
 */
void tree_print_dfs_preorder(TreeArray *t, size_t position);
/**
 * See tree_print_dfs_preorder(), just postorder.
 * @param t TreeArray to work with.
 * @param position the element in the internal array. 0 for root node.
 */
void tree_print_dfs_postorder(TreeArray *t, size_t position);
/**
 * See tree_print_dfs_preorder(), just inorder.
 * @param t TreeArray to work with.
 * @param position the element in the internal array. 0 for root node.
 */
void tree_print_dfs_inorder(TreeArray *t, size_t position);

/**
 * Internal helper function to retrieve maximal number of
 * elements the full tree potentially has.
 * @param max_depth the maximal depth of the binary tree.
 * @return the max number of elements.
 */
size_t tree_getMaxNumberOfElements(size_t max_depth);

#endif // TREEARRAY_H_