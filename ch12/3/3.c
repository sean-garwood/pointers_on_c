#include "../12.h"

int dll_insert(register DNode *rootp, int value)
{
    /*
     * insert a value into a doubly linked list.

     rootp is a pointer to the root node
     value is the new value to insert

     returns 0 if value already in list
     returns 1 if new node inserted
     returns FAIL if memory allocation failed
     */
    register DNode *curr;
    register DNode *next;
    register DNode *new;

    /*
     * see if the value is already in the list.
     otherwise, allocate a new node for the value, which new will point to.

     curr will point to the node that the new value should follow.

     next will point to the one after it.
     */

    for (curr = rootp; (next = curr->next) != NULL; curr = next)
    {
        if (next->data == value)
            return FALSE;

        if (next->data > value)
            break;
    }
    new = (DNode *)malloc(sizeof(DNode));
    if (new == NULL)
        return FAIL;

    new->data = value;
    new->next = next;
    curr->next = new;
    (curr != rootp) ? (new->prev = curr) : (new->prev = NULL);
    (next != NULL) ? (next->prev = new) : (rootp->prev = new);
    return TRUE;
}

int rewrite_dll_insert(register DNode *head, register DNode *tail, int value)
{
    /* four possibilities:
     * 1. empty list
     * 2. lowest value in list
     * 3. highest value in list
     * 4. somewhere in the middle
     */

    register DNode *curr;
    register DNode *next;
    register DNode *new;

    for (curr = head; (next = curr->next) != tail; curr = next)
    {
        if (next->data == value)
            return FALSE;

        if (next->data > value)
            break;
    }

    // now we're either at the right spot or at the end of the list
    if (curr == head)
    {
        // empty list or lowest value in list
        new = (DNode *)malloc(sizeof(DNode));
        if (new == NULL)
            return FAIL;

        new->data = value;
        new->next = tail;
        new->prev = head;
        head->next = new;
        tail->prev = new;
    }
    else if (next == tail && tail->data != value)
    {
        // highest value in list
        new = (DNode *)malloc(sizeof(DNode));
        if (new == NULL)
            return FAIL;

        new->data = value;
        new->next = tail;
        new->prev = curr;
        curr->next = new;
        tail->prev = new;
    }
    else
    {
        // somewhere in the middle
        new = (DNode *)malloc(sizeof(DNode));
        if (new == NULL)
            return FAIL;

        new->data = value;
        new->next = next;
        new->prev = curr;
        curr->next = new;
        next->prev = new;
    }
    return TRUE;
}
