/*
 * a stack implemented with a static array. The array size can be adjusted only
 * by changing the #define statement below and recompiling the module. this is
 * by design.
 */

#ifndef _STACK_H
#include "stack.h"
#endif
#ifndef _SARRAY_STACK_H
#include "sarray_stack.h"
#endif

static STACK_TYPE stack[STACK_SIZE]; // holds values on stack
static int top_element = -1;         // index of the top element

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
    return top_element == -1;
}

int is_full(void)
{
    return top_element == STACK_SIZE - 1;
}

// stubs

void create_stack(void)
{
    // do nothing
}

void destroy_stack(void)
{
    // do nothing
}
