#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

#include "intarray/intarray.h"

/**
 * Implementation of the Insertion Sort algorithm.
 *
 * This is a "naive" not-in-place implementation,
 * utilizing another array.
 * This consumes O(n) additional resources,
 * but shows best the function of the algorithms.
 *
 * @param a array to be sorted.
 */
void array_sort_insertionsort(Array *a);

#endif // INSERTIONSORT_H