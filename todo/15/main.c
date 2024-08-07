#ifndef HEADERS_H
#include "headers.h"
#endif

int main(int argc, const char **argv)
{
    ARGCHECK(argc);

    const char *filename = argv[1];
    FILE *bin;
    char buffer[MAXINPUT];      // stdin goes here
    char temp_buffer[MAXINPUT]; // for parsing

    if ((bin = fopen(filename, "wb+")) == NULL)
    {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    init_inv(bin);

    // now we're ready to start taking some user input!

    // get stdin and copy to buffer
    char *args[MAXTRXARGS]; // declare args outside of the while loop

    while (fgets(buffer, MAXINPUT, stdin) != NULL && buffer[0] != 'q')
    {
        /* parse the input */
        Trx *trx = NEWTRX(trx);
        trx->type = set_trx_type(buffer);
        // null-terminate the buffer
        buffer[strlen(buffer) - 1] = '\0';

        strcpy(temp_buffer, buffer + 2); // copy the rest of the buffer to temp_buffer
        if (temp_buffer[sizeof(temp_buffer) - 1] == '\n')
        {
            temp_buffer[sizeof(temp_buffer) - 1] = '\0';
        }

        // get the args
        assert(get_args(trx->type, temp_buffer, args) == SUCCESS);
        assert(args != NULL);
    }

    fwrite(inv->zero, PSIZE, 1, inv->output);
    fclose(bin);
    free(inv->zero);
    free(inv);
    return SUCCESS;
}
