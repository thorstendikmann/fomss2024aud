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

    printf("## ==> Initial test: Adding two elements and removing them.\n");
    linkedlist_push_back(&l, '1');
    linkedlist_print(&l);
    linkedlist_push_back(&l, '2');
    linkedlist_print(&l);
    linkedlist_pop_front(&l);
    linkedlist_print(&l);
    linkedlist_pop_front(&l);
    linkedlist_print(&l);

    printf("## ==> Testing push_back\n");
    linkedlist_push_back(&l, 'A');
    linkedlist_push_back(&l, 'B');
    linkedlist_push_back(&l, 'C');
    linkedlist_push_back(&l, 'D');
    linkedlist_push_back(&l, 'E');
    linkedlist_push_back(&l, 'F');
    linkedlist_print(&l);

    printf("## ==> Testing at\n");
    printf("    Elem pos [0]: %c\n", *(linkedlist_at(&l, 0)->value));
    printf("    Elem pos [1]: %c\n", *(linkedlist_at(&l, 1)->value));
    printf("    Elem pos [2]: %c\n", *(linkedlist_at(&l, 2)->value));
    printf("    Elem pos [3]: %c\n", *(linkedlist_at(&l, 3)->value));
    printf("    Elem pos [4]: %c\n", *(linkedlist_at(&l, 4)->value));
    printf("    Elem pos [5]: %c\n", *(linkedlist_at(&l, 5)->value));

    printf("## ==> Testing find\n");
    printf("    Elem node 'A': %p\n", (void *)linkedlist_find(&l, 'A'));
    printf("    Elem node 'B': %p\n", (void *)linkedlist_find(&l, 'B'));
    printf("    Elem node 'C': %p\n", (void *)linkedlist_find(&l, 'C'));
    printf("    Elem node 'D': %p\n", (void *)linkedlist_find(&l, 'D'));
    printf("    Elem node 'E': %p\n", (void *)linkedlist_find(&l, 'E'));
    printf("    Elem node 'F': %p\n", (void *)linkedlist_find(&l, 'F'));
    printf("    Elem node 'Z': %p\n", (void *)linkedlist_find(&l, 'Z'));

    printf("## ==> Testing insert_after & insert_after_object\n");
    n = linkedlist_at(&l, 0);
    linkedlist_insert_after(&l, n, '1');
    n = linkedlist_at(&l, 2);
    linkedlist_insert_after(&l, n, '2');
    n = linkedlist_at(&l, 5);
    linkedlist_insert_after(&l, n, '3');
    linkedlist_insert_after_object(&l, 'E', '4');
    linkedlist_insert_after_object(&l, 'F', '5');
    linkedlist_print(&l);

    printf("## ==> Testing truncatate\n");
    linkedlist_truncate(&l);
    linkedlist_print(&l);

    printf("## ==> Testing push_front & insert\n");
    linkedlist_push_front(&l, 'I');
    linkedlist_push_front(&l, 'H');
    linkedlist_push_front(&l, 'G');
    linkedlist_push_front(&l, 'F');
    linkedlist_push_front(&l, 'E');
    linkedlist_push_front(&l, 'D');
    linkedlist_push_front(&l, 'C');
    linkedlist_push_front(&l, 'B');
    linkedlist_push_front(&l, 'A');
    linkedlist_insert(&l, 9, '?');
    linkedlist_insert(&l, 0, '#');
    linkedlist_insert(&l, 10000, '!'); // out of bounds, will do nothing
    linkedlist_print(&l);

    printf("## ==> Testing remove, remove_object & remove_after\n");
    linkedlist_remove_object(&l, '?');
    linkedlist_remove_object(&l, '#');
    linkedlist_print(&l);
    linkedlist_remove(&l, (void *)linkedlist_find(&l, 'A'));
    linkedlist_remove(&l, (void *)linkedlist_find(&l, 'B'));
    linkedlist_remove_after(&l, (void *)linkedlist_find(&l, 'C'));
    linkedlist_remove(&l, (void *)linkedlist_find(&l, 'H'));
    linkedlist_remove(&l, (void *)linkedlist_find(&l, 'I'));
    linkedlist_remove_after(&l, l.head);
    linkedlist_remove_after(&l, l.tail);
    linkedlist_print(&l);

    printf("## ==> Testing pop_front, pop_back\n");
    linkedlist_truncate(&l);
    int ansi_start = 97; // 65 = 'A' | 97 = 'a | 48 = '0'
    for (int i = ansi_start; i < 10 + ansi_start; ++i)
    {
        linkedlist_push_back(&l, i);
    }
    linkedlist_print(&l);
    printf("    Front: %c\n", linkedlist_pop_front(&l));
    printf("    Front: %c\n", linkedlist_pop_front(&l));
    printf("    Front: %c\n", linkedlist_pop_front(&l));
    printf("    Back : %c\n", linkedlist_pop_back(&l));
    printf("    Back : %c\n", linkedlist_pop_back(&l));
    printf("    Back : %c\n", linkedlist_pop_back(&l));
    linkedlist_print(&l);
    
    linkedlist_destroy(&l);

    return 0;
}
