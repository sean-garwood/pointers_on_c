#ifndef HEADERS_H
#include "headers.h"
#endif

Inventory *inv;

void make_inv(FILE *bin)
{
    if (fgetc(bin) == EOF)
    {
        inv = BLANKINV(inv);
        inv->output = bin;
        inv->zero = BLANKPART(inv->zero);
    }
    else
    {
        rewind(bin);
        inv = MALLOCINV(inv);
        inv->output = bin;
    }
}

int write_inv()
{
    if (inv->zero == NULL)
    {
        return FAILURE;
    }
    fwrite(inv, ISIZE, 1, inv->output);
    return SUCCESS;
}

void debug()
{
    assert(inv->zero != NULL);
    assert(inv->output != NULL);
    printf("part size: %lu\ninv size: %lu\ntrx size: %lu\n", PSIZE, ISIZE, TSIZE);
    assert(write_inv() == SUCCESS);
    fclose(inv->output);
}
