#include <stdio.h>
#include <stdlib.h>

#include "array.h"

int main(void)
{
    printf("- %s, %d\n", __func__, __LINE__);

    Array a;
    array_init(&a, 10);
    array_insert(&a, 0, 'A');
    array_insert(&a, 1, 'B');
    array_insert(&a, 2, 'C');
    array_insert(&a, 3, 'D');
    array_insert(&a, 4, 'E');
    array_insert(&a, 5, 'F');
    array_insert(&a, 6, 'G');
    array_insert(&a, 7, 'H');
    array_print(&a);
    // Retrieve individual positions
    printf("Array pos %d: [%c]\n", 2, *(array_at(&a, 2)));
    printf("Array pos %d: [%c]\n", 3, *(array_at(&a, 3)));
    printf("Array pos %d: [%c]\n", 4, *(array_at(&a, 4)));

    // Modify value in Array
    char* tmp = array_at(&a, 4);
    *tmp = 'M';
    printf("Array pos %d: [%c] (modified)\n", 4, *(array_at(&a, 4)));
    
    // Remove object
    array_remove(&a, 7);
    array_print(&a);

    array_push_back(&a, 'I');
    array_print(&a);
    printf("Last elem was: [%c]\n", array_pop_back(&a));
    
    array_push_back(&a, 'J');
    array_push_back(&a, 'K');
    array_push_back(&a, 'L');
    array_push_back(&a, 'M');
    array_push_back(&a, 'N');
    array_push_back(&a, 'O');
    array_print(&a);
    printf("Position of 'K': %d\n", array_find(&a, 'K'));
    printf("array_pop_back: [%c]\n", array_pop_back(&a) );
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
    array_print(&a);

    // free resources
    array_destroy(&a);
    
    return 0;
}
