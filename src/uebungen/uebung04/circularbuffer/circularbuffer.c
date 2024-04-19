#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "circularbuffer.h"

void circular_buffer_init(CircularBuffer *c, size_t capacity)
{
    c->capacity = capacity;
    c->first = 0;
    c->last = 0;
    c->size = 0;
    c->elements = (char *)calloc(capacity, sizeof(char));
}

void circular_buffer_print(const CircularBuffer *c)
{
    if (c && c->elements)
    {
        // print all elements "left to right"
        for (size_t i = 0; i < c->capacity; i++)
        {
            // Does current field contain data?
            int valid = ((i + c->first) % c->capacity) < c->last;

            printf("[");

            // Indicate first and last field
            if (i == c->first)
            {
                printf(">");
            }
            if (valid || 1)
            {
                printf("%c", c->elements[i]);
            }
            else
            {
                printf(" ");
            }
            if (i == c->last)
            {
                printf("<");
            }
            printf("]");
        }
        printf("\n");
    }
}

char circular_buffer_pop_front(CircularBuffer *c)
{
    if (c->size == 0)
    {
        printf("ERROR: Buffer empty.\n");
        return '-';
    }

    char returnElem;
    returnElem = c->elements[c->first];
    c->first = ((c->first + 1) % c->capacity);
    c->size--;

    if (c->size == 0)
    {
        c->last = c->first;
    }

    return returnElem;
}

void circular_buffer_push_back(CircularBuffer *c, char value)
{
    if (c->size == c->capacity)
    {
        printf("ERROR: Buffer full.\n");
        return;
    }

    if (c->size == 0) // empty, first element
    {
        // leave c->first == c->last, no increment
        c->elements[c->last % c->capacity] = value;
    }
    else
    {
        size_t newLast = (c->last + 1) % c->capacity;
        c->elements[newLast] = value;
        c->last = newLast;
    }
    c->size++;
}

char circular_buffer_pop_back(CircularBuffer *c)
{
    if (c->size == 0)
    {
        printf("ERROR: Buffer empty.\n");
        return '-';
    }

    char returnElem = c->elements[c->last % c->capacity];

    if (c->last == 0)
    {
        c->last = c->capacity - 1;
    }
    else
    {
        c->last--;
    }
    c->size--;

    if (c->size == 0)
    {
        c->last = c->first;
    }

    return returnElem;
}

char *circular_buffer_at(const CircularBuffer *c, size_t idx)
{
    if (c->size == 0)
    {
        printf("ERROR: Buffer empty.\n");
        return 0;
    }
    if (idx >= c->capacity)
    {
        printf("ERROR: Index out of bounds.\n");
        return 0;
    }

    char *returnChar;
    returnChar = &(c->elements[(idx + c->first) % c->capacity]);

    return returnChar;
}

void circular_buffer_destroy(CircularBuffer *c)
{
    c->capacity = 0;
    c->last = 0;
    c->first = 0;
    c->size = 0;
    free(c->elements);
}