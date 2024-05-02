#include <string.h>
#include <stdio.h>
#include "heapsort.h"

#include "swap.h"

/**
 * Helper function to build a max-heap in a given array.
 * @param a array to work on
 * @param N max right position - first run this will be usually a->size, but each iteration this is -1!
 * @param i The current node position in the array (0 = root)
 */
void heapify(Array *a, int N, int i)
{
	// Debug
	printf("    heapify: N:%2d i:%2d  | a[i]: %2d\n", N, i, a->elements[i]);

	// Find largest element: root, root->left or root->right child

	// Initialize
	int largest = i;

	// position of left and right elements in array
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	// left child is larger than root
	if (left < N && a->elements[left] > a->elements[largest])
		largest = left;

	// right child is larger than root and largest (= root or left child)
	if (right < N && a->elements[right] > a->elements[largest])
		largest = right;

	// If larger element found in children: swap
	if (largest != i)
	{
		printf("       swap: i:%2d largest idx:%2d | a[i]: %2d a[largest]: %2d => ", i, largest, a->elements[i], a->elements[largest]);
		// Largest element is now at root, "remove" it by placing it to end position
		array_swap(a, i, largest);
		array_print(a);

		// Recursively heapify the sub-tree below the affected node
		heapify(a, N, largest);
	}
}

void array_sort_heapsort(Array *a)
{
	printf("  Build max heap\n");

	// Build initial max heap
	int N = a->size;
	for (int i = N / 2 - 1; i >= 0; i--)
	{
		heapify(a, N, i);
	}
	printf("       heap after initial heapify: ");
	array_print(a);

	// Heap sort
	printf("  Heap sort\n");
	for (int i = N - 1; i >= 0; i--)
	{
		printf("       swapping largest elem %d at root to most right to pos %i  => ", a->elements[0], i);
		// We know: in each step, largest element is at root (=a[0])
		// "Swap out" to most right
		array_swap(a, 0, i);
		array_print(a);

		// Repeat max heap for new "swapped in" root,
		// but ignore all elements already "swapped out"
		// i = max size of unsorted array.
		heapify(a, i, 0);

		printf("       heapsort after max elem N=%i: ", i); // i is max right element in array!
		array_print(a);
	}
}
