#ifndef LINK_QUEUE_H
#include "link_queue.h"
#endif

static LinkQueue *queue = NULL;

void insert(Q_T value)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: memory allocation failed\n");
        exit(1);
    }

    new_node->value = value;
    new_node->next = NULL;
    // check if the queue is empty
    if (queue->head == NULL)
        queue->head = queue->tail = new_node;
    else
    {
        queue->tail->next = new_node;
        queue->tail = new_node;
    }
}

void delete(void)
{
    assert(!is_empty());
    Node *temp = queue->head;
    queue->head = queue->head->next;
    free(temp);
}

Q_T first(void)
{
    assert(!is_empty());
    return queue->head->value;
}

int is_empty(void)
{
    return queue->head == NULL;
}

int is_full(void)
{
    return FALSE;
}

void destroy_link_queue(void)
{
    while (!is_empty())
        delete ();

    free(queue);
    queue = NULL;
}
