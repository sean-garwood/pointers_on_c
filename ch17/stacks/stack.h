/*
 * interface for a generic stack
 */

#ifndef _STACK_H
#define _STACK_H

#define STACK_TYPE int

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

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
