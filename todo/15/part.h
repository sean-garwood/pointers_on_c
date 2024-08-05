
#ifndef PART_H
#define PART_H

#ifndef HEADERS_H
#include "headers.h"

#endif
#define MAXDESC 21
#define PSIZE sizeof(Part)
#define NEWPART(p)            \
    (Part *)calloc(1, PSIZE); \
    if ((p) == NULL)          \
    {                         \
        perror("calloc");     \
        exit(EXIT_FAILURE);   \
    }

typedef struct part_data
{
    unsigned int id;
    unsigned int qty;
    float unit_cost;
    float unit_price;
    char desc[MAXDESC];
} PartData;

typedef struct part
{
    PartData data;
    struct part *next;
} Part;

/*
 * TODO: Implement the following functions
 *
 * init_part_zero
 */

Part *init_part_zero(void);
#endif
