#ifndef _DARRAY_STACK_H
#include "darray_stack.h"
#endif

#ifndef _STACK_H
#include "stack.h"
#endif

static STACK_TYPE *stack;    // holds values on stack
static size_t stack_size;    // size of the stack
static int top_element = -1; // index of the top element

/* create teh stack */
void create_stack(size_t size)
{
    assert(stack_size == 0);
    stack = (STACK_TYPE *)malloc(size * sizeof(STACK_TYPE));
    stack_size = size;
    assert(stack != NULL);
}

/* destroy the stack */
void destroy_stack(void)
{
    assert(stack_size > 0);
    stack_size = 0;
    free(stack);
    stack = NULL;
}

void push(STACK_TYPE value)
{
    assert(!is_full());
    top_element += 1;
    stack[top_element] = value;
}

void pop(void)
{
    assert(!is_empty());
    top_element -= 1;
}

STACK_TYPE top(void)
{
    assert(!is_empty());
    return stack[top_element];
}

int is_empty(void)
{
    assert(stack_size > 0);
    return top_element == -1;
}

int is_full(void)
{
    assert(stack_size > 0);
    return top_element == stack_size - 1;
}
