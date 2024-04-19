#include <stdio.h>
#include <stdlib.h>

#include "intarray.h"

int main(void)
{
    printf("- %s, %d\n", __func__, __LINE__);

    Array a;
    array_init(&a, 10);

    array_insert(&a, 0, 42);
    array_insert(&a, 0, 90);
    array_insert(&a, 0, 85);
    array_push_back(&a, 65);
    array_push_back(&a, 82);
    array_print(&a);

    array_insert(&a, 1, 13);
    array_insert(&a, 1, 26);
    array_insert(&a, 1, 19);
    array_insert(&a, 1, 21);
    array_print(&a);

    array_push_back(&a, 6);
    array_push_back(&a, 8);
    array_push_back(&a, 12);
    array_push_back(&a, 7);
    array_push_back(&a, 25);
    array_push_back(&a, 9);
    array_push_back(&a, 11);
    array_push_back(&a, 16);
    array_print(&a);
    // Retrieve individual positions
    printf("Array pos %d: [%d]\n", 2, *(array_at(&a, 2)));
    printf("Array pos %d: [%d]\n", 3, *(array_at(&a, 3)));
    printf("Array pos %d: [%d]\n", 4, *(array_at(&a, 4)));

    // Modify value in Array
    int* tmp = array_at(&a, 4);
    *tmp = 22;
    printf("Array pos %d: [%d] (modified)\n", 4, *(array_at(&a, 4)));
    
    // Remove object
    array_remove(&a, 7);
    array_print(&a);

    array_push_back(&a, 99);
    array_print(&a);
    printf("Last elem was: [%d]\n", array_pop_back(&a));
    
    array_push_back(&a, 51);
    array_push_back(&a, 52);
    array_push_back(&a, 53);
    array_push_back(&a, 54);
    array_push_back(&a, 55);
    array_print(&a);
    printf("Position of '51': %d\n", array_find(&a, 51));
    printf("array_pop_back: [%d]\n", array_pop_back(&a) );
    array_print(&a);

    // Force shrink resize
    array_pop_back(&a);
    array_pop_back(&a);
    array_pop_back(&a);
    array_pop_back(&a);
    array_pop_back(&a);
    array_pop_back(&a);
    array_pop_back(&a);
    array_pop_back(&a);
    array_pop_back(&a);
    array_pop_back(&a);
    array_pop_back(&a);
    array_pop_back(&a);
    array_pop_back(&a);
    array_pop_back(&a);
    array_pop_back(&a);
    array_pop_back(&a);
    array_pop_back(&a);
    array_pop_back(&a);
    array_pop_back(&a);
    array_print(&a);

    // free resources
    array_destroy(&a);
    
    return 0;
}
