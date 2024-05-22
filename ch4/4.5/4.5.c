/*read file arg line by line and does the following:

for each set of two or more identical, adjacent lines in the file, on eline from
the set should be printed out; nothing else should be printed out.

assume lines in file will not exceed 128 chars in length (127 + \n)
do not use string.h methods/functions!
*/

#include <stdio.h>
#include <string.h>
#define MAXLEN 128
#define INPUTFILE "input.txt"

/*
pseudocode

1. get lines from input.txt
2. scan lines from file, storing one instance of duplciate in duplicates and skipping all
other identical consecutive lines
3. goto 3 until all lines are scanned
4. print duplicates
*/

int main()
{
    FILE *fp;
    char line[MAXLEN];
    char prev[MAXLEN];
    int is_duplicate = 0;

    fp = fopen(INPUTFILE, "r");
    if (fp == NULL)
    {
        perror("Error in opening file");
        return -1;
    }

    while (fgets(line, MAXLEN, fp) != NULL)
    {
        if (strcmp(line, prev) == 0)
        {
            if (!is_duplicate)
            {
                printf("%s", line);
                is_duplicate = 1;
            }
        }
        else
        {
            is_duplicate = 0;
        }
        strcpy(prev, line);
    }

    fclose(fp);
    return 0;
}
