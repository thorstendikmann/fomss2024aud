#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "intarray.h"

void array_print(const Array *a)
{
    // Iterate and print all elements from array.
    for (size_t i = 0; i < a->capacity; i++)
    {
        if (i < a->size)
        {
            printf("[%d]", (int) a->elements[i]);
        }
        else
        {
            printf("[ ]");
        }
    }
    printf("\n");
}

void array_printlr(const Array *a, size_t l, size_t r)
{
    for (size_t i = l; i <= r; i++)
    {
        if (i < a->size)
        {
            printf("[%d]", (int) a->elements[i]);
        }
        else
        {
            printf("[ ]");
        }
    }
}

void array_init(Array *a, size_t capacity)
{
    a->capacity = capacity;
    a->size = 0;
    a->elements = (int*) malloc(capacity * sizeof(int));
}

void array_resize(Array* a, size_t new_capacity)
{
    if (new_capacity != a->capacity)
    {
        // Allocate new memory
        int* new_elements = (int*)malloc(new_capacity * sizeof(int));
        // Copy data from old to new memory
        memcpy(new_elements, a->elements, a->size * sizeof(int));
        free(a->elements);
        // Store new memory location and capacity
        a->elements = new_elements;
        a->capacity = new_capacity;
    }
}

void array_insert(Array *a, size_t idx, int value)
{
    // Increase size if necessary
    if (a->size >= a->capacity)
    {
        size_t new_capacity = (2 * a->capacity) + 1;
        array_resize(a, new_capacity);
    }

    // Copy all elements after idx to the right
    for (size_t i = a->size; i > idx; --i)
    {
        a->elements[i] = a->elements[i - 1];
    }
    // Insert new element at idx
    a->elements[idx] = value;
    a->size++;
}

int* array_at(const Array *a, size_t idx)
{
    if((idx > a->capacity) || (idx > a->size))
    {
        printf("Out of bounds.");
        return 0;
    }

    return &(a->elements[idx]);
}

void array_push_back(Array* a, int value)
{
    array_insert(a, a->size, value);
}

int array_pop_back(Array* a)
{
    return array_remove(a, a->size - 1);
}

int array_remove(Array* a, size_t idx)
{
    // Save element to be removed
    int temp = a->elements[idx];

    // Copy all elements after idx to the left, overriding the element to be removed
    a->size--;
    for (size_t i = idx; i < a->size; ++i)
    {
        a->elements[i] = a->elements[i + 1];
    }

    // Shrink if needed
    if (a->size <= a->capacity / 4)
    {
        int new_capacity = (a->capacity / 2) + 1 ;
        array_resize(a, new_capacity);
    }

    return temp;
}

int array_find(Array* a, int c)
{
    for (size_t i = 0; i < a->capacity; i++)
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

void array_deepcopy(Array *src, Array *dest)
{
    array_destroy(dest);
    array_init(dest, src->size);

    for(size_t i = 0; i < src->size; ++i)
    {
        array_push_back(dest, src->elements[i]);
    }

    array_resize(dest, src->capacity); // trim to same size
}
