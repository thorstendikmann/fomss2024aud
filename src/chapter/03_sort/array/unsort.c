#include <stdlib.h>
#include <time.h>

#include "swap.h"

#include "unsort.h"

void array_unsort(Array *a)
{
	size_t i, j, n;
	n = a->size;

	for (i = 0; i < n; i++)
	{
		j = rand() % a->size;
		array_swap(a, i, j);
	}
}
