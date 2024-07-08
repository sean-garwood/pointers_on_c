#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PARTNO_SIZE 10
#define MAXPARTS 100

typedef struct
{
    int cost;
    int supplier;
    // ...
} PartInfo;

typedef struct
{
    int n_parts;
    struct SUBASSYPART
    {
        char partno[PARTNO_SIZE];
        short quan;
    } *part;
} SubassyInfo;

typedef struct
{
    char partno[PARTNO_SIZE];
    int quan;
    enum
    {
        PART,
        SUBASSY
    } type;
    union
    {
        PartInfo *part;
        SubassyInfo *subassy;
    } info;
} InventoryRecord;

InventoryRecord *create_subassy_record(int n_parts);
InventoryRecord *create_part_record(int cost, int supplier);
void discard_inventory_record(InventoryRecord *rec);
