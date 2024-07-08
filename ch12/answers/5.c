#include "../12.h"

/*
 * write a fn
 */

int sll_remove(Node **rootp, Node *node);
/*
 * that removes a node from a singly linked list. The function should return
 * FALSE if the node was not found in the list, TRUE otherwise.
 *
 * Is there any advantage in taking a pointer to the node to remove as opposed
 * to taking the value?
 */

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
