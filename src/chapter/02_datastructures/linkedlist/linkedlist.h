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
 * Prints all LinkedList elements to stdout in a Graphviz format.
 *
 * @param l LinkedList to be printed.
 */
void linkedlist_print_graphviz(const LinkedList *l);

/**
 * Empty given LinkedList.
 * @param l LinkedList list to operate on.
 */
void linkedlist_truncate(LinkedList *l);

/**
 * Returns the node from the linked list at a given index.
 * Note: Get data via node->value, but ensure node != 0!
 * Note: O(n) ... slow!
 *
 * @param l LinkedList list to operate on.
 * @param index given index.
 * @return node if index within boundaries, 0 if not.
 */
node *linkedlist_at(LinkedList *l, size_t index);

/**
 * Insert object at a given index of the list.
 * If index > linkedlist_size(): simply ignore.
 *
 * @param l LinkedList list to operate on.
 * @param index given index.
 * @param value the object to be inserted.
 * @return new list node, 0 if index not within boundaries.
 */
node *linkedlist_insert(LinkedList *l, size_t index, char value);

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
 * Insert object after first given list object (data) in list.
 * Note: Slow, object first needs to be found!
 *
 * This is a convenience function to call linkedlist_insert_after()
 * with data instead of a LinkedList node element.
 *
 * @param l LinkedList list to operate on.
 * @param object predecessor for new object.
 * @param value the object to be inserted.
 * @return new list node (item->next will point here!).
 */
node *linkedlist_insert_after_object(LinkedList *l, char object, char value);

/**
 * Add an object to the front of the LinkedList and returns corresponding new node element.
 *
 * @param l LinkedList list to operate on.
 * @param value object to be inserted.
 * @return node element of the new first element.
 */
node *linkedlist_push_front(LinkedList *l, char value);

/**
 * Add an object to the back of the LinkedList and returns corresponding new node element.
 *
 * @param l LinkedList list to operate on.
 * @param value object to be inserted.
 * @return node element of the new last element.
 */
node *linkedlist_push_back(LinkedList *l, char value);

/**
 * Removes an element from a LinkedList and frees its resources.
 * Note: Slow, O(n) - previous element needs to be found first.
 *
 * @param l LinkedList list to operate on.
 * @param item the element to be removed.
 */
void linkedlist_remove(LinkedList *l, node *item);

/**
 * Removes an element from a LinkedList after a given one and frees its resources.
 * Returns the value of the removed element.
 *
 * @param l LinkedList list to operate on.
 * @param item the element to be removed.
 * @return value of item, '\0' when there is no item->next.
 */
char linkedlist_remove_after(LinkedList *l, node *item);

/**
 * Removes firsrt element from a LinkedList given by it's object (data).
 * Note: Slow, object first needs to be found!
 *
 * @param l LinkedList list to operate on.
 * @param object the element to be removed.
 */
void linkedlist_remove_object(LinkedList *l, char object);

/**
 * Removed first object from list and returns its value.
 * Frees internal resources.
 *
 * @param l LinkedList list to operate on.
 * @return first object (data).
 */
char linkedlist_pop_front(LinkedList *l);

/**
 * Removed last object from list and returns its value.
 * Frees internal resources.
 *
 * Note: Slow, O(n) - second-last object needs to be found first.
 *
 * @param l LinkedList list to operate on.
 * @return last object (data).
 */
char linkedlist_pop_back(LinkedList *l);

/**
 * Returns the LinkedList node element for the given object if stored in list.
 *
 * @param l LinkedList list to operate on.
 * @param value given value to be found in list.
 * @return node if value found, 0 if not.
 */
node *linkedlist_find(LinkedList *l, char value);

/**
 * Returns the previous element in the list to the given one,
 * so that (returnedElement->next) == item.
 * Note: Slow, O(n), worst case all items need to be iterated.
 *
 * @param l LinkedList list to operate on.
 * @param item given item whose predecessor to be found in list.
 * @return previous element in list if found, 0 otherwise.
 */
node *linkedlist_find_previous(LinkedList *l, const node *item);

/**
 * Returns the LinkedList node element for the given object if stored in list.
 *
 * @param l LinkedList list to operate on.
 * @param value given value to be found in list.
 * @return node if value found, 0 if not.
 */
node *linkedlist_find(LinkedList *l, char value);

#endif // LINKEDLIST_H_