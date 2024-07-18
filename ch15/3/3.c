/*
 * change ex2 to remove restriction on line length. if a line is longer than 80,
 * process in chunks.
 */

#include <stdio.h>
#define MAX_LINE_LEN 82 // leave space for newline and null byte

int main(void)
{
    FILE *out, *in;
    char chunk[MAX_LINE_LEN];

    // open the file for reading
    if ((in = fopen("in.txt", "r")) == NULL ||
        (out = fopen("out.txt", "w")) == NULL)
    {
        perror("fopen");
        return 1;
    }

    // read/write in chunks
    while (fgets(chunk, MAX_LINE_LEN, in) != NULL)
    {
        // check if chunk has a newline in index before null byte
        if (chunk[MAX_LINE_LEN - 2] != '\n')
            chunk[MAX_LINE_LEN - 2] = '\n';

        fputs(chunk, out);
    }

    // close the file
    fclose(in);
    fclose(out);
    return 0;
}
