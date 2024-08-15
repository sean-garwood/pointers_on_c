/*
 * sorting an array of structures with qsort
 */

#include <stdlib.h>
#include <string.h>

typedef struct
{
    char key[10];
    int other_data;
} Record;

/* comparison function for qsort */
int record_compare(const void *a, const void *b)
{
    // compare the keys
    // casting is necessary because the function is declared to take pointers to void
    return strcmp(((Record *)a)->key, ((Record *)b)->key);
}

int main(void)
{
    Record array[50];
    // fill the array with data...

    /*
     * args:
     * 1. pointer to the array to be sorted
     * 2. number of elements in the array
     * 3. size of each element
     * 4. comparison function
     */
    qsort(array, 50, sizeof(Record), record_compare);

    return 0;
}
