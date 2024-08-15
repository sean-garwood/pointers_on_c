/*
 * setjmp() and longjmp() are used for non-local goto.
 * setjmp() saves the current execution context in env and returns 0.
 * longjmp() restores the execution context saved in env and returns to the point where setjmp() was called.
 *
 * Useful for deeply nested function calls/restoring the state of a program/error handling.
 */

#include "trx.h"

/* var that stores setjmp's state information */
jmp_buf env;

int main(void)
{
    int value;
    Trx *trx;

    /* establish the point at which we want to resume execution after call to
       longjmp() */
    value = setjmp(env);

    /* figure out what to do after return from setjmp() */
    switch (value)
    {
    default:
        // longjmp() was called -- fatal error
        fputs("Fatal error\n", stderr);
        break;
    case 1:
        // longjmp()was called -- minor error
        fputs("Invalid transaction\n", stderr);
        // fall through...
    case 0:
        // normal execution after original return from setjmp()
        while (trx = get_trx() != NULL)
            process(trx);
    }
    write_data_to_file();
    return value == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}

void write_data_to_file()
{
    // write data to file
}

Trx *get_trx(void)
{
    // get transaction
}

void process(Trx *trx)
{
    // process transaction
}
