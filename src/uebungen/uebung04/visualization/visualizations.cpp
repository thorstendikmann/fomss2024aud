#include <iostream>
#include <string>

extern "C"
{
#include "array/array.h"
#include "linkedlist/linkedlist.h"
}

#include "queue/queue.h"
#include "stack/stack.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"
#endif

int main()
{
    std::cout << "###############################################################" << std::endl;
    std::cout << "######## Array " << std::endl;
    std::cout << std::endl;
    {
        Array a;
        array_init(&a, 6);
        array_print_graphviz(&a);
        array_push_back(&a, 'A');
        array_print_graphviz(&a);
        array_push_back(&a, 'B');
        array_print_graphviz(&a);
        array_insert(&a, 0, 'X');
        array_print_graphviz(&a);
        array_insert(&a, 2, 'C');
        array_print_graphviz(&a);
        array_remove(&a, 1);
        array_print_graphviz(&a);
        array_destroy(&a);
    }

    std::cout << "###############################################################" << std::endl;
    std::cout << "######## LinkedList " << std::endl;
    std::cout << std::endl;
    {
        LinkedList l;
        linkedlist_init(&l);
        linkedlist_print_graphviz(&l);
        node *A = linkedlist_push_back(&l, 'A');
        linkedlist_print_graphviz(&l);
        node *B = linkedlist_push_back(&l, 'B');
        linkedlist_print_graphviz(&l);
        node *C = linkedlist_push_back(&l, 'C');
        linkedlist_print_graphviz(&l);
        linkedlist_insert_after(&l, B, 'X');
        linkedlist_print_graphviz(&l);
        linkedlist_insert_after(&l, l.head, 'Y');
        linkedlist_print_graphviz(&l);
        linkedlist_destroy(&l);
    }

    std::cout << "###############################################################" << std::endl;
    std::cout << "######## Stack " << std::endl;
    std::cout << std::endl;
    {
        fom::AuD::Stack s;
        s.push('A');
        std::cout << s.toGraphviz() << std::endl;
        s.push('B');
        std::cout << s.toGraphviz() << std::endl;
        s.push('C');
        std::cout << s.toGraphviz() << std::endl;
        s.pop();
        std::cout << s.toGraphviz() << std::endl;
        s.push('M');
        std::cout << s.toGraphviz() << std::endl;
        s.push('N');
        std::cout << s.toGraphviz() << std::endl;
        s.pop();
        std::cout << s.toGraphviz() << std::endl;
        s.push('O');
        std::cout << s.toGraphviz() << std::endl;
    }

    std::cout << "###############################################################" << std::endl;
    std::cout << "######## Queue " << std::endl;
    std::cout << std::endl;
    {
        fom::AuD::Queue s;
        s.enqueue('A');
        std::cout << s.toGraphviz() << std::endl;
        s.enqueue('B');
        std::cout << s.toGraphviz() << std::endl;
        s.enqueue('C');
        std::cout << s.toGraphviz() << std::endl;
        s.dequeue();
        std::cout << s.toGraphviz() << std::endl;
        s.enqueue('M');
        std::cout << s.toGraphviz() << std::endl;
        s.enqueue('N');
        std::cout << s.toGraphviz() << std::endl;
        s.dequeue();
        std::cout << s.toGraphviz() << std::endl;
        s.enqueue('O');
        std::cout << s.toGraphviz() << std::endl;
    }

    return 0;
}

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic pop
#endif
