#ifndef HEADERS_H
#include "headers.h"
#endif

Inventory *inv;

int init_inv(const char *filename)
{
    int result;
    inv = MALLOCINV(inv);
    FILE *test_bin = fopen(filename, "rb+");
    FILE *bin;
    if ((bin = test_bin) == NULL)
    {
        bin = fopen(filename, "wb+");
        if (bin == NULL)
        {
            perror("fopen");
            return FAILURE;
        }
        inv->output = bin;
        inv->zero = init_part_zero();
    }
    else
        result = read_inv(bin);

    result = ((inv->zero != NULL) == TRUE) ? SUCCESS : FAILURE;
    result == SUCCESS ? printf("Inventory initialized\n") : printf("Inventory not initialized\n");
    fclose(bin);

    return result;
}
int read_inv(FILE *bin)
{
    Part *current = part_zero(bin);
    Part *temp;
    inv->zero = current;

    while (TRUE)
    {
        temp = MALLOCPART(temp);
        if (fread(temp, PSIZE, 1, bin) != 1)
        {
            free(temp);
            break;
        }
        current->next = temp;
        current = temp;
    }
    return SUCCESS;
}

int write_inv(const char *filename)
{

    FILE *updated; // updated file goes here
    Part *current = inv->zero;
    // close the inv->output file that was used to read
    // open the file for writing
    updated = fopen(filename, "wb");
    // POINT TO THE NEW FILE

    if (fwrite(inv, ISIZE, 1, updated) != 1)
    {
        perror("fwrite");
        return FAILURE;
    }

    while (current != NULL)
    {
        if (fwrite(current, PSIZE, 1, updated) != 1)
        {
            perror("fread");
            return FAILURE;
        }
        current = current->next;
    }
    fclose(updated);
    printf("Inventory written\n");
    return SUCCESS;
}

int free_memory(Trx *trx)
{
    Part *current, *temp;
    current = inv->zero;

    while (current != NULL)
    {
        temp = current;
        current = current->next;
        free(temp); // free parts
    }

    free(trx);
    free(inv);
    return SUCCESS;
}
