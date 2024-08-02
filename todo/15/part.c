#ifndef HEADERS_H
#include "headers.h"
#endif

Part *find_part(Inventory *inv, unsigned int part_num)
{
    Part *part = inv->part_zero;
    while (part != NULL && part->id != part_num)
    {
        part = part->next;
    }

    return part;
}

Part *create_part_zero(void)
{
    Part *part_zero = calloc(1, sizeof(Part));
    if (part_zero == NULL)
    {
        perror("Error allocating memory for part_zero");
        return NULL;
    }

    strcpy(part_zero->desc, "***Totals***");

    return part_zero;
}

int new_part(Inventory *inv, const char *desc, unsigned int qty, float unit_cost)
{
    unsigned int new_part_id = get_part_id(inv);
    unsigned int max_part_id = inv->totals.num_parts + 1;
    Part *new_part = malloc(sizeof(Part));
    if (new_part == NULL)
    {
        perror("Error allocating memory for new part");
        return FAILURE;
    }

    new_part->id = new_part_id;
    if (new_part_id == 1)
        inv->part_zero->next = new_part;

    new_part->qty = qty;
    new_part->unit_cost = unit_cost;
    new_part->unit_price = 0.0;
    strncpy(new_part->desc, desc, sizeof(new_part->desc) - 1);
    new_part->desc[sizeof(new_part->desc) - 1] = '\0';
    new_part->next =
        (new_part->id == max_part_id) ? NULL : find_part(inv, new_part_id + 1);

    return SUCCESS;
}

int buy_part(Inventory *inv, unsigned int part_num, unsigned int qty, float this_unit_cost)
{
    Part *part = find_part(inv, part_num);
    if (part == NULL || qty <= 0 || part->desc[0] == '\0')
        return FAILURE;

    float old_unit_cost = part->unit_cost;
    unsigned int old_qty = part->qty;

    part->qty += qty;
    part->unit_cost = ((old_unit_cost * old_qty) + (this_unit_cost * qty)) /
                      part->qty;

    return SUCCESS;
}

int sell_part(Inventory *inv, unsigned int part_num, unsigned int qty, float unit_price)
{
    Part *part = find_part(inv, part_num);
    if (part == NULL || part->qty < qty || qty <= 0)
        return FAILURE;

    float old_unit_price = part->unit_price;
    unsigned int old_qty = part->qty;

    part->qty -= qty;
    part->unit_price = ((old_unit_price * old_qty) + (unit_price * qty)) /
                       part->qty;

    return SUCCESS;
}

int delete_part(Inventory *inv, unsigned int part_num)
{
    Part *part;
    if ((part = find_part(inv, part_num)) == NULL)
        return FAILURE;

    part->qty = 0;
    part->unit_cost = 0;
    part->unit_price = 0;
    part->desc[0] = '\0';

    return SUCCESS;
}

int print_part(Inventory *inv, unsigned int part_num)
{
    Part *part = find_part(inv, part_num);
    if (part == NULL || part->desc[0] == '\0')
    {
        return FAILURE;
    }
    printf("Part number: %u\n", part->id);
    printf("Description: %s\n", part->desc);
    printf("Quantity: %u\n", part->qty);
    printf("Unit cost: %.2f\n", part->unit_cost);
    printf("Unit price: %.2f\n", part->unit_price);
    printf("\n");
    return SUCCESS;
}

unsigned int get_part_id(Inventory *inv)
{
    unsigned int part_id = 1;
    Part *part = inv->part_zero;

    for (; part != NULL; part = part->next)
    {
        if (part->desc[0] == '\0')
        {
            return part_id;
        }
        part_id++;
    }

    return part_id;
}
