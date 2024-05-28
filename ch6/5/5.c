/*
Modify the program in ..4/4.c so that it uses arrays of bits to represent the
numbers. Use the bitwise operators to manipulate the bits.
*/
#include <stdio.h>
#include <stdlib.h>

#define SIZE 1e10
#define TRUE 1
#define FALSE 0

#define INDEX(n) ((n) >> 3)      // equivalent to n/8
#define BIT(n) (1U << ((n) & 7)) // equivalent to 2^(n%8)

char *get_nums(long size);
void remove_nonprimes(char *arr, long size);

char *get_nums(long size)
{
    char *arr = calloc((size >> 3) + 1, sizeof(char));
    for (int i = 2; i < size; i++)
        arr[INDEX(i)] |= BIT(i); // set bit i to 1
    return arr;
}

void remove_nonprimes(char *arr, long size)
{
    arr[INDEX(0)] &= ~BIT(0); // set bit 0 to 0
    arr[INDEX(1)] &= ~BIT(1); // set bit 1 to 0
    for (int i = 2; i * i < size; i++)
    {
        if (arr[INDEX(i)] & BIT(i)) // if bit i is 1
        {
            for (int j = i * i; j < size; j += i)
                arr[INDEX(j)] &= ~BIT(j); // set bit j to 0
        }
    }
}

int main(void)
{
    char *arr = get_nums(SIZE);
    unsigned int count = 0;
    remove_nonprimes(arr, SIZE);
    for (int i = 0; i < SIZE; i++)
    {
        if (arr[INDEX(i)] & BIT(i)) // if bit i is 1
        {
            printf("%d, ", i);
            count++;
        }
    }
    printf("\nTotal primes: %d\n", count);
    free(arr);
    return 0;
}
