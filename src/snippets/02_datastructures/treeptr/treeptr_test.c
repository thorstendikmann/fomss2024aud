#include <stdio.h>
#include <stdlib.h>

#include "treeptr.h"

int main(void)
{
    printf("- %s, %d\n", __func__, __LINE__);

    TreePtr t;
    tree_initialize(&t);

    // TODO --- test it!!

    tree_destroy(&t);

    return 0;
}
