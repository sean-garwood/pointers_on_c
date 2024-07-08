#include "../12.h"

int dll_remove(DNode *rootp, DNode *node)
{
    DNode *curr;
    DNode *linkp = rootp;
    while ((curr = linkp) != NULL && curr->next != node)
        linkp = curr->next;

    // now we're standing on the node before the desired node, or we've reached the end of the list

    if (curr == NULL)
    {
        printf("Node not found\n");
        return FALSE;
    }
    else if (curr == rootp)
    {
        // we're removing the first node
        linkp = curr->next;
        if (linkp != NULL)
            linkp->prev = NULL;
    }
    else
    {
        // we're removing a node that's not the first
        linkp->next = curr->next->next;
        if (linkp->next != NULL)
            linkp->next->prev = linkp;
    }
    return TRUE;
}

void print_dll(register DNode *root)
{
    DNode *current = root;
    while (current != NULL)
    {
        printf("%d\n", current->data);
        current = current->next;
    }
    printf("\n");
}
