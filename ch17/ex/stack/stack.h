/*
 * interface for a generic stack
 */

#ifndef _STACK_H
#define _STACK_H

#define STACK_TYPE int
#define STACK_SIZE 100 // max stack size

#include <assert.h>
#include <stdlib.h>

/* pushes a new value on the stack */
void push(STACK_TYPE value);

/* pops a value from the stack */
void pop(void);

/* returns the top value from the stack */
STACK_TYPE top(void);

/* returns true if the stack is empty */
int is_empty(void);

/* returns true if the stack is full */
int is_full(void);

#endif // _STACK_H
