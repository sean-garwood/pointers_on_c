#ifndef HEADERS_H
#include "headers.h"
#endif

Inventory *inv;

void init_inv(FILE *bin)
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
    return SUCCESS;
}

void debug(Trx *trx)
{
    assert(sizeof(*trx) == TSIZE);
    assert((Trx *)trx != NULL);
    puts("tests passed!");
}
