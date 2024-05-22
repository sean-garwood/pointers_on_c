/* write a fn that extracts a substring from a string. the function should have
the ofllowing prototype:*/

int substr(char *dst, char *src, int start, int len);

/*
it copies the string that begins `start` chars past the beginning of the string
in `src` into the array `dst`.

at most `len` non-NUL chars should be compied from `src`. after copying, `dst`
must be NUL-terminated.

the fn should return the lenght of the string stored in `dst`.

if `start` specifies a position beyond the end of the string in `src`, or if
`start` or `len` are negative, then `dst` should be made an empty string.
*/

#include <stdio.h>
#include <stdlib.h> // Include the stdlib.h header for atoi function

#define MAXLEN 128

int substr(char *dst, char *src, int start, int len)
{
    int i;
    int j = 0;
    for (i = start; i < start + len; i++)
    {
        if (src[i] == '\0')
        {
            break;
        }
        dst[j++] = src[i];
    }
    dst[j] = '\0';
    return j;
}

int main(int argc, char *argv[])
{
    if (argc < 4)
    {
        printf("Usage: %s <src> <start> <len>\n", argv[0]);
        return 1;
    }

    char *src = argv[1];
    int start = atoi(argv[2]); // Convert the string to an integer using atoi
    int len = atoi(argv[3]);   // Convert the string to an integer using atoi

    char dst[MAXLEN];
    int result = substr(dst, src, start, len);
    printf("dst: %s\n", dst);
    printf("len: %d\n", result);
    return 0;
}
