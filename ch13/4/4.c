/*
 * write a sort function that will sort an array of any type. To make it
 * generic, one of its args must be a pointer to a callback comparison function
 * that the caller will supply.
 *
 * the comparison function will take two args: pointers to the values to be
 * compared.
 *
 * It returns an integer such that:
 *     0 if the values are equal
 *     less than 0 if the first value is less than the second
 *     greater than 0 if first value is greater than the second
 *
 *
 * The args to sort must be:
 *
 *     1. a pointer to the first value in the array to be sorted.
 *     2. the number of values in the array
 *     3. sizeof each element in the array
 *     4. pointer to compare function
 *
 * Return type:
 *
 *     void
 *
 * More restrictions:
 *
 *     * cannot declare array arg with its real type because the fn can be
 *       called to sort different types of arrays.
 *         * if you treat the data as if it were an array of chars, you can use
 *           the third argument listed above both to locate the beginning of
 *           each element and to calculate the address of the next element. (??)
 *               * this is a common technique in C.
 *     * You may (but for this exercise, we will) use exchange sort:
 *
 *           for i = 1 to num_records - 1 do
 *             for j = i + 1 to num_records do
 *               if record i > record j then
 *                 exchange record i with record j
 */
#include "4.h"
int main(void)
{
    // stub
    return 0;
}

int compare(void *a, void *b)
{
    /*
     * user-supplied comparison function
     * if a == b, return 0
     * if a < b, return -1
     * if a > b, return 1
     */

    return 0;
}

void exchange_sort(void *element, int num_elements, int size_of_element,
                   int (*compare)(void *, void *))
{
    for (int i = 0; i < num_elements - 1; i++)
    {
        for (int j = i + 1; j < num_elements; j++)
        {
            if (compare(element + i * size_of_element, element + j * size_of_element) > 0)
            {
                void *temp = malloc(size_of_element);
                // exit if malloc fails
                if (temp == NULL)
                {
                    return;
                }
                memcpy(temp, element + i * size_of_element, size_of_element);
                memcpy(element + i * size_of_element,
                       element + j * size_of_element, size_of_element);
                memcpy(element + j * size_of_element, temp, size_of_element);
                free(temp);
            }
        }
    }
}
