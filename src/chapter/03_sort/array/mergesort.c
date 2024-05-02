#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "mergesort.h"

#include "swap.h"

/**
 * Merges two subarrays of <em>a</em> in mergesort algorithms.
 *
 * - First subarray is a->elements[l..m].
 * - Second subarray is a->elements[m+1..r]
 *
 * @param a the array to work on.
 * @param l left boundary.
 * @param m midpoint.
 * @param r right boundary.
 */
void merge(Array *a, size_t l, size_t m, size_t r)
{
	size_t i, j, k;
	size_t n1 = m - l + 1; // num of left array elements
	size_t n2 = r - m;	   // num of right array elements

	printf("    merge  :     ");
	array_printlr(a, l, r);
	printf("\n");

	// create tmp merge arrays
	int* L = malloc(n1 * sizeof(size_t));
	int* R = malloc(n2 * sizeof(size_t));

	// copy data to tmp arrays L[] and R[]
	for (i = 0; i < n1; i++)
		L[i] = a->elements[l + i];
	for (j = 0; j < n2; j++)
		R[j] = a->elements[m + 1 + j];

	// merge tmp arrays back into arr[l..r]
	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2)
	{
		// take the smaller element from each sub-array
		// then increment this subarray one position
		if (L[i] <= R[j])
		{
			a->elements[k] = L[i];
			i++;
		}
		else
		{
			a->elements[k] = R[j];
			j++;
		}
		k++;
	}

	// copy remaining elements of L[], if any
	while (i < n1)
	{
		a->elements[k] = L[i];
		i++;
		k++;
	}

	// copy remaining elements of R[], if any
	while (j < n2)
	{
		a->elements[k] = R[j];
		j++;
		k++;
	}

	free(L);
	free(R);

	printf("    mresult:     ");
	array_printlr(a, l, r);
	printf("\n");
}

void array_sort_mergesort(Array *a, size_t l, size_t r)
{
	if (l < r)
	{
		size_t m = l + (r - l) / 2;

		printf("    msort  : ");
		array_printlr(a, l, r);
		printf("\n");

		// Divide into halfs and call recursively
		array_sort_mergesort(a, l, m);
		array_sort_mergesort(a, m + 1, r);

		// Merge result
		merge(a, l, m, r);
	}
}
