#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "intarray/intarray.h"
#include "array/selectionsort.h"
#include "array/bubblesort.h"
#include "array/insertionsort.h"
#include "array/insertionsortinplace.h"
#include "array/mergesort.h"
#include "array/quicksort.h"
#include "array/heapsort.h"

int main(void)
{
    printf("- %s, %d\n", __func__, __LINE__);

    {
        printf("\n############################# ---------- Part 1 ----------n\n\n");
        Array a; // a copy on which we sort
        array_init(&a, 10);
        Array orig; // the original "unsorted" array
        array_init(&orig, 1);

        array_push_back(&orig, 7);
        array_push_back(&orig, 3);
        array_push_back(&orig, 5);
        array_push_back(&orig, 2);
        array_push_back(&orig, 6);
        array_push_back(&orig, 9);
        array_push_back(&orig, 1);
        array_push_back(&orig, 3);
        array_push_back(&orig, 8);
        array_resize(&orig, orig.size); // trim to size
        array_print(&orig);

        printf("#---- Selection Sort\n");
        array_deepcopy(&orig, &a);
        array_print(&a);
        array_sort_selectionsort(&a);
        array_print(&a);

        printf("#---- Bubble Sort\n");
        array_deepcopy(&orig, &a);
        array_print(&a);
        array_sort_bubblesort(&a);
        array_print(&a);

        printf("#---- Insertion Sort (inplace)\n");
        array_deepcopy(&orig, &a);
        array_print(&a);
        array_sort_insertionsortinplace(&a);
        array_print(&a);

        printf("#---- Merge Sort\n");
        array_deepcopy(&orig, &a);
        array_print(&a);
        array_sort_mergesort(&a, 0, a.size - 1);
        array_print(&a);

        printf("#---- Quick Sort\n");
        array_deepcopy(&orig, &a);
        array_print(&a);
        array_sort_quicksort(&a, 0, a.size - 1);
        array_print(&a);

        printf("#---- Heap Sort\n");
        array_deepcopy(&orig, &a);
        array_print(&a);
        array_sort_heapsort(&a);
        array_print(&a);

        // free resources
        array_destroy(&a);
        array_destroy(&orig);
    }
    {
        printf("\n############################# ---------- Part 2 ----------n\n\n");
        Array a; // a copy on which we sort
        array_init(&a, 10);
        Array orig; // the original "unsorted" array
        array_init(&orig, 1);

        array_push_back(&orig, 8);
        array_push_back(&orig, 1);
        array_push_back(&orig, 7);
        array_push_back(&orig, 11);
        array_push_back(&orig, 16);
        array_push_back(&orig, 12);
        array_push_back(&orig, 14);
        array_push_back(&orig, 5);
        array_push_back(&orig, 20);
        array_push_back(&orig, 4);
        array_resize(&orig, orig.size); // trim to size
        array_print(&orig);

        printf("#---- Selection Sort\n");
        array_deepcopy(&orig, &a);
        array_print(&a);
        array_sort_selectionsort(&a);
        array_print(&a);

        printf("#---- Bubble Sort\n");
        array_deepcopy(&orig, &a);
        array_print(&a);
        array_sort_bubblesort(&a);
        array_print(&a);

        printf("#---- Insertion Sort (inplace)\n");
        array_deepcopy(&orig, &a);
        array_print(&a);
        array_sort_insertionsortinplace(&a);
        array_print(&a);

        printf("#---- Merge Sort\n");
        array_deepcopy(&orig, &a);
        array_print(&a);
        array_sort_mergesort(&a, 0, a.size - 1);
        array_print(&a);

        printf("#---- Quick Sort\n");
        array_deepcopy(&orig, &a);
        array_print(&a);
        array_sort_quicksort(&a, 0, a.size - 1);
        array_print(&a);

        printf("#---- Heap Sort\n");
        array_deepcopy(&orig, &a);
        array_print(&a);
        array_sort_heapsort(&a);
        array_print(&a);

        // free resources
        array_destroy(&a);
        array_destroy(&orig);
    }

    return 0;
}
