/* read lines from a file until EOF
print longest line
constraint is that no line may be > 1000 chars*/

#include "1.h"
#include <string.h>

void scan_input_file(FILE *file, char *longest_line);

int main()
{
    char longest_line[MAXLINELEN];
    FILE *input_file = fopen(INPUT, "r");
    scan_input_file(input_file, longest_line);
    printf("longest line: %s", longest_line);
    fclose(input_file);
    return 0;
}

void scan_input_file(FILE *file, char *longest_line)
{
    char line[MAXLINELEN];
    int max_len = 0;
    while (fgets(line, MAXLINELEN, file) != NULL)
    {
        if (strlen(line) > max_len)
        {
            max_len = strlen(line);
            strcpy(longest_line, line);
        }
    }
}

/* problems 1.5 and 1.6 were omitted from the repository due to the fact that
they require copying by rote a large program*/
