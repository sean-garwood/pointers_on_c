/*
 * write a fn
 */
#include "../ch9.h"
char *my_strrchr(char const *str, int ch);

/*
 * same as strrchr but returns pointer to last occurrence of char in str
 */

int main(void)
{
    const char str[] = "foo";
    char ch = 'o';
    char *last = my_strrchr(str, ch);
    printf("last occurrence of %c in %s is %c\n", ch, str, *last);
    printf("this is in index %ld\n of %s", last - str, str);
    return 0;
}

char *my_strrchr(char const *str, int ch)
{
    char *last = NULL;
    while (*str)
    {
        if (*str == ch)
            last = (char *)str;
        str++;
    }
    return last;
}
