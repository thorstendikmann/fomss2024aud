#ifndef INTARRAY_H_
#define INTARRAY_H_

#include <stddef.h>
#include <stdint.h>

/**
 * Our Array data structure.
 */
typedef struct Array
{
    /** Maximum capacity. */
    size_t capacity;
    /** Current size. */
    size_t size;
    /** Memory location of the first element. */
    int *elements;
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
void array_init(Array *a, size_t capacity);

/**
 * Prints content of an Array to stdout.
 * @param a the array to be printed.
 */
void array_print(const Array *a);

/**
 * Prints partial content of an Array to stdout.
 * @param a the array to be printed partially.
 * @param l left index (from here ...)
 * @param r right index (... to here, including this!)
 */
void array_printlr(const Array *a, size_t l, size_t r);

/**
 * Insert a given object to a given Array.
 *
 * @param a the array the object is inserted.
 * @param idx the index at which the object is inserted.
 * @param value the object to be inserted to Array.
 */
void array_insert(Array *a, size_t idx, int value);

/**
 * Retrieve an object at a given index from a given Array.
 * This will just return a reference to the object, not delete it in the Array!
 *
 * @param a the array the object is stored in.
 * @param idx the index of interest
 * @return a pointer to the object (can be modified!).
 */
int *array_at(const Array *a, size_t idx);

/**
 * Retrieve and delete object at a given index from a given Array.
 *
 * @param a the array the object is stored in.
 * @param idx the index of interest
 * @return the object.
 */
int array_remove(Array *a, size_t idx);

/**
 * Insert an object in a given Array at the end.
 *
 * @param a the array the object will be stored in.
 * @param value the value to be stored.
 */
void array_push_back(Array *a, int value);

/**
 * Return and delete the last object from an array.
 *
 * @param a the array the object is stored in.
 * @return the object
 */
int array_pop_back(Array *a);

/**
 * Find the position of an object in the array.
 * @param a the array the object is stored in.
 * @param c the object to be found.
 * @return the index of the object in the array. -1 if not found.
 */
int array_find(Array *a, int c);

/**
 * Free's all memory. Opposite to "initialize".
 * @param a the array to be free'd from memory.
 */
void array_destroy(Array *a);

/**
 * Resize array to new capacity.
 * This is usually triggered automatically, but can be handy for some manual trimming.
 *
 * Ensure new_capacity >= a->size !!
 *
 * @param a the array to resize
 * @param new_capacity new number of elements this array can hold.
 */
void array_resize(Array *a, size_t new_capacity);

/**
 * (Deep) Copy all data from source to destination array.
 * 
 * This will clear all dest's content and create a copy
 * of each element in src.
 * 
 * @param src source array
 * @param dest destination array
 */
void array_deepcopy(Array *src, Array *dest);

#endif // INTARRAY_H_
