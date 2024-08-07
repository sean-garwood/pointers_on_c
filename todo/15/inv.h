#ifndef INV_H
#define INV_H

#ifndef HEADERS_H
#include "headers.h"
#endif

#define ISIZE sizeof(Inventory)
// for calloc
#define BLANKINV(i)                \
    (Inventory *)calloc(1, ISIZE); \
    if ((i) == NULL)               \
    {                              \
        perror("calloc");          \
        exit(EXIT_FAILURE);        \
    }

// for malloc
#define MALLOCINV(i)            \
    (Inventory *)malloc(ISIZE); \
    if ((i) == NULL)            \
    {                           \
        perror("calloc");       \
        exit(EXIT_FAILURE);     \
    }

typedef struct inventory
{
    FILE *output; // binary data file to read/write inventory data
    Part *zero;   // head of the list
} Inventory;

void make_inv(FILE *bin);

void debug(void);

// inventory pointer is global
extern Inventory *inv;

#endif
