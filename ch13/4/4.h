#include <stdlib.h>

int compare(void *a, void *b);
void exchange_sort(void *element, int num_elements, int size_of_element,
                   int (*compare)(void *, void *));
