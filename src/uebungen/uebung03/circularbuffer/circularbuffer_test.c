#include <stdio.h>
#include <stdlib.h>

#include "circularbuffer.h"

int main(void)
{
    printf("- %s, %d\n", __func__, __LINE__);

    CircularBuffer c;
    int MAX_SIZE = 10;
    char *ch;

    circular_buffer_init(&c, MAX_SIZE);
    circular_buffer_print(&c);

    circular_buffer_push_back(&c, 'A');
    circular_buffer_print(&c);
    circular_buffer_push_back(&c, 'B');
    circular_buffer_print(&c);
    circular_buffer_push_back(&c, 'C');
    circular_buffer_print(&c);
    circular_buffer_push_back(&c, 'D');
    circular_buffer_print(&c);
    circular_buffer_push_back(&c, 'E');
    circular_buffer_print(&c);
    circular_buffer_push_back(&c, 'F');
    circular_buffer_print(&c);
    circular_buffer_push_back(&c, 'G');
    circular_buffer_print(&c);
    circular_buffer_push_back(&c, 'H');
    circular_buffer_print(&c);
    
    printf("pop front [%c]\n", circular_buffer_pop_front(&c));
    printf("pop front [%c]\n", circular_buffer_pop_front(&c));
    printf("pop back  [%c]\n", circular_buffer_pop_back(&c));
    circular_buffer_print(&c);
    
    printf("Pushing additional chars.\n");
    int ansi_start = 97; // 65 = 'A' | 97 = 'a | 48 = '0'
    for (int i = ansi_start; i < MAX_SIZE + ansi_start; ++i)
    {
        circular_buffer_push_back(&c, i);
        circular_buffer_print(&c);
    }
    circular_buffer_print(&c);

    printf("pop front [%c]\n", circular_buffer_pop_front(&c));
    circular_buffer_print(&c);
    printf("pop front [%c]\n", circular_buffer_pop_front(&c));
    circular_buffer_print(&c);
    printf("pop back  [%c]\n", circular_buffer_pop_back(&c));
    circular_buffer_print(&c);
    printf("pop back  [%c]\n", circular_buffer_pop_back(&c));
    
    printf("\n");
    printf("Pushing additional chars.\n");
    circular_buffer_push_back(&c, 'X');
    circular_buffer_print(&c);
    circular_buffer_push_back(&c, 'Y');
    circular_buffer_print(&c);
    circular_buffer_push_back(&c, 'Z');
    circular_buffer_print(&c);

    printf("\n");
    printf("Modifying chars.\n");
    ch = circular_buffer_at(&c, 0);
    printf("ch  [%c]\n", *ch);
    *ch = '#';
    circular_buffer_print(&c);
    ch = circular_buffer_at(&c, 1);
    printf("ch  [%c]\n", *ch);
    *ch = '%';
    circular_buffer_print(&c);
    ch = circular_buffer_at(&c, 4);
    printf("ch  [%c]\n", *ch);
    *ch = '+';
    circular_buffer_print(&c);
    ch = circular_buffer_at(&c, (c.size)-1);
    printf("ch  [%c]\n", *ch);
    *ch = '?';
    circular_buffer_print(&c);
    ch = circular_buffer_at(&c, (c.size)-2);
    printf("ch  [%c]\n", *ch);
    *ch = '!';
    circular_buffer_print(&c);

    printf("\n");
    printf("pop front [%c]\n", circular_buffer_pop_front(&c));
    circular_buffer_print(&c);
    printf("pop front [%c]\n", circular_buffer_pop_front(&c));
    circular_buffer_print(&c);
    printf("pop back  [%c]\n", circular_buffer_pop_back(&c));
    circular_buffer_print(&c);
    printf("pop back  [%c]\n", circular_buffer_pop_back(&c));
    circular_buffer_print(&c);
    printf("pop back  [%c]\n", circular_buffer_pop_back(&c));
    circular_buffer_print(&c);
    printf("pop back  [%c]\n", circular_buffer_pop_back(&c));
    circular_buffer_print(&c);
    printf("pop back  [%c]\n", circular_buffer_pop_back(&c));
    circular_buffer_print(&c);
    printf("pop back  [%c]\n", circular_buffer_pop_back(&c));
    circular_buffer_print(&c);
    printf("pop back  [%c]\n", circular_buffer_pop_back(&c));
    circular_buffer_print(&c);
    printf("pop back  [%c]\n", circular_buffer_pop_back(&c));
    circular_buffer_print(&c);
    printf("pop back  [%c]\n", circular_buffer_pop_back(&c));
    circular_buffer_print(&c);

    circular_buffer_push_back(&c, 'F');
    circular_buffer_print(&c);
    circular_buffer_push_back(&c, 'O');
    circular_buffer_print(&c);
    circular_buffer_push_back(&c, 'M');
    circular_buffer_print(&c);
    printf("pop front [%c]\n", circular_buffer_pop_front(&c));
    circular_buffer_print(&c);
    printf("pop front [%c]\n", circular_buffer_pop_front(&c));
    circular_buffer_print(&c);
    printf("pop front [%c]\n", circular_buffer_pop_front(&c));
    circular_buffer_print(&c);
    printf("pop front [%c]\n", circular_buffer_pop_front(&c));
    circular_buffer_print(&c);
    
    circular_buffer_destroy(&c);

    return 0;
}
