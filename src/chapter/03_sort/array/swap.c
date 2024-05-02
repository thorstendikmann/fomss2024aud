#include <stdio.h>

#include "swap.h"

void array_swap(Array *a, size_t i, size_t j)
{
	// printf("Swapping %zu [%d] with %zu [%d]\n", i, a->elements[i], j, a->elements[j]);

	int tmp = a->elements[i];
	a->elements[i] = a->elements[j];
	a->elements[j] = tmp;
}
