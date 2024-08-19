#include "10.h"
/*
 * An insertion sort is performed by adding values to an array one by one.

 The first value is simply stored at beginning of the array.

 Each subsequent value is added by finding its proper position in the array,
 moving existing values as needed to make room for it, and then inserting it.

 Write a function `isort` that performs this task.

 Its prototype should be the same as `qsort`:

 * HINT: consider the array that you get as having a "sorted" part at the
 * beginning (left) and an "unsorted" part at the end (right).
 *
 * The sorted part is empty at the beginning, and grows as the function
 * progresses.
 * Terminate when all elements have been sorted (left is empty, right is full)
 */

int intcmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

void isort(void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *))
{
    char *arr = (char *)base;
    char *key = (char *)malloc(size); // Temporary buffer for the key

    for (size_t i = 1; i < nmemb; i++)
    {
        memcpy(key, arr + i * size, size); // Copy the key
        size_t j = i;
        while (j > 0 && compar(arr + (j - 1) * size, key) > 0)
        {
            memcpy(arr + j * size, arr + (j - 1) * size, size);
            j--;
        }
        memcpy(arr + j * size, key, size); // Place the key in its correct position
    }

    free(key); // Free the temporary buffer
}

int main(void)
{
    // get random numbers to test
    srand(time(NULL));
    int randoms[N];
    int this, next;
    for (int i = 0; i < N; i++)
        randoms[i] = rand() % N;

    // sort the random numbers
    isort(randoms, N, sizeof(int), intcmp);
    // check answer
    for (int i = 0; i < N - 1; i++)
    {
        this = randoms[i];
        next = randoms[i + 1];
        if (this > next)
        {
            printf("failed on index %d:\n\tthis: %d\n\tnext: %d\n",
                   i, this, next);
            return 1;
        }
    }

    return 0;
}
