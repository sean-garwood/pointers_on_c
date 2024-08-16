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
    int results[SIDES] = {0};

    printf("Rolling a %d-sided die %d times\n", SIDES, TRIALS);
    for (int i = 0; i < TRIALS; i++)
        results[roll_die() - 1] += 1;

    for (int i = MIN; i <= SIDES; i++)
        printf("%d: %d\n", i, results[i - 1]);

    return 0;
}
