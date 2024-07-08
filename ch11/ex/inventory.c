// create a SUBASSEMBLY inventory record
#include "inventory.h"

int main(void)
{
    // create a subassembly record
    InventoryRecord *subassy_rec;
    subassy_rec = create_subassy_record(3);
    if (subassy_rec == NULL)
    {
        printf("Memory allocation failed\n%s", "");
        return 1;
    }
    // fill in the parts
    subassy_rec->info.subassy->part[0].quan = 5;
    subassy_rec->info.subassy->part[1].quan = 10;
    subassy_rec->info.subassy->part[2].quan = 15;
    // print the parts
    for (int i = 0; i < subassy_rec->info.subassy->n_parts; i++)
    {
        printf("%d\n", subassy_rec->info.subassy->part[i].quan);
    }
    // create a part record
    InventoryRecord *part_rec;
    part_rec = create_part_record(100, 1);
    if (part_rec == NULL)
    {
        printf("Memory allocation failed\n%s", "");
        return 1;
    }
    // print the part info
    printf("cost: %d\nsupplier: %d\n", part_rec->info.part->cost,
           part_rec->info.part->supplier);

    // free the records
    discard_inventory_record(subassy_rec);
    discard_inventory_record(part_rec);
    printf("Memory freed\n%s", "");
    return 0;
}

InventoryRecord *create_subassy_record(int n_parts)
{
    InventoryRecord *new_rec;
    new_rec = malloc(sizeof(InventoryRecord));
    if (new_rec != NULL)
    {
        new_rec->info.subassy = malloc(sizeof(SubassyInfo));
        if (new_rec->info.subassy != NULL)
        {
            // get an array big enough for the parts
            new_rec->info.subassy->part = malloc(n_parts * sizeof(struct SUBASSYPART));
            if (new_rec->info.subassy->part != NULL)
            {
                // got mem, fill in fields
                new_rec->type = SUBASSY;
                new_rec->info.subassy->n_parts = n_parts;
                return new_rec;
            }
            free(new_rec->info.subassy);
        }
        free(new_rec);
    }
    return NULL;
}

InventoryRecord *create_part_record(int cost, int supplier)
{
    InventoryRecord *new_rec;
    new_rec = malloc(sizeof(InventoryRecord));
    if (new_rec != NULL)
    {
        new_rec->info.part = malloc(sizeof(PartInfo));
        if (new_rec->info.part != NULL)
        {
            // got mem, fill in fields
            new_rec->type = PART;
            new_rec->info.part->cost = cost;
            new_rec->info.part->supplier = supplier;
            return new_rec;
        }
        free(new_rec);
    }
    return NULL;
}

void discard_inventory_record(InventoryRecord *rec)
{
    switch (rec->type)
    {
    case SUBASSY:
        free(rec->info.subassy->part);
        free(rec->info.subassy);
        break;
    case PART:
        free(rec->info.part);
        break;
    default:
        printf("Unknown record type\n%s", "");
        exit(EXIT_FAILURE);
    }
    free(rec);
}
