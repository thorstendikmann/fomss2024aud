#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linkedlist.h"

void linkedlist_printnode(node *n)
{
    printf("[%c | %p | -> %p]", *(n->value), (void *)n, (void *)n->next);
}

node *linkedlist_create_node(void)
{
    node *n;
    n = malloc(sizeof(node));
    n->value = malloc(sizeof(char));
    *(n->value) = '-'; // dummy value
    n->next = 0;
    return n;
}

void linkedlist_destroy_node(node *n)
{
    // free memory
    free(n->value);
    free(n);
}

void linkedlist_init(LinkedList *l)
{
    l->head = linkedlist_create_node();
    l->tail = linkedlist_create_node();
    l->head->next = l->tail;
    l->tail->next = l->head;
}

void linkedlist_destroy(LinkedList *l)
{
    printf("- %s, %d\n", __func__, __LINE__);
    linkedlist_print(l);

    node *n = l->head->next;
    node *destroy;
    // Quite brutal deletion of all nodes. Better properly remove.
    while (n != l->tail)
    {
        destroy = n; // save var
        n = n->next;
        linkedlist_destroy_node(destroy);
    }

    linkedlist_destroy_node(l->head);
    linkedlist_destroy_node(l->tail);
    l->head = 0;
    l->tail = 0;
}

void linkedlist_print(const LinkedList *l)
{
    size_t i = 0;
    node *curPtr = l->head->next;
    printf("[H    | %p | -> %p]\n", (void *)l->head, (void *)l->head->next);
    while (curPtr != 0 && curPtr != l->tail)
    {
        printf("   ");
        linkedlist_printnode(curPtr);
        curPtr = curPtr->next;
        printf("   %3zu\n", i++);
    }
    printf("[T    | %p | -> %p] = %3zu elements\n", (void *)l->tail, (void *)l->tail->next, linkedlist_size(l));
    printf("\n");
}

node *linkedlist_insert_after(LinkedList *l, node *item, char value)
{
    node *new_item = linkedlist_create_node();
    *(new_item->value) = value;

    // update links
    new_item->next = item->next;
    item->next = new_item;

    // if items was the last element, then update tail
    if (new_item->next == l->tail)
        l->tail->next = new_item;

    return new_item;
}
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"

char linkedlist_remove_after(LinkedList *l, node *item)
{
    // TODO
    return '\0';
}

size_t linkedlist_size(const LinkedList *l)
{
    // TODO
    return 0;
}

#pragma GCC diagnostic pop