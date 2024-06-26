/*
 * write a fn called `my_strnlen` that is similar to `strlen` but able to handle
 * unterminated strings created with the strn... fns.
 *
 * Pass an arg containing sizeof(array) that holds str to be tested.
 */

#include <stdio.h>
#include <string.h>
#define SIZE 100

size_t my_strnlen(const char *str, size_t size);

int main(void)
{
    // get string from user
    char str[SIZE];
    printf("Enter a string: ");
    fgets(str, SIZE, stdin);
    str[strcspn(str, "\n")] = 0;
    printf("Length of string: %zu\n", my_strnlen(str, sizeof(str)));

    return 0;
}

size_t my_strnlen(const char *str, size_t size)
{
    size_t len = sizeof(*str);
    while (*str != '\0' && size > 0)
    {
        len++;
        str++;
    }
    return len;
}
