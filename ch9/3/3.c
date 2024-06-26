/*
 * write a fn similar to strcpy but that doesn't overflow dest array. result of
 * copy must be a true string.
 */

#include <stdio.h>
#include <string.h>

#define SIZE 10

char *my_strcpy(char *dest, const char *src);

int main(void)
{

    char dest[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        dest[i] = 'a';
    }
    const char src[] = "foo";
    my_strcpy(dest, src);
    printf("dest: %s\n", dest);
    return 0;
}

char *my_strcpy(char *dest, const char *src)
{
    int max = strlen(dest);
    int len = strlen(src);
    for (int i = 0; i < max && i < len; i++)
    {
        dest[i] = src[i];
    }
    // add null terminator to dest
    dest[len] = '\0';
    return dest;
}
