/* the UNIX `fgrep` program takes a string and a series of filenames as cli args

 Looks through files one by one

 For each line that contains str:
    name of file
    colon
    line number with string
 ...are printed

 Write this program.

 str arg comes first, cannot contain newline
 filename args come next
   if no filenames given, program should read stdin
     lines printed by program not prefixed with filename or colon

 Assume max line length is 510 characters */

#include "9.h"

int main(int argc, char *argv[])
{
    if (NO_ARGS_GIVEN)
    {
        fprintf(stderr, "Usage: %s str [file ...]\n", argv[0]);
        return 1;
    }

    char *str = STRING;
    if (NO_FILE_GIVEN)
        fgrep(str, DEFAULT_INPUT, NULL);
    else
    {
        for (int i = 2; i < argc; i++)
        {
            char *filename = argv[i];
            FILE *file = fopen(filename, "r");
            if (file == NULL)
            {
                perror(argv[i]);
                return 1;
            }
            fgrep(STRING, file, filename);
            fclose(file);
        }
    }
    return 0;
}

void fgrep(const char *str, FILE *file, const char *filename)
{
    char line[MAX_LINE_LENGTH];
    int line_num = 0;

    while (fgets(line, MAX_LINE_LENGTH, file) != NULL)
    {
        line_num++;
        if (strstr(line, str) != NULL)
        {
            if (file != DEFAULT_INPUT)
                printf("%s:%d: %s\n", filename, line_num, line);
            else
                printf("%d: %s\n", line_num, line);
        }
    }
}
