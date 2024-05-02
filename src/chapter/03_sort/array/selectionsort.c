#include <stdio.h>

#include "selectionsort.h"

#include "swap.h"

void array_sort_selectionsort(Array *a)
{
	size_t i, j, min_idx;

	// Go from left to right.
	// Shift boundary of "unsorted subarray" one by one
	for (i = 0; i < a->size; i++)
	{
		// find minimum element in rest unsorted array
		min_idx = i;
		for (j = i + 1; j < a->size; j++)
			if (a->elements[j] < a->elements[min_idx])
				min_idx = j; // new minimum found

		// swap found minimum with the first element of unsorted subarray
		if (min_idx != i)
			array_swap(a, min_idx, i);

		// Debug
		printf("    %3zu: ", i);
		array_print(a);
	}
}
