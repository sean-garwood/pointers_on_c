#include "8.h"

/*
 * datafile contains the ages of family members.

 the ages of the members of one family are all on the same line, separated by
 white space, eg

 45 42 22
 36 35 7 3 1
 22 20

 write a program that computes the average age of each family represented in the
 data file.

 print the average age using `%5.2f` format.

 max line length is 512 characters.
 */

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <datafile>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    int members, age, total_age;
    float avg;
    char line[MAXLINE];

    while (fgets(line, MAXLINE, fp) != NULL)
    {
        members = age = total_age = 0;
        avg = 0.00;
        char *token = strtok(line, " ");
        while (token != NULL)
        {
            ++members;
            total_age += atoi(token);
            token = strtok(NULL, " ");
        }
        avg = ((float)total_age) / ((float)members);
        printf("%5.2f\n", avg);
    }

    return 0;
}
