#include "../11.h"

/*
 * write a fn that reads a list of ints from stdin and returns the values in a
 * dynamically allocated array.
 *
 * End of the input list is determined by EOF
 *
 * The first number in the array shoudl be a count of how many values the array
 * contains. This number is followed by the values.
 *
 * the separator for the given ints will be a space, newline, or tab. ( we can
 * use the strtok? fn to split the input into ints, then cast the strings to ints)
 *
 * 1. get the input from the user
 * 2. split the input into tokens, which are themselves strings (use strtok)
 * 3. convert the tokens to ints
 * 4. count the number of tokens
 * 5. allocate memory for the array:
 *     - the first element is the count of the number of tokens
 *    - the rest of the elements are the tokens
 * 6. return the dynamically allocated array.
 */

int main(void)
{
    int *p = get_ints();
    if (p == NULL)
    {
        printf("***Memory allocation failed!\n%s", "");
        return 1;
    }
    else
    {
        // print the length of the array, denoted by p[0]
        printf("Length of the array: %d\n", p[0]);
        // print elements
        for (int i = 1; i <= p[0]; i++)
            printf("%d ", p[i]);
    }
    free(p);
    return 0;
}

int *get_ints(void)
{
    // while input is not EOF
    // read the input, which is a list of integers delimited by whitespace
    int arr[MAXLEN];
    int i = 0;
    while (scanf("%d", &arr[i]) != EOF)
        i++;

    // use my_calloc to allocate memory for the array
    int *p = my_calloc(i + 1, sizeof(int));
    if (p == NULL)
        return NULL;

    // put the number of elements in the first element of the array
    p[0] = i;

    // copy the values from arr to p
    for (int j = 0; j < i; j++)
        p[j + 1] = arr[j];

    return p;
}
