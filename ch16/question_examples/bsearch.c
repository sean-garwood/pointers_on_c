/*
 * demo of binary search applied to a **sorted** array
 */

#include <stdlib.h>
#include <string.h>

#define LEN 50

typedef struct
{
    char key[10];
    int other_data;
} Record;

/*
 * the prototype for bsearch is as follows:
 * void *bsearch(const void *key, const void *base, size_t n_elements,
 *               size_t element_size,
 *               int (*compare)(const void *, const void *));
 *
 * args:
 * 1. key: the value to search for
 * 2. base: pointer to the first element of the array
 * 3. n_elements: number of elements in the array
 * 4. element_size: size of each element in the array
 * 5. compare: comparison function
 */

/* comparison function: compare only the key value */
int record_compare(const void *a, const void *b)
{
    return strcmp(((Record *)a)->key, ((Record *)b)->key);
}

int main(void)
{
    Record array[LEN];
    Record key;
    Record *found;

    /*
     * code to fill the array and sort it
     */

    /*
     * Create a key record
     *     only the key field filled in with the value we want to locate
     * search the array for the key
     */

    strcpy(key.key, "value");
    found = bsearch(&key, array, LEN, sizeof(Record), record_compare);

    // found points to the array whose key matches the value, or nil if not found

    return EXIT_SUCCESS;
}
