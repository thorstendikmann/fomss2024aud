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
    linkedlist_truncate(l);
    linkedlist_destroy_node(l->head);
    linkedlist_destroy_node(l->tail);
    l->head = 0;
    l->tail = 0;
}

size_t linkedlist_size(const LinkedList *l)
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

void linkedlist_truncate(LinkedList *l)
{
    node *n = l->head->next;
    while (n != 0 && n != l->tail)
    {
        n = n->next; // do before removing n ...
        linkedlist_pop_front(l);
    }
}

node *linkedlist_at(LinkedList *l, size_t index)
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

node *linkedlist_insert(LinkedList *l, size_t index, char value)
{
    // Catch special case for inserting as new first element
    if (index == 0)
    {
        return linkedlist_push_front(l, value);
    }

    // Otherwise find the predecessor and insert_after it
    node *predecessor = linkedlist_at(l, index - 1); // -1 = predecessor
    if (predecessor)
    {
        return linkedlist_insert_after(l, predecessor, value);
    }

    return 0;
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

node *linkedlist_insert_after_object(LinkedList *l, char object, char value)
{
    node *n = linkedlist_find(l, object);
    if (n)
        return linkedlist_insert_after(l, n, value);
    else
        return 0;
}

node *linkedlist_push_front(LinkedList *l, char value)
{
    return linkedlist_insert_after(l, l->head, value);
}

node *linkedlist_push_back(LinkedList *l, char value)
{
    return linkedlist_insert_after(l, l->tail->next, value);
}

void linkedlist_remove(LinkedList *l, node *item)
{
    // Find predecessor element first
    node *previous = linkedlist_find_previous(l, item);
    if (previous)
    {
        linkedlist_remove_after(l, previous);
    }
}

char linkedlist_remove_after(LinkedList *l, node *item)
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

        linkedlist_destroy_node(del_item);
    }
    return value;
}

void linkedlist_remove_object(LinkedList *l, char c)
{
    node *elem = linkedlist_find(l, c);
    if (elem)
    {
        linkedlist_remove(l, elem);
    }
}

char linkedlist_pop_front(LinkedList *l)
{
    return linkedlist_remove_after(l, l->head);
}

char linkedlist_pop_back(LinkedList *l)
{
    char retChar = '\0';
    node *prev = linkedlist_find_previous(l, l->tail);
    if (prev)
    {
        retChar = *(prev->value);
        linkedlist_remove(l, prev);
    }
    return retChar;
}

node *linkedlist_find(LinkedList *l, char value)
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

node *linkedlist_find_previous(LinkedList *l, const node *item)
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

void linkedlist_print_graphviz(const LinkedList *l)
{
    printf("digraph g {\n");
    printf("graph [\n");
    printf("  rankdir = \"LR\"\n");
    printf("];\n");

    printf("\"%p\" [\n", (void *)l->head);
    printf("    label = \"<f0> %p | <f1> Head\"\n", (void *)l->head);
    printf("    style = \"filled\"\n");
    printf("    fillcolor = \"#9dc4c4\"\n");
    printf("    shape = \"record\"\n");
    printf("];\n");

    // Nodes
    {
        node *curPtr = l->head->next;
        while (curPtr != 0 && curPtr != l->tail)
        {
            printf("\"%p\" [\n", (void *)curPtr);
            printf("    label = \"<f0> %p | <f1> %c\"\n", (void *)curPtr, *(curPtr->value));
            printf("    shape = \"record\"");
            printf("];\n");

            curPtr = curPtr->next;
        }
    }

    printf("\"%p\" [\n", (void *)l->tail);
    printf("    label = \"<f0> %p | <f1> Tail\"\n", (void *)l->tail);
    printf("    style = \"filled\"\n");
    printf("    fillcolor = \"#9dc4c4\"\n");
    printf("    shape = \"record\"\n");
    printf("];\n");

    // Links
    {
        node *curPtr = l->head;
        printf("\"%p\" -> \"%p\"\n", (void *)curPtr, (void *)curPtr->next);
        curPtr = curPtr->next;
        
        while (curPtr != 0 && curPtr != l->tail)
        {
            printf("\"%p\" -> \"%p\"\n", (void *)curPtr, (void *)curPtr->next);
            curPtr = curPtr->next;
        }
    }
    printf("}\n");
    printf("\n");
}
