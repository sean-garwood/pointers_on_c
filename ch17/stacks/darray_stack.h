#ifndef _DARRAY_STACK_H
#define _DARRAY_STACK_H

#ifndef _STACK_H
#include "stack.h"
#endif

#define MAX_STACKS 10

/* create the stack. argument specifies number of elements */
/* does not apply to static array implementation. */
void create_stack(size_t size);

/* destroy the stack, free memory.  */
/* does not apply to static array implementation. */
void destroy_stack(void);

/* 17.1 */
void resize_stack(size_t new_size);
#endif // _DARRAY_STACK_H
