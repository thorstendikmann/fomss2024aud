#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"

int main(void)
{
    printf("- %s, %d\n", __func__, __LINE__);

    printf("############# LinkedList #############\n");
    LinkedList l;
    node *n;
    linkedlist_init(&l);
    linkedlist_print(&l);

    n = l.head;
    n = linkedlist_insert_after(&l, n, '1');
    n = linkedlist_insert_after(&l, n, '2');
    n = linkedlist_insert_after(&l, n, '3');
    n = linkedlist_insert_after(&l, n, '4');
    n = linkedlist_insert_after(&l, n, '5');
    linkedlist_print(&l);

    printf("List size: %zu\n", linkedlist_size(&l));

    n = l.head;
    linkedlist_remove_after(&l, n);
    linkedlist_remove_after(&l, n);
    linkedlist_remove_after(&l, n);

    linkedlist_print(&l);
    linkedlist_destroy(&l);

    return 0;
}
