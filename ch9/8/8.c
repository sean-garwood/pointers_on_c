#include "../ch9.h"
/*
 * write a fn
 */

char *my_strnchr(const char *str, int ch, int which);

/*
 * that is identical to strchr except that the third argument `which` specifies
 * which occurrence of the character is desired.
 *
 * For example, if the third arg is one, the fn behaves exactly like strchr. If
 * the third arg is two, the fn returns a pointer to the second occurrence of ch
 * in the string str.
 */

int main(void)
{
    const char str[] = "fooboz";
    char *first_occurrence = my_strnchr(str, SOUGHT, 1);
    char *second_occurrence = my_strnchr(str, SOUGHT, 2);
    char *third_occurrence = my_strnchr(str, SOUGHT, 3);

    printf("first occurrence of %c in %s is %c\n",
           SOUGHT, str, *first_occurrence);
    printf("* this is in index %ld of %s\n", first_occurrence - str, str);
    printf("second occurrence of %c in %s is %c\n",
           SOUGHT, str, *second_occurrence);
    printf("* this is in index %ld of %s\n", second_occurrence - str, str);
    printf("third occurrence of %c in %s is %c\n",
           SOUGHT, str, *third_occurrence);
    printf("* this is in index %ld of %s\n", third_occurrence - str, str);
    return 0;
}

char *my_strnchr(const char *str, int ch, int which)
{
    int count = 0;
    while (*str && count < which)
    {
        if (*str == ch)
            count++;
        if (count == which)
            return (char *)str;
        str++;
    }
}
