#include <stdio.h>
#include <stdlib.h>

#include "doublelinkedlist.h"

int main(void)
{
    printf("- %s, %d\n", __func__, __LINE__);

    printf("############# DoubleLinkedList #############\n");
    DoubleLinkedList l;
    node *n;
    doublelinkedlist_init(&l);
    doublelinkedlist_print(&l);

    printf("## ==> Initial test: Adding two elements and removing them.\n");
    doublelinkedlist_push_back(&l, '1');
    doublelinkedlist_print(&l);
    doublelinkedlist_push_back(&l, '2');
    doublelinkedlist_print(&l);
    doublelinkedlist_pop_front(&l);
    doublelinkedlist_print(&l);
    doublelinkedlist_pop_front(&l);
    doublelinkedlist_print(&l);

    printf("## ==> Testing push_back\n");
    doublelinkedlist_push_back(&l, 'A');
    doublelinkedlist_push_back(&l, 'B');
    doublelinkedlist_push_back(&l, 'C');
    doublelinkedlist_push_back(&l, 'D');
    doublelinkedlist_push_back(&l, 'E');
    doublelinkedlist_push_back(&l, 'F');
    doublelinkedlist_print(&l);

    printf("## ==> Testing at\n");
    printf("    Elem pos [0]: %c\n", *(doublelinkedlist_at(&l, 0)->value));
    printf("    Elem pos [1]: %c\n", *(doublelinkedlist_at(&l, 1)->value));
    printf("    Elem pos [2]: %c\n", *(doublelinkedlist_at(&l, 2)->value));
    printf("    Elem pos [3]: %c\n", *(doublelinkedlist_at(&l, 3)->value));
    printf("    Elem pos [4]: %c\n", *(doublelinkedlist_at(&l, 4)->value));
    printf("    Elem pos [5]: %c\n", *(doublelinkedlist_at(&l, 5)->value));

    printf("## ==> Testing find\n");
    printf("    Elem node 'A': %p\n", (void *)doublelinkedlist_find(&l, 'A'));
    printf("    Elem node 'B': %p\n", (void *)doublelinkedlist_find(&l, 'B'));
    printf("    Elem node 'C': %p\n", (void *)doublelinkedlist_find(&l, 'C'));
    printf("    Elem node 'D': %p\n", (void *)doublelinkedlist_find(&l, 'D'));
    printf("    Elem node 'E': %p\n", (void *)doublelinkedlist_find(&l, 'E'));
    printf("    Elem node 'F': %p\n", (void *)doublelinkedlist_find(&l, 'F'));
    printf("    Elem node 'Z': %p\n", (void *)doublelinkedlist_find(&l, 'Z'));

    printf("## ==> Testing insert_after & insert_after_object\n");
    n = doublelinkedlist_at(&l, 0);
    doublelinkedlist_insert_after(&l, n, '1');
    n = doublelinkedlist_at(&l, 2);
    doublelinkedlist_insert_after(&l, n, '2');
    n = doublelinkedlist_at(&l, 5);
    doublelinkedlist_insert_after(&l, n, '3');
    doublelinkedlist_insert_after_object(&l, 'E', '4');
    doublelinkedlist_insert_after_object(&l, 'F', '5');
    doublelinkedlist_print(&l);

    printf("## ==> Testing truncatate\n");
    doublelinkedlist_truncate(&l);
    doublelinkedlist_print(&l);

    printf("## ==> Testing push_front & insert\n");
    doublelinkedlist_push_front(&l, 'I');
    doublelinkedlist_push_front(&l, 'H');
    doublelinkedlist_push_front(&l, 'G');
    doublelinkedlist_push_front(&l, 'F');
    doublelinkedlist_push_front(&l, 'E');
    doublelinkedlist_push_front(&l, 'D');
    doublelinkedlist_push_front(&l, 'C');
    doublelinkedlist_push_front(&l, 'B');
    doublelinkedlist_push_front(&l, 'A');
    doublelinkedlist_insert(&l, 9, '?');
    doublelinkedlist_insert(&l, 0, '#');
    doublelinkedlist_insert(&l, 10000, '!'); // out of bounds, will do nothing
    doublelinkedlist_print(&l);

    printf("## ==> Testing remove, remove_object & remove_after\n");
    doublelinkedlist_remove_object(&l, '?');
    doublelinkedlist_remove_object(&l, '#');
    doublelinkedlist_print(&l);
    doublelinkedlist_remove(&l, (void *)doublelinkedlist_find(&l, 'A'));
    doublelinkedlist_remove(&l, (void *)doublelinkedlist_find(&l, 'B'));
    doublelinkedlist_remove_after(&l, (void *)doublelinkedlist_find(&l, 'C'));
    doublelinkedlist_remove(&l, (void *)doublelinkedlist_find(&l, 'H'));
    doublelinkedlist_remove(&l, (void *)doublelinkedlist_find(&l, 'I'));
    doublelinkedlist_remove_after(&l, l.head);
    doublelinkedlist_remove_after(&l, l.tail);
    doublelinkedlist_print(&l);

    printf("## ==> Testing pop_front, pop_back\n");
    doublelinkedlist_truncate(&l);
    int ansi_start = 97; // 65 = 'A' | 97 = 'a | 48 = '0'
    for (int i = ansi_start; i < 10 + ansi_start; ++i)
    {
        doublelinkedlist_push_back(&l, i);
    }
    doublelinkedlist_print(&l);
    printf("    Front: %c\n", doublelinkedlist_pop_front(&l));
    printf("    Front: %c\n", doublelinkedlist_pop_front(&l));
    printf("    Front: %c\n", doublelinkedlist_pop_front(&l));
    printf("    Back : %c\n", doublelinkedlist_pop_back(&l));
    printf("    Back : %c\n", doublelinkedlist_pop_back(&l));
    printf("    Back : %c\n", doublelinkedlist_pop_back(&l));
    doublelinkedlist_print(&l);
    
    doublelinkedlist_destroy(&l);

    return 0;
}
