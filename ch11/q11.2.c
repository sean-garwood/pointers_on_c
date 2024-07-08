#include "q11.h"

/*
 * What is the total amt of mem you can dynamically allocate on your machine
   when you ask for 500 bytes at a time? 5000 bytes? is there a difference? how
   do you explain if so?
 */

int main()
{
    unsigned long *pi;
    unsigned long i;
    unsigned long total = 0;
    for (i = 0; i < DYNAMIC_BIG_NUMBER / BIG_TRANCHE; i++)
    {
        pi = malloc(BIG_TRANCHE * sizeof(i));
        if (pi == NULL)
        {
            printf("Memory allocation failed\n%s", "");
            return 1;
        }
        total += BIG_TRANCHE;
    }
    printf("Memory allocation successful\n%ld bytes\n", total);
    free(pi);
    return 0;
}
