/*Procedure:
1. read lines from the standard input
2. print line number and line to the standard output.

There is no limit to the length of the line.
*/

#include "1.h"

int main()
{
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int line_number = 0;

    while ((read = getline(&line, &len, stdin)) != -1 && line[0] != '\n')
    {
        line_number++;
        printf("%d %s", line_number, line);
    }

    free(line);
    return 0;
}
