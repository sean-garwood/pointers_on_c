/*
 * write program that scans stdin and counts num times the word 'the' appears.
 *
 *
 *
 *
 *
 * requirements:
 *      it should be case-sensitive.
 *      assume that words will be separated from each other by one or more
 *      whitespace chars; input lines will be less than 100 chars long.
 *      write count to the stdout.
 */

#include "../ch9.h"

int count_thes(char *str);
void result(int count);

int main(void)
{
    char str[MAXLEN];

    printf("Enter a string. I\'ll count the number of times 'the' appears: ");
    result(count_thes(str));
    return 0;
}

int count_thes(char *str)
{
    int count = 0;
    while (fgets(str, MAXLEN, stdin))
    {
        char *word = strtok(str, " \n\t");
        while (word)
        {
            if (strcmp(word, "the") == 0)
                count++;
            word = strtok(NULL, " \n\t");
        }
    }
    return count;
}

void result(int count)
{
    printf("*** The word 'the' appears %d time%sin the string.\n",
           count, count == 1 ? " " : "s ");
}
