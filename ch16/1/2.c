/*
 * write a fn that simulates the throwing of a six-sided die

 return random int in range 1 through 6.

 ensure each value is likely to appear

 first time fn is called, should seed rng with time of day
 */

#include "../headers.h"

int roll_die()
{
    static int first_time = 1;
    SEED(first_time);

    return (rand() % SIDES) + MIN;
}

int main(void)
{
    int first_time = 1;
    printf("Rolling a die 10 times\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", roll_die());
    }

    return 0;
}
