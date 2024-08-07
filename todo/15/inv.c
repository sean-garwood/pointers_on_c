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
void debug()
{
    assert(inv->zero != NULL);
    assert(inv->output != NULL);
    printf("part size: %lu\ninv size: %lu\ntrx size: %lu\n", PSIZE, ISIZE, TSIZE);
    fclose(inv->output);
}
