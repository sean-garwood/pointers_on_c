#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DESC_LEN 21
#define MAXLEN 240

#define NEW_PART (Part *)malloc(sizeof(Part))

typedef struct part
{
    unsigned int part_number;
    char description[MAX_DESC_LEN];
    unsigned int quantity;
    float cost_each;
    struct part *next;
} Part;

typedef struct
{
    Part *totals;         // part num zero, grand totals
    const char *filename; // name of the file to persist data
    FILE *record;         // binary file to persist data.
} Inventory;

void init_inventory(const char *filename);
void init_part_zero();
void clear_attrs(Part *part);
void print(unsigned int part_number);
void print_all();
void prompt();

void new_part(const char *desc, unsigned int qty, float cost); // todo: handle negative cost
void buy(unsigned int part_number, unsigned int qty, float cost);
void sell(unsigned int part_number, unsigned int qty, float cost);
void delete(unsigned int part_number);

Part *find_part(unsigned int part_number);
Part *find_empty_part();
