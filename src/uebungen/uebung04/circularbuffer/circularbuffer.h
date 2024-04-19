#ifndef CIRCULAR_BUFFER_H_
#define CIRCULAR_BUFFER_H_

#include <stddef.h>

/**
 * CircularBuffer data structure.
 */
typedef struct CircularBuffer
{
    /** Maximum capacity. */
    size_t capacity;
    /** Index of the first element stored. */
    size_t first;
    /** Index of the last element stored. */
    size_t last;
    /** Number of elements stored. */
    size_t size;
    /** Memory location of the first element. */
    char *elements;
} CircularBuffer;

/**
 * Properly initializes any instance of CircularBuffer.
 * This function must be called to ensure a proper "default state".
 *
 * Remember to call circular_buffer_destroy() when done.
 *
 * @param c the circular_buffer to be initialized.
 * @param capacity maximal capacity this CircularBuffer can store.
 */
void circular_buffer_init(CircularBuffer *c, size_t capacity);

/**
 * Prints content of an CircularBuffer to stdout.
 * @param c the circular_buffer to be printed.
 */
void circular_buffer_print(const CircularBuffer *c);

/**
 * Return the first object from a circular_buffer.
 * The position of the "first" object in the buffer will be updated 
 * (to what is before calling the "second" element).
 *
 * @param c the circular_buffer the object is stored in.
 * @return the object
 */
char circular_buffer_pop_front(CircularBuffer *c);

/**
 * Insert an object in a given CircularBuffer at the end.
 * 
 * The "last" element will be updated, now pointing to the new inserted.
 *
 * @param c the circular_buffer the object will be stored in.
 * @param value the value to be stored.
 */
void circular_buffer_push_back(CircularBuffer *c, char value);

/**
 * Return and delete the last object from a circular_buffer.
 * 
 * The "last" element will be updated to (last-1).
 *
 * @param c the circular_buffer the object is stored in.
 * @return the object stored.
 */
char circular_buffer_pop_back(CircularBuffer *c);

/**
 * Return the object address at the given position.
 * The returned object can be modified!
 * 
 * _Note:_ The idx refers to the stored elements, so
 * (idx = 0) => CircularBuffer.first
 * (idx = (CircularBuffer.size-1)) => CircularBuffer.last
 * This index does not refer to the internal memory location.
 * 
 * This function does not modify first or last position!
 *
 * @param c the circular_buffer the object is stored in.
 * @param idx the index to be retrieved.
 * @return the pointer to the object stored.
 */
char* circular_buffer_at(const CircularBuffer *c, size_t idx);

/**
 * Free's all memory. Opposite to "initialize".
 * @param c the circular_buffer to be free'd from memory.
 */
void circular_buffer_destroy(CircularBuffer *c);

#endif // CIRCULAR_BUFFER_H_