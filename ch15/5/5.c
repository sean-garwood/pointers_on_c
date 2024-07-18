/*
 * change the solution to 4.c so that it looks for lines beginning with an int.
 *
 * sum the ints.
 *
 * write the total at the end of the output file.
 *
 * Other than this change, 5.c should perform the same as 4.c.
 */

#include "5.h"

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

    // sum the ints and append to end of file

    int num_ints = sum_ints(output);

    fprintf(output, "The sum of all the ints in the file is: %d\n", num_ints);

    // close the files
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
    if ((*input = fopen(in, "r")) == NULL || (*output = fopen(out, "r+")) == NULL)
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

int sum_ints(FILE *output)
{
    char line[MAX_LINE_LEN];
    long long sum = 0; // Use long long for sum to handle larger numbers
    rewind(output);    // Ensure we start reading from the beginning of the file

    // Check current position and if at EOF
    long position = ftell(output);
    printf("Current position: %ld\n", position);
    if (feof(output))
    {
        printf("At EOF before reading.\n");
    }

    while (fgets(line, MAX_LINE_LEN, output) != NULL)
    {
        int num = 0;
        int i = 0;
        // Convert leading characters to integer if they are digits
        while (line[i] && isdigit(line[i]))
        {
            num = num * 10 + (line[i] - '0');
            i++;
        }
        sum += num;
    }

    if (feof(output))
    {
        printf("Reached EOF after reading.\n");
    }

    // Move to the end of the file to append sum
    fseek(output, 0, SEEK_END);
    return sum;
}
