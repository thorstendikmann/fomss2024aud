#include <string.h>
#include <stdio.h>
#include "quicksort.h"

#include "swap.h"

int partition(Array *a, int l, int r)
{
	// // choose the pivot - take the last in the list.
	int pivot = a->elements[r];

	printf("    Partition with l:%3d, r:%3d | Pi %3i\n", l, r, pivot);

	// Index of smaller elements ("split indicator")
	int i = (l - 1);

	// j = iterator through array.
	for (int j = l; j <= r; j++)
	{
		if(i >= 0 && j >= 0)
		{
			printf("      i: %d [%d], j: %d [%d]", i, a->elements[i], j, a->elements[j]);
		}
		else
		{
			printf("      i: %d [?], j: %d [?]", i, j);
		}

		// Current element is smaller than the pivot?
		if (a->elements[j] < pivot)
		{
			// Increment split indicator
			i++;
			printf(" -- a[j]: [%d] < piv->%d | swap %d [%d] <-> %d [%d]", a->elements[j], pivot, i, a->elements[i], j, a->elements[j]);
			// ... and swap current element with the split indicator
			array_swap(a, i, j);
		}
		printf("\n");
	}
	printf("      swap %d [%d] <-> %d [%d] | (pivot swap)\n", i+1, a->elements[i+1], r, a->elements[r]);
	array_swap(a, i + 1, r);

	printf("      Partitioned Array: ");
	array_printlr(a, l, r);
	printf("  |  Split indicator position: %d\n", i+1);

	return (i + 1);
}

void array_sort_quicksort(Array *a, int l, int r)
{
	printf("  Quicksort with   l:%3d, r:%3d\n", l, r);
	if (l < r)
	{
		int q = partition(a, l, r);
		array_sort_quicksort(a, l, q - 1);
		array_sort_quicksort(a, q + 1, r);
	}
}
