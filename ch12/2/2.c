#include "../12.h"
Node *find_value(register Node *node, int value)
{
    while (node != NULL && node->data != value)
        node = node->next;
    return node;
}
