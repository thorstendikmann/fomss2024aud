#include <stdio.h>
#include <stdlib.h>

#include "circularbuffer.h"

int main(void)
{
    printf("- %s, %d\n", __func__, __LINE__);

    CircularBuffer c;
    int MAX_SIZE = 10;
    circular_buffer_init(&c, MAX_SIZE);

    // ...

    circular_buffer_print(&c);
    circular_buffer_destroy(&c);

    return 0;
}
