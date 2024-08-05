#ifndef HEADERS_H
#include "headers.h"
#endif

Inventory *inv;

/*
 * TODO: Implement the following functions
 *
 * check_file
 * get_file_mode
 * init inventory
 */

FILE *read_file(const char *filename)
{
    // check if the given filename exists
    return fopen(filename, "r");
}

const char *get_file_mode(const char *filename, FILE *file)
{
    // check if the file is readable
    if (file == NULL)
    {
        return "w+b";
    }
    fclose(file);
    return "r+b";
}

FILE *open_file(const char *filename)
{
    // get the file mode
    return fopen(filename, get_file_mode(filename, read_file(filename)));
}

Inventory *init_inventory(FILE *output)
{
    // allocate memory for the inventory
    inv = (Inventory *)calloc(1, ISIZE);
    if (inv == NULL)
    {
        perror("calloc");
        return NULL;
    }

    inv->output = output;
    return inv;
}

// test main
