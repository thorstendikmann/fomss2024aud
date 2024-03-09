#include <stdio.h>
#include <stdlib.h>

#include "circularbuffer.h"

int main(void)
{
    printf("- %s, %d\n", __func__, __LINE__);

    CircularBuffer c;

    // ...

    circular_buffer_print(&c);

    return 0;
}
