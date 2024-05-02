#ifndef MERGESORT_H
#define MERGESORT_H

#include "intarray/intarray.h"

/**
 * Implementation of the Merge Sort algorithm.
 *
 * Call with l = 0 and r=a->size-1.
 *
 * @param a array to be sorted.
 * @param l left index of sub-array to be sorted.
 * @param l right index of sub-array to be sorted.
 */
void array_sort_mergesort(Array *a, size_t l, size_t r);

#endif // MERGESORT_H