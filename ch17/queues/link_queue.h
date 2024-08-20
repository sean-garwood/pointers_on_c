/*
 * 17.3: convert the queue module to use linked list allocation.
 */
#ifndef LINK_QUEUE_H
#define LINK_QUEUE_H

#ifndef QUEUE_H
#include "queue.h"
#endif

typedef struct node
{
    Q_T value;
    struct node *next;
} Node;

typedef struct
{
    Node *head;
    Node *tail;
} LinkQueue;

/* Destroy a linked queue */
void destroy_link_queue(void);

#endif // LINK_QUEUE_H
