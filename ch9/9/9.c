#include "../ch9.h"
/*
 * write a fn
 */

int count_chars(const char *str, const char *chars);

/*
 * * looks through the first arg 'str' and returns the num of chars that match
 *   the chars in the second arg 'chars'.
 */

int main(void)
{
    const char str[] = FOO;
    const char chars[] = OO;
    int count = count_chars(str, chars);
    printf("the number of chars in %s that are in %s is %d\n",
           str, chars, count);
    return 0;
}

int count_chars(const char *str, const char *chars)
{
    int count = 0;
    while (*str)
    {
        if (strchr(chars, *str))
        {
            count++;
            str += sizeof(chars);
        }
        else
            str++;
    }
    return count;
}
