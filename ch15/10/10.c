/* Write a program to compute checksums for files.

cli invocation: `sum [ -f ] [ file ... ]`

The `-f` option is optional.

`file` is a list of file names. If no names given, default to stdin

program computes and prints checksum each file in order in which they are named

Algo for computing checksum:

Each char in file is added to a 32-bit unsigned integer, and the result is the
checksum

Ordinarily, the checksum is written to stdout when eof of each file is found.

If -f option is given, it is written to a file instead of the stdout, whose name
is 'file.cks' where 'file' is the name of the file being checksummed. illegal
when no filename given

sample output:
hw contents = "Hello World!"
hw2 contents = "Hello World!\nHello World!"
$ sum
hi
^D
219
$ sum hw
1095
$ sum -f
-f illegal when reading stdin
$ sum -f hw2 // writes to hw2.cks
$ cat hw2.cks
2190 */

#include "10.h"

int main(int argc, char *argv[])
{
    // check arg count
    if (argc < 2)
    {
        if (F_FLAG_GIVEN)
        {
            printf("-f illegal when reading stdin\n");
            return 1;
        }

        printf("%u\n", checksum(DEFAULT_FILE));
        return 0;
    }

    // compute checksum for each file
    for (int i = 1; i < argc; i++)
    {
        if (F_FLAG_GIVEN)
        {
            FILE *file = fopen(argv[i], "r");
            if (!file)
            {
                perror("fopen");
                return 1;
            }

            FILE *file_cks = fopen(strcat(argv[i], ".cks"), "w");
            if (!file_cks)
            {
                perror("fopen");
                return 1;
            }

            fprintf(file_cks, "%u\n", checksum(file));
            fclose(file);
            fclose(file_cks);
        }
        else
        {
            FILE *file = fopen(argv[i], "r");
            if (!file)
            {
                perror("fopen");
                return 1;
            }

            printf("%u\n", checksum(file));
            fclose(file);
        }
    }

    return 0;
}

unsigned int checksum(FILE *file)
{
    unsigned int sum = 0;
    int c;
    while ((c = fgetc(file)) != EOF)
    {
        sum += c;
    }
    return sum;
}
