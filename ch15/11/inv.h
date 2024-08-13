#ifndef INV_H
#define INV_H

#ifndef HEADERS_H
#include "headers.h"
#endif

#define ISIZE sizeof(Inventory)
#define MALLOCINV(i)            \
    (Inventory *)malloc(ISIZE); \
    if ((i) == NULL)            \
    {                           \
        perror("calloc");       \
        exit(EXIT_FAILURE);     \
    }

typedef struct inventory
{
    Part *zero; // head of the list
} Inventory;

int init_inv(const char *filename);
int read_inv(FILE *bin);
int write_inv(const char *filename);
int free_memory(Trx *trx);
// inventory pointer is global
extern Inventory *inv;
#endif
