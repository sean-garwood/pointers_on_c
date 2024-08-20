/*
 * A client that uses the generic data stack module (./stack/g_stack.h) to
 * create two stacks holding different types of data.
 */

#ifndef _G_CLIENT_H
#include "g_client.h"
#endif

GENERIC_STACK(int, _int, 10)    // create a stack of integers
GENERIC_STACK(float, _float, 5) // create a stack of floats

int main(void)
{
    /* push several values on each stack */
    push_int(5);
    push_int(22);
    push_int(15);
    push_float(25.3);
    push_float(-40.5);

    /* empty the int stack and print the values */
    while (!is_empty_int())
    {
        printf("popping top_int: %d\n", top_int());
        pop_int();
    }

    /* empty float stack and print values */
    while (!is_empty_float())
    {
        printf("popping top_float: %.2f\n", top_float());
        pop_float();
    }

    return EXIT_SUCCESS;
}
