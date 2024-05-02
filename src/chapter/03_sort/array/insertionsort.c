#include <string.h>
#include <stdio.h>

#include "insertionsort.h"

#include "swap.h"

void array_sort_insertionsort(Array *a)
{
	size_t i, j;

	Array tmpArray;
	array_init(&tmpArray, a->size);

	// Run original array from left to right.
	for (i = 0; i < a->size; ++i)
	{
		// For each element, insert at the "correct" position in tmpArray

		if (tmpArray.size == 0) // first element in tmpArray?
			array_push_back(&tmpArray, a->elements[i]);
		else
		{
			// Where to add current element to tmpArray?
			j = 0;
			// Find first element larger than current
			while (j < tmpArray.size && tmpArray.elements[j] < a->elements[i])
			{
				j++;
			}
			// insert current element at right position in tmpArray
			array_insert(&tmpArray, j, a->elements[i]);
		}

		// Debug
		printf("    %3zu: tmp array: ", i);
		array_print(&tmpArray);
	}

	// Copy values back to original array
	for (i = 0; i < a->size; ++i)
	{
		a->elements[i] = tmpArray.elements[i];
	}

	array_destroy(&tmpArray);
}
