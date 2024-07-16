/*
 * write a program that reads from stdin and computes percentage of chars it
 * finds in each following category:
 *
 *   control chars
 *   whitespace chars
 *   digits
 *   lowercase letters
 *   uppercase letters
 *   punctuation chars
 *   non-printable chars
 *
 * Char categories are to be as they are defined for the `ctype.h` functions.
 *
 * Do not use `if` statements.
 */

#include "1.h"

int main(void)
{
    int ch;
    int category;
    int total = 0;
    while ((ch = getchar()) != EOF)
    {
        total++;
        for (category = 0; category < (int)N_CATEGORIES; category++)
        {
            if (compare[category](ch))
            {
                count[category]++;
                break;
            }
        }
    }

    printf("\ntotal chars: %d\n", total);
    if (total == 0)
    {
        printf("No characters found\n");
        return 0;
    }
    else
    {
        for (category = 0; category < (int)N_CATEGORIES; category++)
        {
            printf("%s: %6.2f%%\n", category_names[category], count[category] * 100.0 / total);
        }
    }
    return 0;
}

int not_print_flag(int ch)
{
    return !isprint(ch);
}
