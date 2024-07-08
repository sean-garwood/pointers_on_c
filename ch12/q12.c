#include "12.h"

/* insert into singly-ordered linked list.
 * args are pointer to the first node in the list and value to insert.*/
int sll_insert(register Node **linkp, int new_value)
{
    register Node *current;
    register Node *new;

    while ((current = *linkp) != NULL && current->data < new_value)
        linkp = &current->next;

    new = (Node *)malloc(sizeof(Node));
    if (new == NULL)
        return FALSE;

    new->data = new_value;
    new->next = current;
    *linkp = new;

    return TRUE;
}

int alloc_first_then_insert(register Node **linkp, int new_value)
{
    register Node *current;
    register Node *new;
    new = (Node *)malloc(sizeof(Node));

    while ((current = *linkp) != NULL && current->data < new_value)
        linkp = &current->next;

    if (new == NULL)
        return FALSE;

    new->data = new_value;
    new->next = current;
    *linkp = new;

    return TRUE;
}

int rewritten_sll_insert(register Node **linkp, int new_value)
{
    register Node *new;

    while (*linkp != NULL && (*linkp)->data < new_value)
        linkp = &(*linkp)->next;

    new = (Node *)malloc(sizeof(Node));
    if (new == NULL)
        return FALSE;

    new->data = new_value;
    new->next = *linkp;
    *linkp = new;

    return TRUE;
}
