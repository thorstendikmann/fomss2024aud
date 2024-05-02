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
    
    array_push_back(&orig, 4);
    array_push_back(&orig, 3);
    array_push_back(&orig, 6);
    array_push_back(&orig, 1);
    array_push_back(&orig, 7);
    array_push_back(&orig, 5);
    array_push_back(&orig, 2);
    array_resize(&orig, orig.size); // trim to size
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

    printf("#---- Insertion Sort (inplace)\n");
    array_deepcopy(&orig,&a);
    array_print(&a);
    array_sort_insertionsortinplace(&a);
    array_print(&a);

    // free resources
    array_destroy(&a);
    array_destroy(&orig);

    return 0;
}
