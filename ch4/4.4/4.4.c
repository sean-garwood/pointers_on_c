/*write a function copy_n whose prototype is*/

/* The function copy_n should copy n characters from the array src to the array
dst.
If the length of src is less than n, then add enough NUL characters after the
copied chars to get a total of n chars stored.

if len of string in src is greater than or equal to n, then stop after you have
stored the nth char; in this case dst will not be NUL-terminated.

note that a call to `copy_n` should store something into `dst[0] through
dst[n-1]`, and only those locations, regardless of len of src.

if planning on using strncpy, you are congratulated for reading ahead, but you
should figure out logic yourself.

*/

#include <stdio.h>

#define MAXLEN 128

void copy_n(char *dst, char *src, int n);

void copy_n(char *dst, char *src, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (src[i] == '\0')
        {
            break;
        }
        dst[i] = src[i];
    }
    dst[i] = '\0';
}

int main()
{
    char src[MAXLEN];
    char dst[MAXLEN];
    fgets(src, MAXLEN, stdin);
    copy_n(dst, src, MAXLEN - 1);
    printf("%s\n", dst);
    return 0;
}
