#ifndef DOUBLELINKEDLIST_H_
#define DOUBLELINKEDLIST_H_

/**
 * A list element.
 */
typedef struct node
{
    /** Reference to the next element. */
    struct node *next;
    /** Reference to the last element. */
    struct node *prev;
    /** Reference to the data. */
    char *value;
} node;

/**
 * DoubleLinkedList.
 */
typedef struct DoubleLinkedList
{
    /** Special node linking to the first element in the list. */
    node *head;
    /** Special node linking to the last element in the list. */
    node *tail;
} DoubleLinkedList;

/**
 * Internal helper function to create and initialize a new node in memory and return a reference to it.
 * @return reference to created node.
 */
node *doublelinkedlist_create_node(void);

/**
 * Internal helper function to properly free memory of a node.
 * @param n the node to be freed from memory.
 */
void doublelinkedlist_destroy_node(node *n);

/**
 * Properly initializes a DoubleLinkedList.
 * This will set l->head and l->tail.
 *
 * Remember to call doublelinkedlist_destroy() to free all resources.
 *
 * @param l the new DoubleLinkedList to be initialized.
 */
void doublelinkedlist_init(DoubleLinkedList *l);

/**
 * Frees all resources.
 *
 * @param l the new DoubleLinkedList to be initialized.
 */
void doublelinkedlist_destroy(DoubleLinkedList *l);

/**
 * Returns the size of the list.
 * Note: O(n) ... slow!
 *
 * @param l DoubleLinkedList list to operate on.
 * @return number of DoubleLinkedList elements.
 */
size_t doublelinkedlist_size(const DoubleLinkedList *l);

/**
 * Prints all DoubleLinkedList elements to stdout.
 *
 * @param l DoubleLinkedList to be printed.
 */
void doublelinkedlist_print(const DoubleLinkedList *l);

/**
 * Empty given DoubleLinkedList.
 * @param l DoubleLinkedList list to operate on.
 */
void doublelinkedlist_truncate(DoubleLinkedList *l);

/**
 * Returns the node from the linked list at a given index.
 * Note: Get data via node->value, but ensure node != 0!
 * Note: O(n) ... slow!
 *
 * @param l DoubleLinkedList list to operate on.
 * @param index given index.
 * @return node if index within boundaries, 0 if not.
 */
node *doublelinkedlist_at(DoubleLinkedList *l, size_t index);

/**
 * Insert object at a given index of the list.
 * If index > doublelinkedlist_size(): simply ignore.
 *
 * @param l DoubleLinkedList list to operate on.
 * @param index given index.
 * @param value the object to be inserted.
 * @return new list node, 0 if index not within boundaries.
 */
node *doublelinkedlist_insert(DoubleLinkedList *l, size_t index, char value);

/**
 * Insert object after given list element.
 *
 * @param l DoubleLinkedList list to operate on.
 * @param item predecessor for new object.
 * @param value the object to be inserted.
 * @return new list node (item->next will point here!).
 */
node *doublelinkedlist_insert_after(DoubleLinkedList *l, node *item, char value);

/**
 * Insert object after first given list object (data) in list.
 * Note: Slow, object first needs to be found!
 *
 * This is a convenience function to call doublelinkedlist_insert_after()
 * with data instead of a DoubleLinkedList node element.
 *
 * @param l DoubleLinkedList list to operate on.
 * @param object predecessor for new object.
 * @param value the object to be inserted.
 * @return new list node (item->next will point here!).
 */
node *doublelinkedlist_insert_after_object(DoubleLinkedList *l, char object, char value);

/**
 * Add an object to the front of the DoubleLinkedList and returns corresponding new node element.
 *
 * @param l DoubleLinkedList list to operate on.
 * @param value object to be inserted.
 * @return node element of the new first element.
 */
node *doublelinkedlist_push_front(DoubleLinkedList *l, char value);

/**
 * Add an object to the back of the DoubleLinkedList and returns corresponding new node element.
 *
 * @param l DoubleLinkedList list to operate on.
 * @param value object to be inserted.
 * @return node element of the new last element.
 */
node *doublelinkedlist_push_back(DoubleLinkedList *l, char value);

/**
 * Removes an element from a DoubleLinkedList and frees its resources.
 * Note: Slow, O(n) - previous element needs to be found first.
 *
 * @param l DoubleLinkedList list to operate on.
 * @param item the element to be removed.
 */
void doublelinkedlist_remove(DoubleLinkedList *l, node *item);

/**
 * Removes an element from a DoubleLinkedList after a given one and frees its resources.
 * Returns the value of the removed element.
 *
 * @param l DoubleLinkedList list to operate on.
 * @param item the element to be removed.
 * @return value of item, '\0' when there is no item->next.
 */
char doublelinkedlist_remove_after(DoubleLinkedList *l, node *item);

/**
 * Removes firsrt element from a DoubleLinkedList given by it's object (data).
 * Note: Slow, object first needs to be found!
 *
 * @param l DoubleLinkedList list to operate on.
 * @param object the element to be removed.
 */
void doublelinkedlist_remove_object(DoubleLinkedList *l, char object);

/**
 * Removed first object from list and returns its value.
 * Frees internal resources.
 *
 * @param l DoubleLinkedList list to operate on.
 * @return first object (data).
 */
char doublelinkedlist_pop_front(DoubleLinkedList *l);

/**
 * Removed last object from list and returns its value.
 * Frees internal resources.
 * Note: Fast - thx to DoubleLinkedList !!
 *
 * @param l DoubleLinkedList list to operate on.
 * @return last object (data).
 */
char doublelinkedlist_pop_back(DoubleLinkedList *l);

/**
 * Returns the DoubleLinkedList node element for the given object if stored in list.
 *
 * @param l DoubleLinkedList list to operate on.
 * @param value given value to be found in list.
 * @return node if value found, 0 if not.
 */
node *doublelinkedlist_find(DoubleLinkedList *l, char value);

/**
 * Returns the previous element in the list to the given one,
 * so that (returnedElement->next) == item.
 * Note: Fast - thx to DoubleLinkedList !!
 * Note: in a DoubleLinkedList reference to the list is not even needed as the node itself knows its previous element.
 *
 * @param l DoubleLinkedList list to operate on.
 * @param item given item whose predecessor to be found in list.
 * @return previous element in list if found, 0 otherwise.
 */
node *doublelinkedlist_find_previous(DoubleLinkedList *l, const node *item);

/**
 * Returns the DoubleLinkedList node element for the given object if stored in list.
 *
 * @param l DoubleLinkedList list to operate on.
 * @param value given value to be found in list.
 * @return node if value found, 0 if not.
 */
node *doublelinkedlist_find(DoubleLinkedList *l, char value);

#endif // DOUBLELINKEDLIST_H_