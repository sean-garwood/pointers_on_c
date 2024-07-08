#include "q11.h"

#define BIG_NUMBER 1000000000
#define DYNAMIC_BIG_NUMBER 8500000000

/*
 * What is the largest static array you can declare on your system?
 */

int main()
{
    int *pi;
    pi = malloc(DYNAMIC_BIG_NUMBER * sizeof(int));
    if (pi == NULL)
    {
        printf("Memory allocation failed\n%s", "");
        return 1;
    }
    printf("Memory allocation successful\n%ld bytes\n",
           DYNAMIC_BIG_NUMBER * sizeof(int));
    return 0;
}
