#ifndef ARRAY_H_
#define ARRAY_H_

/**
 * Our Array data structure.
 */
typedef struct Array
{
    /** Maximum capacity. */
    int capacity;
    /** Current size. */
    int size;
    /** Memory location of the first element. */
    char *elements;
} Array;

/**
 * Properly initializes any instance of Array.
 * This function must be called to ensure a proper "default state".
 *
 * Remember to call array_destroy() when done.
 *
 * @param a the array to be initialized.
 * @param capacity maximal capacity this Array can store.
 */
void array_init(Array *a, int capacity);

/**
 * Prints content of an Array to stdout.
 * @param a the array to be printed.
 */
void array_print(const Array *a);

/**
 * Insert a given object to a given Array.
 *
 * @param a the array the object is inserted.
 * @param idx the index at which the object is inserted.
 * @param value the object to be inserted to Array.
 */
void array_insert(Array *a, int idx, char value);

/**
 * Retrieve an object at a given index from a given Array.
 * This will just return a reference to the object, not delete it in the Array!
 *
 * @param a the array the object is stored in.
 * @param idx the index of interest
 * @return a pointer to the object (can be modified!).
 */
char *array_at(const Array *a, int idx);

/**
 * Retrieve and delete object at a given index from a given Array.
 *
 * @param a the array the object is stored in.
 * @param idx the index of interest
 * @return the object.
 */
char array_remove(Array *a, int idx);

/**
 * Insert an object in a given Array at the end.
 *
 * @param a the array the object will be stored in.
 * @param value the value to be stored.
 */
void array_push_back(Array *a, char value);

/**
 * Return and delete the last object from an array.
 *
 * @param a the array the object is stored in.
 * @return the object
 */
char array_pop_back(Array *a);

/**
 * Find the position of an object in the array.
 * @param a the array the object is stored in.
 * @param c the object to be found.
 * @return the index of the object in the array. -1 if not found.
 */
int array_find(Array *a, char c);

/**
 * Free's all memory. Opposite to "initialize".
 * @param a the array to be free'd from memory.
 */
void array_destroy(Array *a);

#endif // ARRAY_H_