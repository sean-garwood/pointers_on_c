/*
 * generic implementation of a stack with a static array.
 *
 * Array size is given as one of the arguments when stack is instantiated.
 */

#ifndef _G_STACK_H
#define _G_STACK_H

#define GENERIC_STACK(STACK_T, SUFFIX, STACK_SIZE)                              \
    static STACK_T stack##SUFFIX[STACK_SIZE];                                   \
    static int top_element##SUFFIX = -1;                                        \
                                                                                \
    int is_empty##SUFFIX(void) { return top_element##SUFFIX == -1; }            \
    int is_full##SUFFIX(void) { return top_element##SUFFIX == STACK_SIZE - 1; } \
                                                                                \
    void push##SUFFIX(STACK_T value)                                            \
    {                                                                           \
        assert(!is_full##SUFFIX());                                             \
        stack##SUFFIX[++top_element##SUFFIX] = value;                           \
    }                                                                           \
                                                                                \
    void pop##SUFFIX(void)                                                      \
    {                                                                           \
        assert(!is_empty##SUFFIX());                                            \
        --top_element##SUFFIX;                                                  \
    }                                                                           \
                                                                                \
    STACK_T top##SUFFIX(void)                                                   \
    {                                                                           \
        assert(!is_empty##SUFFIX());                                            \
        return stack##SUFFIX[top_element##SUFFIX];                              \
    }

#endif // _G_STACK_H
