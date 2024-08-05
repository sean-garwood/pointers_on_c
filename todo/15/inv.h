#ifndef INV_H
#define INV_H

#ifndef HEADERS_H
#include "headers.h"
#endif

#define ISIZE sizeof(Inventory)

typedef struct inventory
{
    FILE *output; // binary data file to read/write inventory data
    Part *zero;   // head of the list
} Inventory;

FILE *check_file(const char *filename);
const char *get_file_mode(const char *filename, FILE *file);
FILE *open_file(const char *filename);
Inventory *init_inventory(FILE *output);

// inventory pointer is global
extern Inventory *inv;

#endif
