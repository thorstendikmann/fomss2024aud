#include <stdio.h>
#include <stdlib.h>

#include "intarray/intarray.h"
#include "heapsort.h"

int main(void)
{
    printf("- %s, %d\n", __func__, __LINE__);

    Array a;
    array_init(&a, 10);

    array_push_back(&a, 5);
    array_push_back(&a, 8);
    array_push_back(&a, 2);
    array_push_back(&a, 4);
    array_push_back(&a, 6);
    array_push_back(&a, 1);
    array_push_back(&a, 7);
    array_push_back(&a, 3);
    array_resize(&a, a.size); // trim to size

    printf("#---- Heap Sort\n");
    array_print(&a);
    array_sort_heapsort(&a);
    array_print(&a);

    // free resources
    array_destroy(&a);

    printf("\n\n############################################\n\n");

    // Example from lecture / slides
    array_init(&a, 10);
    array_push_back(&a, 4);
    array_push_back(&a, 7);
    array_push_back(&a, 42);
    array_push_back(&a, 8);
    array_push_back(&a, 27);
    array_push_back(&a, 19);
    array_push_back(&a, 2);
    array_push_back(&a, 3);
    array_push_back(&a, 1);
    array_resize(&a, a.size); // trim to size

    printf("#---- Heap Sort II\n");
    array_print(&a);
    array_sort_heapsort(&a);
    array_print(&a);

    // free resources
    array_destroy(&a);

    return 0;
}
