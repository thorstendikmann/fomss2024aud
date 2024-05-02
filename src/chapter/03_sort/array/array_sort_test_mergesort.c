#include <stdio.h>
#include <stdlib.h>

#include "intarray/intarray.h"
#include "mergesort.h"

int main(void)
{
    printf("- %s, %d\n", __func__, __LINE__);

    Array a;
    array_init(&a, 10);

    array_push_back(&a, 5);
    array_push_back(&a, 3);
    array_push_back(&a, 2);
    array_push_back(&a, 4);
    array_push_back(&a, 6);
    array_push_back(&a, 1);
    array_push_back(&a, 7);
    array_push_back(&a, 3);
    array_resize(&a, a.size); // trim to size
    
    printf("#---- Merge Sort\n");
    array_print(&a);
    array_sort_mergesort(&a, 0, a.size-1);
    array_print(&a);

    // free resources
    array_destroy(&a);

    return 0;
}
