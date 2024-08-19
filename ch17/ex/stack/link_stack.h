/*
 * a linked list stack. no size limit.
 */
#ifndef _LINK_STACK_H
#define _LINK_STACK_H

#ifndef _STACK_H
#include "stack.h"
#endif

#include <stdio.h>
#include <malloc.h>

#define FALSE 0

/* a struct to hold one value. the `next` member will point to the next value on
the stack. */
typedef struct STACK_NODE
{
    STACK_TYPE value;
    struct STACK_NODE *next;
} StackNode;

static StackNode *stack; // the top of the stack

/* create stack */
void create_stack(size_t size)
{
    // stub-- not needed in this implementation
}

/* destroy stack */
void destroy_stack(void)
{
    while (!is_empty())
        pop();
}

/* push a value on the stack */
void push(STACK_TYPE value)
{
    StackNode *new_node = (StackNode *)malloc(sizeof(StackNode));
    assert(new_node != NULL);

    new_node->value = value;
    new_node->next = stack;
    stack = new_node;
}

void pop(void)
{
    StackNode *first_node;

    assert(!is_empty());
    first_node = stack;
    stack = first_node->next;
    free(first_node);
}

STACK_TYPE top(void)
{
    assert(!is_empty());
    return stack->value;
}

int is_empty(void)
{
    return stack == NULL;
}

int is_full(void)
{
    return FALSE; // never full
}
#endif // _LINK_STACK_H
