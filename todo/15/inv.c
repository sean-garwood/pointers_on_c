#ifndef HEADERS_H
#include "headers.h"
#endif

Inventory *inv;

void init_inv(const char *filename, FILE *bin, Part *zero)
{
    if ((bin = fopen(filename, "wb+")) == NULL)
    {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    fseek(bin, 0, SEEK_END);
    if (ftell(bin) == 0)
    {
        zero = init_part_zero();
        inv->output = bin;
        inv->zero = zero;
    }
    else
    {
        rewind(bin);
        fread(inv, ISIZE, 1, bin);
        inv->zero = zero;
        fread(zero, PSIZE, 1, bin);
        Part *prev = zero;
        while (!feof(bin))
        {
            // read in the next part
            Part *p = MALLOCPART(p);
            if (fread(p, PSIZE, 1, bin) != 1)
                break;
            prev->next = p;
            prev = p;
        }
    }
}

int write_inv()
{
    rewind(inv->output);
    // write the inventory struct to the file
    if (fwrite(inv, ISIZE, 1, inv->output) != 1)
    {
        perror("fwrite");
        return FAILURE;
    }
    // write parts
    Part **current = &inv->zero;
    Part *prev;
    while (*current != NULL)
    {
        if (fwrite(*current, PSIZE, 1, inv->output) != 1)
        {
            perror("fwrite");
            return FAILURE;
        }
        prev = *current;
        current = &prev->next;
        free(prev);
    }
    free(inv);
    return SUCCESS;
}
