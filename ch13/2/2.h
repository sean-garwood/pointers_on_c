#include <stdlib.h>
#include <stdio.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

void callback(Node *node);
void *traverse(Node *head, void (*callback)(Node *));
