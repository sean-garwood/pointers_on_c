#include "../12.h"

/*
 * Write a function
 */
Node *sll_reverse(register Node *root);
/*
 * that reverses a singly linked list. The function should return a pointer to
 * the new root node.
 *
 * Link field of the last node in the list will contain NULL.
 *
 * In event of empty list (root == NULL), the function should return NULL.
 */

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

Node *sll_reverse(register Node *root)
{
    Node *prev = NULL;
    Node *next;
    Node *curr = root;

    if (curr == NULL)
        return NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    int last_is_null_flag = prev->next == NULL ? 1 : 0;
    printf("last node point to null?: %d\n",
           last_is_null_flag ? prev->next->data : 1);
    return prev;
}

void print_sll(register Node *root)
{
    Node *current = root;
    while (current != NULL)
    {
        printf("%d\n", current->data);
        current = current->next;
    }
    printf("\n");
}

void free_sll(register Node *root)
{
    Node *next;
    while (root != NULL)
    {
        next = root->next;
        free(root);
        root = next;
    }
}
