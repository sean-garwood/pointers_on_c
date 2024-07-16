/*
 * write a function to traverse a singly linked list
 *
 * It takes two args:
 *
 *  1. a pointer to the head of the list
 *  2. pointer to callback fn
 *     a. takes a single arg: pointer to a list node
 *     b. invoked once per node in the list.
 *
 * what does the fn need to know about the nodes in the list?
 *
 * not sure which function this is referring to. Traverse just needs to check
 * whether the current node is NULL or not. The callback function needs to know
 * ... nothing? It's just a function that takes a Node pointer as an argument,
 * prints its address and data.
 */

#include "2.h"

void *traverse(Node *head, void (*callback)(Node *))
{
    Node *current = head;
    while (current != NULL)
    {
        callback(current);
        current = current->next;
    }
    return head;
}

void callback(Node *node)
{
    printf("This is a callback fn\nnode address: %p\n", (void *)node);
    printf("node data: %d\n", node->data);
}

int main(void)
{
    Node *head = malloc(sizeof(Node));
    head->data = 1;
    head->next = malloc(sizeof(Node));
    head->next->data = 2;
    head->next->next = malloc(sizeof(Node));
    head->next->next->data = 3;

    traverse(head, callback);

    free(head->next->next);
    free(head->next);
    free(head);
    return 0;
}
