/*
 * modify 3.c to prompt for and read two filenames from stdin.

 first is the input file

 second is the output file

 program should open both files and copy from the input file to the output file
 as before.
 */

#include "../4..5.h"

int main(void)
{
    char in[MAX_LINE_LEN], out[MAX_LINE_LEN], chunk[MAX_LINE_LEN];
    FILE *output, *input;

    // get file names from stdin
    get_file_names(in, out);

    // open the file for reading
    if (open_files(&input, &output, in, out) == FAILURE)
        return FAILURE;

    // read/write in chunks
    copy_in_chunks(chunk, input, output);

    // close the file
    close_io(input, output);
    return SUCCESS;
}

void get_file_names(char *in, char *out)
{
    printf("Enter input file name: ");
    if (fgets(in, MAX_LINE_LEN, stdin) == NULL)
    {
        perror("Error reading input file name");
        exit(FAILURE);
    }
    printf("Enter output file name: ");
    if (fgets(out, MAX_LINE_LEN, stdin) == NULL)
    {
        perror("Error reading output file name");
        exit(FAILURE);
    }
    // Remove potential newline characters from fgets
    in[strcspn(in, "\n")] = 0;
    out[strcspn(out, "\n")] = 0;
}

int open_files(FILE **input, FILE **output, const char *in, const char *out)
{
    if ((*input = fopen(in, "r")) == NULL || (*output = fopen(out, "w")) == NULL)
    {
        perror("fopen");
        return FAILURE;
    }
    else
        return SUCCESS;
}

void copy_in_chunks(char *buffer, FILE *input, FILE *output)
{
    while (fgets(buffer, MAX_LINE_LEN, input) != NULL)
    {
        // check if chunk has a newline in index before null byte
        if (buffer[MAX_LINE_LEN - 2] != '\n')
            buffer[MAX_LINE_LEN - 2] = '\n';

        fputs(buffer, output);
    }
}

void close_io(FILE *input, FILE *output)
{
    fclose(input);
    fclose(output);
}
