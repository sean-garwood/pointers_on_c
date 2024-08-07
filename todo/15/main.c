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
        // get trxtype

        /* parse the input */
        TrxType trx_t = set_trx_type(buffer);
        Trx *trx;

        buffer[strlen(buffer) - 1] = '\0';
        strcpy(temp_buffer, buffer + 2);

        // get the arguments
        if (get_args(trx_t, temp_buffer, args) == FAILURE)
        {
            puts("get_args failed");
            return EXIT_FAILURE;
        }

        trx = init_trx(trx_t, args);
        debug(trx);
    }
    return write_inv();
}
