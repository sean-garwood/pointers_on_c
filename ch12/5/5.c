#include "../12.h"

int sll_remove(Node **rootp, Node *node)
{
    Node *current;
    while ((current = *rootp) != NULL && current != node)
        rootp = &current->next;

    if (current == NULL)
    {
        printf("Node not found\n");
        return FALSE;
    }

    *rootp = current->next;
    printf("Node removed\n * value: %d\n", node->data);
    free(current);

    return TRUE;
}
