#ifndef HEAPSORT_H
#define HEAPSORT_H

#include "intarray/intarray.h"

/**
 * Implementation of the Heap Sort algorithm.
 * 
 * Call with l = 0 and r=a->size-1.
 * 
 * @param a array to be sorted.
 */
void array_sort_heapsort(Array *a);

#endif // HEAPSORT_H