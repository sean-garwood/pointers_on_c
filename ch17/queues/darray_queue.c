#ifndef DARRAY_QUEUE_H
#include "darray_queue.h"
#endif

static Q_T *queue;
static size_t queue_size;
static size_t members;
static size_t front;
static size_t rear;

void insert(Q_T value)
{
    if (is_full())
        resize_queue(members + 1);

    queue[rear] = value;
    rear = (rear + 1) % queue_size;
    members++;
}

void delete(void)
{
    assert(!is_empty());
    front = (front + 1) % queue_size;
}

Q_T first(void)
{
    assert(!is_empty());
    return queue[front];
}

int is_empty(void)
{
    return members == 0;
}

int is_full(void)
{
    return members == queue_size;
}

void create_queue(size_t size)
{
    queue = (Q_T *)malloc(size * sizeof(Q_T));
    if (queue == NULL)
    {
        fprintf(stderr, "create_queue: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    members = front = rear = 0;
}

void destroy_darray_queue(void)
{
    free(queue);
}

void resize_queue(size_t new_size)
{
    Q_T *new_queue;
    if (new_size < members)
    {
        fprintf(stderr, "resize_queue: new_size is too small\n");
        exit(EXIT_FAILURE);
    }

    if ((new_queue = (Q_T *)malloc(new_size * sizeof(Q_T))) == NULL)
    {
        fprintf(stderr, "resize_queue: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    for (size_t i = 0; i < members; i++)
    {
        new_queue[i] = queue[(front + i) % queue_size];
    }
    free(queue);
    queue = new_queue;
    queue_size = new_size;
    front = 0;
    rear = members;
}
