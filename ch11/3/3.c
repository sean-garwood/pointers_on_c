/*
 * write a program that reads a string from stdin and returns a copy of the
 * string in dynamically allocated memory. the program may not impose a limit on
 * the size of the string being read.
 */

#include "../11.h"

int main(void)
{
    char *s = copy_string_to_alloc();
    printf("%s\n", s);
    printf("size of string: %ld\n", strlen(s));
    free(s);
    return 0;
}

char *copy_string_to_alloc(void)
{
    char *s = malloc(1);
    char c;
    int i = 0;
    if (s == NULL)
    {
        printf("Memory allocation failed\n%s", "");
        return NULL;
    }

    while ((c = getchar()) != '\n' && c != EOF)
    {
        s = realloc(s, i + 1);
        if (s == NULL)
        {
            printf("Memory allocation failed\n%s", "");
            return NULL;
        }
        s[i++] = c;
    }

    return s;
}
