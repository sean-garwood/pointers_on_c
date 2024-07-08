#include "../12.h"

Node *find_value(register Node *node, int value)
{
    while (node != NULL && node->data != value)
        node = node->next;
    return node;
    // no changes needed to make this work on an ordered list.
}
