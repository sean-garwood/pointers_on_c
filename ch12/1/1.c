#include "../12.h"

int sll_count(register Node *node)
{
    int i = 0;
    while (node != NULL)
    {
        i++;
        node = node->next;
    }
    return i;
}
