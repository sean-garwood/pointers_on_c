/* interface for a queue module */
#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>

#define FALSE 0
#define Q_T int // queue type

/* create a queue */
void create_queue(size_t size); // only applies to Dnamic array implementation
void destroy_queue(void);       // applies to d- and l- implementations

/* add new value in the queue*/
void insert(Q_T value);

/* delete a value from the queue */
void delete(void);
/*
 * in traditional interface:
 *     `delete` removes the value of the que and returns it.
 *     alternately, it takes the value out of the queue and does not return it.
 */

/* return the value at the front of the queue without removing it */
Q_T first(void);

/* predicates */
int is_empty(void);
int is_full(void);

#endif // QUEUE_H
