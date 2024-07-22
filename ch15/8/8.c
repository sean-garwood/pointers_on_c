/* Write a program to produce a hex dump of a file (oh boy!)

 It should take a single arg from the cli: name of file to dump

 If ar is missing, dump stdin

 Each line should have following format:

 | columns | contents |
 |---------|----------|
 | 1-6     | current offset in file (hex) with leading zeroes |
 | 9-43    | hex rep of the next CHUNK bytes in the file. Printed in four groups
             of 8 hex digits with a space btwn each group. |
 | 46      | an asterisk |
 | 47-62   | char representation of the same CHUNK bytes.
             Non-printable chars should be replaced with a period. |
 | 63      | an asterisk |

 All hex should use uppercase letters
 sample outputs:

 000200 D405C000 82102004 91D02000 9010207F *...... ... ... .*
 000210 82102001 91D02000 0001C000 2F757372 *.. ... ...../usr*
 000220 2F6C6962 2F6C642E 736F002F 6465762F /lib/ld.so./dev*


 pseudocode

 open file
 read binary
 write formatted output to a file
 close file */

#include "8.h"

int main(int argc, char *argv[])
{
    FILE *input, *output;
    long pos;
    unsigned char buffer[CHUNK];
    size_t bytes_read;

    if (argc > MAXARGS)
    {
        printf("Usage: %s [filename]\n", argv[0]);
        return 1;
    }

    // open io files
    input = (argc != MAXARGS) ? DEFAULT_STREAM : fopen(INPUT_FILE, "rb");
    output = fopen(OUTPUT_FILE, "w");

    // check if file streams opened
    if (input == NULL || output == NULL)
    {
        printf("Error opening files\n");
        return 1;
    }

    /*
     * now the work begins. read the file in chunks of CHUNK bytes
     */

    // initial position should be beginning of file
    // can't use ftell for stdin so set to zero if input == stdin

    pos = (input == DEFAULT_STREAM) ? 0 : ftell(input);
    if (pos == -1)
    {
        if (ferror(input))
        {
            printf("Error reading file position\n");
            clearerr(input); // Clear error state if you plan to attempt further operations
        }
        else
        {
            printf("Seek operation not supported on this stream\n");
        }
        return 1;
    }
    while ((bytes_read = fread(buffer, 1, CHUNK, input)) > 0)
    {
        fprintf(output, "%06lX ", pos);
        pos += bytes_read;

        for (size_t i = 0; i < bytes_read; i++)
        {
            fprintf(output, "%02X", buffer[i]);
            if (i % 4 == 3) // Ensure space after every 8 bytes and at the end of the chunk
                fprintf(output, " ");
        }

        fprintf(output, "*");

        for (size_t i = 0; i < bytes_read; i++)
        {
            fprintf(output, "%c", isprint(buffer[i]) ? buffer[i] : '.');
        }

        fprintf(output, "*\n");
    }

    /*
     * close the files
     */
    fclose(input);
    fclose(output);

    return 0;
}
