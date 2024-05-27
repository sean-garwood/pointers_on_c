/*  locate the first char in the `source` char array that exists in chars.
return a pointer to that char
    not allowed to use any string.h functions.
    not allowed to use any subscripts. */

#include <stdio.h>

char *find_char(char const *source, char const *chars);


int main(void)
{
    const char source[] = "ABCDEF";
    const char chars[] = "XQ";
    char *result = find_char(source, chars);
    result == NULL ? printf("result: NULL\n") : printf("result: %c\n", *result);
    return 0;

}

char *find_char(char const *source, char const *chars)
{
    while (*source)
    {
        char const *c = chars;
        while (*c)
        {
            if (*c == *source)
            {
                return (char *)source;
            }
            c++;
        }
        source++;
    }
    return NULL;
}
