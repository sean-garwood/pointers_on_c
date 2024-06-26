/*
 * write a fn `my_strcat` that is similar to strcat but will not overflow the
 * destination array.
 */
#include "../ch9.h"

char *my_strcat(char *dest, const char *src, size_t len);

int main(void)
{
    // dummy values
    char dest[SIZE];
    const char src[] = "foo";
    for (int i = 0; i < SIZE; i++)
    {
        dest[i] = 'a';
    }
    my_strcat(dest, src, 8);
    printf("dest: %s\n", dest);
    return 0;
}

char *my_strcat(char *dest, const char *src, size_t len)
{
    if (len > SIZE)
        len = SIZE;
    else if (len + strlen(dest) > SIZE)
    {
        /* overwrite the last len bytes of dest with the first len
         * bytes of src if the length of dest + src is greater than
         * the size of dest.
         */
        char *overwrite = dest + strlen(dest) - len;
        strncpy(overwrite, src, len);
    }
    else
        strncat(dest, src, len);
    return dest;
}
