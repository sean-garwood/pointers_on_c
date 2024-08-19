/*
 * a queue implemented with a static array. it uses the 'dont completely fill
 * the array' approach.
 *
 * The array size can be adjusted only by changing the value of the the
 * #define'd statement and recomipliing the program.
 *
 */

#include "aqueue.h"

static Q_T queue[ARRAY_SIZE];
static size_t front = 1;
static size_t rear = 0;

void insert(Q_T value)
{
    assert(!is_full());
    rear = (rear + 1) % ARRAY_SIZE;
    queue[rear] = value;
}

void delete(void)
{
    assert(!is_empty());
    front = (front + 1) % ARRAY_SIZE;
}

Q_T first(void)
{
    assert(!is_empty());
    return queue[front];
}

int is_empty(void)
{
    return (rear + 1) % ARRAY_SIZE == front;
}

int is_full(void)
{
    return (rear + 2) % ARRAY_SIZE == front;
}
