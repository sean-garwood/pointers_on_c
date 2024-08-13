#ifndef PART_H
#define PART_H

#ifndef HEADERS_H
#include "headers.h"
#endif

#define MAXDESC 21
#define PSIZE sizeof(Part)
#define MALLOCPART(p)       \
    (Part *)malloc(PSIZE);  \
    if ((p) == NULL)        \
    {                       \
        perror("calloc");   \
        exit(EXIT_FAILURE); \
    }

typedef struct part
{
    struct part *next;
    struct
    {
        unsigned int id;
        unsigned int qty;
        float unit_cost;
        float unit_price;
        char desc[MAXDESC];
    } data;
} Part;

unsigned int get_id(void);
Part *find_part(unsigned int loc);
Part *init_part_zero(void);
Part *part_zero(FILE *bin);
void print_part_data(Part *p);
#endif
