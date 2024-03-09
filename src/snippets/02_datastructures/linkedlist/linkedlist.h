#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

/**
 * A list element.
 */
typedef struct node
{
    /** Reference to the next element. */
    struct node *next;
    /** Reference to the data. */
    char *value;
} node;

/**
 * LinkedList.
 */
typedef struct LinkedList
{
    /** Special node linking to the first element in the list. */
    node *head;
    /** Special node linking to the last element in the list. */
    node *tail;
} LinkedList;

/**
 * Internal helper function to create and initialize a new node in memory and return a reference to it.
 * @return reference to created node.
 */
node *linkedlist_create_node(void);

/**
 * Internal helper function to properly free memory of a node.
 * @param n the node to be freed from memory.
 */
void linkedlist_destroy_node(node *n);

/**
 * Properly initializes a LinkedList.
 * This will set l->head and l->tail.
 *
 * Remember to call linkedlist_destroy() to free all resources.
 *
 * @param l the new LinkedList to be initialized.
 */
void linkedlist_init(LinkedList *l);

/**
 * Frees all resources.
 *
 * @param l the new LinkedList to be initialized.
 */
void linkedlist_destroy(LinkedList *l);

/**
 * Returns the size of the list.
 * Note: O(n) ... slow!
 *
 * @param l LinkedList list to operate on.
 * @return number of LinkedList elements.
 */
size_t linkedlist_size(const LinkedList *l);

/**
 * Prints all LinkedList elements to stdout.
 *
 * @param l LinkedList to be printed.
 */
void linkedlist_print(const LinkedList *l);

/**
 * Insert object after given list element.
 *
 * @param l LinkedList list to operate on.
 * @param item predecessor for new object.
 * @param value the object to be inserted.
 * @return new list node (item->next will point here!).
 */
node *linkedlist_insert_after(LinkedList *l, node *item, char value);

/**
 * Removes an element from a LinkedList after a given one and frees its resources.
 * Returns the value of the removed element.
 *
 * @param l LinkedList list to operate on.
 * @param item the element to be removed.
 * @return value of item, '\0' when there is no item->next.
 */
char linkedlist_remove_after(LinkedList *l, node *item);

#endif // LINKEDLIST_H_