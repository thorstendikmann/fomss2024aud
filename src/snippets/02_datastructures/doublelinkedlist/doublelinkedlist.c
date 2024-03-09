#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "doublelinkedlist.h"

void doublelinkedlist_printnode(node *n)
{
    printf("[%c | %p | -> %p]", *(n->value), (void *)n, (void *)n->next);
}

node *doublelinkedlist_create_node(void)
{
    node *n;
    n = malloc(sizeof(node));
    n->value = malloc(sizeof(char));
    *(n->value) = '-'; // dummy value
    n->next = 0;
    return n;
}

void doublelinkedlist_destroy_node(node *n)
{
    // free memory
    free(n->value);
    free(n);
}

void doublelinkedlist_init(DoubleLinkedList *l)
{
    l->head = doublelinkedlist_create_node();
    l->tail = doublelinkedlist_create_node();
    l->head->next = l->tail;
    l->tail->next = l->head;
}

void doublelinkedlist_destroy(DoubleLinkedList *l)
{
    doublelinkedlist_truncate(l);
    doublelinkedlist_destroy_node(l->head);
    doublelinkedlist_destroy_node(l->tail);
    l->head = 0;
    l->tail = 0;
}

size_t doublelinkedlist_size(const DoubleLinkedList *l)
{
    node *n = l->head->next;
    size_t i = 0;
    // Loop through whole list and count
    while (n != 0 && n != l->tail)
    {
        ++i;
        n = n->next;
    }
    return i;
}

void doublelinkedlist_print(const DoubleLinkedList *l)
{
    size_t i = 0;
    node *curPtr = l->head->next;
    printf("[H    | %p | -> %p]\n", (void *)l->head, (void *)l->head->next);
    while (curPtr != 0 && curPtr != l->tail)
    {
        printf("   ");
        doublelinkedlist_printnode(curPtr);
        curPtr = curPtr->next;
        printf("   %3zu\n", i++);
    }
    printf("[T    | %p | -> %p] = %3zu elements\n", (void *)l->tail, (void *)l->tail->next, doublelinkedlist_size(l));
    printf("\n");
}

void doublelinkedlist_truncate(DoubleLinkedList *l)
{
    node *n = l->head->next;
    while (n != 0 && n != l->tail)
    {
        n = n->next; // do before removing n ...
        doublelinkedlist_pop_front(l);
    }
}

node *doublelinkedlist_at(DoubleLinkedList *l, size_t index)
{
    node *n = l->head->next;
    size_t i = 0;
    // Loop through whole list until index reached.
    while (n != 0 && n != l->tail)
    {
        if (i == index)
        {
            return n;
        }

        ++i;
        n = n->next;
    }

    return 0;
}

node *doublelinkedlist_insert(DoubleLinkedList *l, size_t index, char value)
{
    // Catch special case for inserting as new first element
    if (index == 0)
    {
        return doublelinkedlist_push_front(l, value);
    }

    // Otherwise find the predecessor and insert_after it
    node *predecessor = doublelinkedlist_at(l, index - 1); // -1 = predecessor
    if (predecessor)
    {
        return doublelinkedlist_insert_after(l, predecessor, value);
    }

    return 0;
}

node *doublelinkedlist_insert_after(DoubleLinkedList *l, node *item, char value)
{
    node *new_item = doublelinkedlist_create_node();
    *(new_item->value) = value;

    // update links
    new_item->next = item->next;
    item->next = new_item;

    // if items was the last element, then update tail
    if (new_item->next == l->tail)
        l->tail->next = new_item;

    return new_item;
}

node *doublelinkedlist_insert_after_object(DoubleLinkedList *l, char object, char value)
{
    node *n = doublelinkedlist_find(l, object);
    if (n)
        return doublelinkedlist_insert_after(l, n, value);
    else
        return 0;
}

node *doublelinkedlist_push_front(DoubleLinkedList *l, char value)
{
    return doublelinkedlist_insert_after(l, l->head, value);
}

node *doublelinkedlist_push_back(DoubleLinkedList *l, char value)
{
    return doublelinkedlist_insert_after(l, l->tail->next, value);
}

void doublelinkedlist_remove(DoubleLinkedList *l, node *item)
{
    // Find predecessor element first
    node *previous = doublelinkedlist_find_previous(l, item);
    if (previous)
    {
        doublelinkedlist_remove_after(l, previous);
    }
}

char doublelinkedlist_remove_after(DoubleLinkedList *l, node *item)
{
    if (item == l->tail)
    {
        // Don't pass tail as arg!
        return '\0';
    }

    node *del_item = item->next;
    char value = '\0';

    // if not last item (=there is no "remove_after" the last!)
    if (del_item != l->tail)
    {
        value = *(del_item->value);

        // update pointers
        item->next = del_item->next;
        if (item->next == l->tail)
            l->tail->next = item; // if item was the second-last elem in list

        doublelinkedlist_destroy_node(del_item);
    }
    return value;
}

void doublelinkedlist_remove_object(DoubleLinkedList *l, char c)
{
    node *elem = doublelinkedlist_find(l, c);
    if (elem)
    {
        doublelinkedlist_remove(l, elem);
    }
}

char doublelinkedlist_pop_front(DoubleLinkedList *l)
{
    return doublelinkedlist_remove_after(l, l->head);
}

char doublelinkedlist_pop_back(DoubleLinkedList *l)
{
    char retChar = '\0';
    node *prev = doublelinkedlist_find_previous(l, l->tail);
    if (prev)
    {
        retChar = *(prev->value);
        doublelinkedlist_remove(l, prev);
    }
    return retChar;
}

node *doublelinkedlist_find(DoubleLinkedList *l, char value)
{
    node *curPtr = l->head;

    while (curPtr != l->tail)
    {
        if (*(curPtr->value) == value)
        {
            return curPtr;
        }
        curPtr = curPtr->next;
    }

    return 0;
}

node *doublelinkedlist_find_previous(DoubleLinkedList *l, node *item)
{
    node *previous = l->head;
    while (previous != 0 && previous != l->tail)
    {
        if (previous->next == item)
        {
            return previous;
        }
        previous = previous->next;
    }
    return 0;
}