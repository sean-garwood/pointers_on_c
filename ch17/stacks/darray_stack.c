#ifndef _DARRAY_STACK_H
#include "darray_stack.h"
#endif

static STACK_TYPE *stacks[MAX_STACKS];      // array of stacks
static size_t stack_sizes[MAX_STACKS];      // size of the stack
static int top_elements[MAX_STACKS] = {-1}; // init value of index of the top element
static int stack_id = 0;                    // start at zero, increment for each new stack

/* allow for creation of up to 10 separate stacks */

/* create teh stack */
void create_stack(size_t size)
{
    assert(stack_sizes[stack_id] == 0);
    stacks[stack_id] = (STACK_TYPE *)malloc(size * sizeof(STACK_TYPE));
    stack_sizes[stack_id] = size;
    assert(stacks[stack_id] != NULL);
}

/* destroy the stack */
void destroy_stack(int stack_id)
{
    assert(!is_empty(stack_id));
    stack_sizes[stack_id] = 0;
    free(stacks[stack_id]);
    stacks[stack_id] = NULL;
}

void push(STACK_TYPE value, int stack_id)
{
    int top_element;
    STACK_TYPE *stack = stacks[stack_id];

    assert(!is_full(stack_id));
    top_element = ++top_elements[stack_id];
    stack[top_element] = value;
}

void pop(int stack_id)
{
    assert(!is_empty(stack_id));
    // pop the top element
    --top_elements[stack_id];
}

STACK_TYPE top(int stack_id)
{
    int top_element = top_elements[stack_id];
    STACK_TYPE *stack = stacks[stack_id];
    assert(!is_empty(stack_id));
    return stack[top_element];
}

int is_empty(int stack_id)
{
    assert(stack_id >= 0 && stack_id < MAX_STACKS && stack_sizes[stack_id] > 0);
    return top_elements[stack_id] == -1;
}

int is_full(int stack_id)
{
    assert(stack_id >= 0 && stack_id < MAX_STACKS && stack_sizes[stack_id] > 0);
    return top_elements[stack_id] == stack_sizes[stack_id] - 1;
}

/* 17.1 */
void resize_stack(size_t new_size, int stack_id)
{
    STACK_TYPE *new_stack = NULL;
    size_t stack_size = stack_sizes[stack_id];
    size_t size_diff; // difference between old and new stack sizes

    if (!(size_diff = new_size - stack_size))
        return;

    // Allocate new memory
    new_stack = (STACK_TYPE *)realloc(stacks[stack_id], new_size * sizeof(STACK_TYPE));
    if (new_stack == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    // Update stack pointer and size
    stacks[stack_id] = new_stack;
    stack_sizes[stack_id] = new_size;

    // Adjust top_element if necessary
    if (top_elements[stack_id] >= new_size)
        top_elements[stack_id] = new_size - 1;
}
