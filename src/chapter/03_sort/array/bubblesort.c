#include <stdio.h>

#include "bubblesort.h"

#include "swap.h"

void array_sort_bubblesort(Array *a)
{
	size_t i, j, n;
	n = a->size;

	// Run from left to right
	for (i = 0; i < n - 1; ++i)
	{
		// For all remaining unsorted elements from left to right ...
		// (We know "i"-elements are already sorted correctly at the right)
		for (j = 0; j < n - i - 1; ++j)
		{
			// ... if next element is larger than current -> swap!
			if (a->elements[j] > a->elements[j + 1])
			{
				array_swap(a, j, j + 1);
			}
		}

		// Debug
		printf("    %3zu: ", i);
		array_print(a);
	}
}
