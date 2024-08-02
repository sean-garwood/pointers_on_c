#define HEADERS_H

#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARGCHECK(x)                      \
    if ((x) != 2)                        \
    {                                    \
        puts("Usage: ./inv <filename>"); \
        return EXIT_FAILURE;             \
    }
#define SUCCESS 0
#define FAILURE 1
#define TRUE 1
#define FALSE 0
#define MAXDESC 21
#define BUFSIZE 21

#define CONT(buffer) ((fgets((buffer), BUFSIZE, stdin) != NULL) && ((buffer)[0] != 'e'))
typedef struct part
{
    unsigned int id;
    unsigned int qty;
    float unit_cost;
    float unit_price;
    char desc[MAXDESC];
    struct part *next;
} Part;

typedef struct
{
    Part *part_zero; // head of the list
    FILE *output;    // binary data file to read/write inventory data
    struct
    {
        unsigned int num_parts;
        unsigned int num_items;
        float total_cost;
        float total_value;
    } totals;
} Inventory;

int inv_exists(const char *filename);
void new_inv(Inventory *inv, FILE *output);

Part *find_part(Inventory *inv, unsigned int part_num);
Part *create_part_zero();
unsigned int get_part_id(Inventory *inv);

int new_part(Inventory *inv, const char *desc, unsigned int qty,
             float unit_cost);
int buy_part(Inventory *inv, unsigned int part_num, unsigned int qty,
             float unit_cost);
int sell_part(Inventory *inv, unsigned int part_num, unsigned int qty,
              float unit_price);
int delete_part(Inventory *inv, unsigned int part_num);
int print_part(Inventory *inv, unsigned int part_num);
int print_all(Inventory *inv);
int print_totals(Inventory *inv);
int update_totals(Inventory *inv);

void write_to_bin(Inventory *inv);
void free_memory(Inventory *inv);
int byebye(Inventory *inv, const char *filename);
