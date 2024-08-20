/* interface for a queue module */
#ifndef QUEUE_H
#define QUEUE_H

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#define FALSE 0
#define Q_T int // queue type

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
