#include <string.h>
#include <stdio.h>

#include "insertionsortinplace.h"

#include "swap.h"

void array_sort_insertionsortinplace(Array *a)
{
	size_t i;
	int j;

	for (i = 1; i < a->size; i++)
	{
		int key = a->elements[i]; // Tmp store current element.
		j = (int)i - 1;

		// Compare key with each element on the left of it
		// until an element smaller than it found.
		while (j >= 0 && key < a->elements[j])
		{
			// shift every smaller element "one to the right"
			a->elements[j + 1] = a->elements[j];
			--j;
		}
		// Insert the current key to the found position.
		a->elements[j + 1] = key;

		// Debug
		printf("    %3zu: ", i);
		array_print(a);
	}
}
