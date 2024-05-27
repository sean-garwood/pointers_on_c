/*
Modify the program in ..4/4.c so that it uses arrays of bits to represent the
numbers. Use the bitwise operators to manipulate the bits.
*/
#include <stdio.h>
#include <stdlib.h>

#define SIZE 2000000000
#define TRUE 1
#define FALSE 0

#define INDEX(n) ((n) >> 5)       // equivalent to n/32
#define BIT(n) (1U << ((n) & 31)) // equivalent to 2^(n%32)

unsigned int *get_nums(int size);
void remove_nonprimes(unsigned int *arr, int size);

unsigned int *get_nums(int size)
{
    unsigned int *arr = calloc((size >> 5) + 1, sizeof(unsigned int));
    for (int i = 2; i < size; i++)
        arr[INDEX(i)] |= BIT(i); // set bit i to 1
    return arr;
}

void remove_nonprimes(unsigned int *arr, int size)
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
    unsigned int *arr = get_nums(SIZE);
    remove_nonprimes(arr, SIZE);
    for (int i = 0; i < SIZE; i++)
    {
        if (arr[INDEX(i)] & BIT(i)) // if bit i is 1
            printf("%d, ", i);
    }
    free(arr);
    return 0;
}
