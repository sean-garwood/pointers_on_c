#ifndef HEADERS_H
#include "headers.h"
#endif

int inv_exists(const char *filename)
{
    FILE *file = fopen(filename, "rb");
    if (file == NULL)
    {
        return FALSE;
    }
    fclose(file);
    return TRUE;
}

void new_inv(Inventory *inv, FILE *output)
{

    inv->part_zero = create_part_zero();
    inv->output = output;
    inv->totals.num_parts = 0;
    inv->totals.num_items = 0;
    inv->totals.total_cost = 0.0;
    inv->totals.total_value = 0.0;
}

int print_all(Inventory *inv)
{
    Part *part = inv->part_zero;
    while (part != NULL)
    {
        if (part->desc[0] != '\0')
        {
            printf("Part number: %u\n", part->id);
            printf("Description: %s\n", part->desc);
            printf("Quantity: %u\n", part->qty);
            printf("Unit cost: %.2f\n", part->unit_cost);
            printf("Unit price: %.2f\n", part->unit_price);
            printf("\n");
        }
        part = part->next;
    }
    return SUCCESS;
}

int update_totals(Inventory *inv)
{
    Part *part = inv->part_zero;
    inv->totals.num_parts = 0;
    inv->totals.num_items = 0;
    inv->totals.total_cost = 0.0;
    inv->totals.total_value = 0.0;
    while (part != NULL)
    {
        if (part->id == 0)
        {
            part = part->next;
            continue;
        }

        if (!(part->desc[0] == '\0'))
            inv->totals.num_parts++;

        inv->totals.num_items += part->qty;
        inv->totals.total_cost += part->qty * part->unit_cost;
        inv->totals.total_value += part->qty * part->unit_price;
        part = part->next;
    }
    return SUCCESS;
}

int print_totals(Inventory *inv)
{
    printf("Number of parts: %u\n", inv->totals.num_parts);
    printf("Number of items: %u\n", inv->totals.num_items);
    printf("Total cost: %.2f\n", inv->totals.total_cost);
    printf("Total value: %.2f\n", inv->totals.total_value);
    return SUCCESS;
}
void write_to_bin(Inventory *inv)
{
    Part *part = inv->part_zero;
    while (part != NULL)
    {
        fwrite(part, sizeof(Part), 1, inv->output);
        part = part->next;
    }
}

void free_memory(Inventory *inv)
{
    Part *part = inv->part_zero;
    Part *temp;
    while (part != NULL)
    {
        temp = part;
        part = part->next;
        free(temp);
    }
    free(inv);
}

int byebye(Inventory *inv, const char *filename)
{
    write_to_bin(inv);
    free_memory(inv);
    printf("Data written to %s.\nMemory freed.\nI/O stream closed.\nGoodbye!",
           filename);
    return SUCCESS;
}
