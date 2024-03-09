#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "array.h"

void array_print(const Array *a)
{
    // Iterate and print all elements from array.
    for (int i = 0; i < a->capacity; i++)
    {
        if (i < a->size)
        {
            printf("[%c]", a->elements[i]);
        }
        else
        {
            printf("[ ]");
        }
    }
    printf("\n");
}

void array_init(Array *a, int capacity)
{
    a->capacity = capacity;
    a->size = 0;
    a->elements = (char*) malloc(capacity);
}

void array_resize(Array* a, int new_capacity)
{
    if (new_capacity != a->capacity)
    {
        // Allocate new memory
        char* new_elements = (char*)malloc(new_capacity);
        // Copy data from old to new memory
        memcpy(new_elements, a->elements, a->size);
        // // "Manual way":
        // for (int i = 0; i < a->size; ++i)
        // {
        //     new_elements[i] = a->elements[i];
        // }
        // Free old memory
        free(a->elements);
        // Store new memory location and capacity
        a->elements = new_elements;
        a->capacity = new_capacity;
    }
}

void array_insert(Array *a, int idx, char value)
{
    // Increase size if necessary
    if (a->size >= a->capacity)
    {
        int new_capacity = (2 * a->capacity) + 1;
        array_resize(a, new_capacity);
    }

    // Copy all elements after idx to the right
    for (int i = a->size; i > idx; --i)
    {
        a->elements[i] = a->elements[i - 1];
    }
    // Insert new element at idx
    a->elements[idx] = value;
    a->size++;
}

char* array_at(const Array *a, int idx)
{
    if((idx > a->capacity) || (idx > a->size))
    {
        printf("Out of bounds.");
        return "\0";
    }

    return &(a->elements[idx]);
}

void array_push_back(Array* a, char value)
{
    array_insert(a, a->size, value);
}

char array_pop_back(Array* a)
{
    return array_remove(a, a->size - 1);
}

#pragma GCC diagnostic push
// Ignore -Wunused-parameter while function not yet implemented - remove me
#pragma GCC diagnostic ignored "-Wunused-parameter"
char array_remove(Array* a, int idx)
{
    // TODO
    return '\0';
}
#pragma GCC diagnostic pop

int array_find(Array* a, const char c)
{
    for (int i = 0; i < a->capacity; i++)
    {
        if (a->elements[i] == c)
        {
            return i;
        }
    }
    return -1;
}

void array_destroy(Array *a)
{
    a->capacity = 0;
    a->size = 0;
    free(a->elements);
}
