/*
 * 17.11 prompt:
 * rewrite ../ex/stack/g_stack.h as three separate defines:
 *
 * declare stack interface
 * create stack implementation
 * create data for stack
 *
 * must change the interface for the stack to pass the stack data as an arg
 *      it will be more convenient to package the stack data into a struct.
 *
 *
 * These mods will let a single set of stack functions manipulate any stack of
 * the corresponding type.
 *
 */

#ifndef STACK_H
#define STACK_H

#include <assert.h>
#include <stdlib.h>

#define STACK_INTERFACE(STACK_TYPE, SUFFIX)                    \
    typedef struct                                             \
    {                                                          \
        STACK_TYPE *stack;                                     \
        int top_element;                                       \
    } Stack##SUFFIX;                                           \
                                                               \
    void pop##SUFFIX(Stack##SUFFIX *stack);                    \
    STACK_TYPE top##SUFFIX(Stack##SUFFIX *stack);              \
    void push##SUFFIX(Stack##SUFFIX *stack, STACK_TYPE value); \
    int is_empty##SUFFIX(Stack##SUFFIX *stack);                \
    int is_full##SUFFIX(Stack##SUFFIX *stack)

#define STACK_IMPLEMENTATION(STACK_TYPE, SUFFIX)     \
                                                     \
    void pop##SUFFIX(Stack##SUFFIX *stack)           \
    {                                                \
        assert(!is_empty##SUFFIX(stack));            \
        --stack->top_element;                        \
    }                                                \
                                                     \
    STACK_TYPE top##SUFFIX(Stack##SUFFIX *stack)     \
    {                                                \
        assert(!is_empty##SUFFIX(stack));            \
        return stack->stack[stack->top_element];     \
    }                                                \
                                                     \
    int is_empty##SUFFIX(Stack##SUFFIX *stack)       \
    {                                                \
        return stack->top_element == -1;             \
    }                                                \
    int is_full##SUFFIX(Stack##SUFFIX *stack)        \
    {                                                \
        return stack->top_element == STACK_SIZE - 1; \
    }

#define STACK_DATA(STACK_TYPE, SUFFIX) \
    STACK_TYPE stack##SUFFIX;          \
    int top_element##SUFFIX = -1;

#endif // _G_STACK_H
