#ifndef INSERTIONSORTINPLACE_H
#define INSERTIONSORTINPLACE_H

#include "intarray/intarray.h"

/**
 * Implementation of the Insertion Sort algorithm - in-place version.
 *
 * This is an optimized version of array_sort_insertionsort(),
 * swapping elements inplace instead of utilizing another array.
 * (This looks now similar to selection sort...)
 *
 * @param a array to be sorted.
 */
void array_sort_insertionsortinplace(Array *a);

#endif // INSERTIONSORTINPLACE_H