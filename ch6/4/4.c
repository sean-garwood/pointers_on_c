/* write a program that implements the Sieve of Eratosthenes.


Algo:

1. write down all nums from 2..n
2. cross out non prime nums
    a. start with 2, cross out all multiples of 2
    b. move to next uncrossed num, cross out all multiples of that num
    c. repeat until no more uncrossed nums
3. the remaining uncrossed nums are the primes

use an array for your list.
the value in each array element keeps track fo whether the number is crossed
out.
Set all elements of array to true intially, then set the elements to false as
you cross out the numbers.

Start with an array of 1000 elements. if you need more, increase the size of
the array.
*/
#include <stdio.h>
#include <stdlib.h>

#define TRUE 'y'
#define FALSE 'n'
#define SIZE 500000000 // didn't like 1 billion.
char *get_nums(int size);
void remove_nonprimes(char *arr, int size);

char *get_nums(int size)
{
    char *arr = malloc(size * sizeof(char)); // a wild malloc appeared!
    // this program could not handle 1m before this was used.
    // author recommends starting with 1000 elements (lol 1999)
    for (int i = 0; i < size; i++)
        (i % 2 == 0) ? (arr[i] = FALSE) : (arr[i] = TRUE);
    return arr;
}

void remove_nonprimes(char *arr, int size)
{
    for (int i = 3; i < size; i += 2)
    {
        if (arr[i] == TRUE)
        {
            for (int j = i + i; j < size; j += i)
                arr[j] = FALSE;
        }
    }
}

int main(void)
{
    char *arr = get_nums(SIZE);
    remove_other_primes(arr, SIZE);
    for (int i = 2; i < SIZE; i++)
    {
        if (arr[i] == TRUE)
            printf("%d, ", i);
    }
    free(arr);
    return 0;
}
