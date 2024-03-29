#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "circularbuffer.h"

#if defined(__GNUC__) || defined(__clang__)
// Ignore -Wunused-parameter while function not yet implemented - remove me
#  pragma GCC diagnostic push
#  pragma GCC diagnostic ignored "-Wunused-parameter"
#endif

void circular_buffer_print(const CircularBuffer *c)
{
    if (!c)
        return;

    // print all elements "left to right"
    for (size_t i = 0; i < c->capacity; i++)
    {
        printf("[");

        // Indicate first and last field
        if (i == c->first)
        {
            printf(">");
        }
        printf("%c", c->elements[i]);
        if (i == c->last)
        {
            printf("<");
        }
        printf("]");
    }
    printf("\n");
}

void circular_buffer_init(CircularBuffer *c, size_t capacity)
{
    // TODO
}

char circular_buffer_pop_front(CircularBuffer *c)
{
    // TODO
    return '-';
}

void circular_buffer_push_back(CircularBuffer *c, char value)
{
    // TODO
}

char circular_buffer_pop_back(CircularBuffer *c)
{
    // TODO
    return '-';
}

char *circular_buffer_at(const CircularBuffer *c, size_t idx)
{
    // TODO
    return 0;
}

void circular_buffer_destroy(CircularBuffer *c)
{
    // TODO
}

#if defined(__GNUC__) || defined(__clang__)
#  pragma GCC diagnostic pop
#endif
