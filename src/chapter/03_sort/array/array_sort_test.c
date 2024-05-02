#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "intarray/intarray.h"
#include "swap.h"
#include "unsort.h"
#include "selectionsort.h"
#include "bubblesort.h"
#include "insertionsort.h"
#include "insertionsortinplace.h"
#include "mergesort.h"
#include "quicksort.h"
#include "heapsort.h"

int main(void)
{
	srand (time(NULL));

    printf("- %s, %d\n", __func__, __LINE__);

    Array a;
    array_init(&a, 10);
    
    Array orig;
    array_init(&orig, 1);

    array_push_back(&orig, 15);
    array_push_back(&orig, 7);
    array_swap(&orig, 0, 1);

    array_push_back(&orig, 9);
    array_push_back(&orig, 11);
    array_swap(&orig, 2, 3);

    array_push_back(&orig, 13);
    array_push_back(&orig, 5);
    array_push_back(&orig, 3);
    array_push_back(&orig, 17);
    array_push_back(&orig, 19);
    array_push_back(&orig, 2);
    array_push_back(&orig, 4);
    array_push_back(&orig, 20);
    array_push_back(&orig, 18);
    array_push_back(&orig, 16);
    array_push_back(&orig, 6);
    array_push_back(&orig, 8);
    array_push_back(&orig, 12);
    array_push_back(&orig, 1);
    array_push_back(&orig, 30);
    array_push_back(&orig, 26);
    array_push_back(&orig, 21);
    array_push_back(&orig, 24);
    array_resize(&orig, orig.size); // trim to size

    // Shuffle a bit so every run looks different.
    array_unsort(&orig);
    array_print(&orig);

    printf("#---- Selection Sort\n");
    array_deepcopy(&orig,&a);
    array_print(&a);
    array_sort_selectionsort(&a);
    array_print(&a);

    printf("#---- Bubble Sort\n");
    array_deepcopy(&orig,&a);
    array_print(&a);
    array_sort_bubblesort(&a);
    array_print(&a);

    printf("#---- Insertion Sort\n");
    array_deepcopy(&orig,&a);
    array_print(&a);
    array_sort_insertionsort(&a);
    array_print(&a);

    printf("#---- Insertion Sort (inplace)\n");
    array_deepcopy(&orig,&a);
    array_print(&a);
    array_sort_insertionsortinplace(&a);
    array_print(&a);

    printf("#---- Quick Sort\n");
    array_deepcopy(&orig,&a);
    array_print(&a);
    array_sort_quicksort(&a, 0, a.size-1);
    array_print(&a);

    printf("#---- Heap Sort\n");
    array_deepcopy(&orig,&a);
    array_print(&a);
    array_sort_heapsort(&a);
    array_print(&a);

    printf("#---- Merge Sort\n");
    array_deepcopy(&orig,&a);
    array_print(&a);
    array_sort_mergesort(&a, 0, a.size-1);
    array_print(&a);

    // free resources
    array_destroy(&a);
    array_destroy(&orig);

    return 0;
}
