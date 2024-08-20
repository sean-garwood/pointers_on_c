/*
 * 17.2 ANSWER
 */

#ifndef DARRAY_QUEUE_H
#define DARRAY_QUEUE_H

#ifndef QUEUE_H
#include "queue.h"
#endif

static Q_T *queue;

/* create a queue */
void create_queue(size_t size); // only applies to Dnamic array implementation

/* destroy a queue */
void destroy_darray_queue(void);

/* resize the queue to the given new_size */
void resize_queue(size_t new_size); // only applies to darray implementation

#endif
