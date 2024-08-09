#ifndef HEADERS_H
#include "headers.h"
#endif

unsigned int get_id()
{
    Part *current = inv->zero;
    unsigned int id = 0;

    while (current != NULL && current->data.desc[0] != '\0')
    {
        id++;
        current = current->next;
    }

    return id;
}

Part *find_part(unsigned int loc)
{
    Part *current = inv->zero;
    while (current != NULL && current->next->data.id != loc)
    {
        current = current->next;
    }
    return current;
}

Part *part_zero(FILE *bin)
{
    Part *zero = MALLOCPART(zero);

    if (((fread(inv, ISIZE, 1, bin)) == FALSE) ||
        (fread(zero, PSIZE, 1, bin)) == FALSE)
    {
        perror("fread");
        return NULL;
    }

    inv->zero = zero;
    inv->zero->next = NULL;

    return zero;
}
Part *init_part_zero()
{
    Part *zero = MALLOCPART(zero);
    zero->data.id = 0;
    zero->data.qty = 0;
    strcpy(zero->data.desc, "HEAD\0");
    zero->next = NULL;
    inv->zero = zero;
    return zero;
}

void print_part_data(Part *p)
{
    printf("ID: %u\n", p->data.id);
    printf("Description: %s\n", p->data.desc);
    printf("Quantity: %u\n", p->data.qty);
    printf("Unit Cost: %.2f\n", p->data.unit_cost);
    printf("Unit Price: %.2f\n", p->data.unit_price);
}
