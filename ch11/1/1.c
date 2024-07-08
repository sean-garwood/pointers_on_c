/*
 * Write your own version of the `calloc` function, using `malloc` to obtain memory.
 */

#include "../11.h"

void *my_calloc(size_t n, size_t size)
{
    void *p = malloc(n * size);
    if (p == NULL)
        return NULL;

    // main difference between calloc and malloc is that calloc initializes the memory to 0
    for (size_t i = 0; i < n * size; i++)
        *((char *)p + i) = 0;
    return p;
}
