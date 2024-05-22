/* Take user input from stdin one line at a time
initializes a line number counter at 1. first line received is line 1
send the concatenated line number, space, and user input to stdout*/

#include "1.h"

void add_line_number(char *line, int line_number);

int main()
{
    int line_number = 1;
    char line[100];
    while (fgets(line, sizeof(line), stdin)[0] != '\n')
    {
        add_line_number(line, line_number);
        line_number++;
    }
    return 0;
}

void add_line_number(char *line, int line_number)
{
    printf("%d %s\n", line_number, line);
}
