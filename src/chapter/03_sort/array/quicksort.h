#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "intarray/intarray.h"

/**
 * Implementation of the Quick Sort algorithm.
 *
 * Call with l = 0 and r=a->size-1.
 *
 * @param a array to be sorted.
 * @param l left index of sub-array to be sorted.
 * @param l right index of sub-array to be sorted.
 */
void array_sort_quicksort(Array *a, int l, int r);

#endif // QUICKSORT_H