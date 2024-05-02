#ifndef SWAP_H
#define SWAP_H

#include "intarray/intarray.h"

#include <stddef.h>
#include <stdint.h>

/**
 * Swap two elements in an array.
 * Basic feature for sorting algorithms.
 *
 * @param a the array to work on.
 * @param i element position 1.
 * @param j element position 2.
 */
void array_swap(Array *a, size_t i, size_t j);

#endif // SWAP_H