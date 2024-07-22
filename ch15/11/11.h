#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// flags
#define MAX_PART_DESC 20
#define MAX_TRX_LEN 240
#define FIRST_PART_NUM 1
#define NUM_TRX_TYPES 5
#define POST_SUCCESS 0 // return value of int functions on success
#define REQ_CLI_ARGS_DONT_EXIST argc != 2

// strings
#define ALL_PARTS "*" // arg to pass print_parts
#define INV_FILE argv[1]

#define NEW "new" // trx types
#define BUY "buy"
#define SELL "sell"
#define DELETE "delete"
#define PRINT "print"
// procedures
#define CLI_HELP(program)                                         \
    if (REQ_CLI_ARGS_DONT_EXIST)                                  \
    {                                                             \
        fprintf(stderr, "Usage: %s <inventory file>\n", program); \
        exit(EXIT_FAILURE);                                       \
    }

#define MAIN_LOOP(trx)                               \
    while (fgets(trx, MAX_TRX_LEN, stdin) != NULL && \
           strcmp(trx, "end\n") != 0)

#define catch_null(objp, msg)          \
    if ((objp) == NULL)                \
                                       \
    {                                  \
        perror(((const char *)(msg))); \
        exit(EXIT_FAILURE);            \
    }

int new(Part *part);
int buy(Part *part);
int sell(Part *part);
int delete(Part *part);
int print(Part *part);

// helpers
void init_inventory(const char *filename);
Part *find_part(unsigned int num);
unsigned int next_available_part_num(void); // use global Inventory to walk through parts

typedef struct part
{
    unsigned int num;
    char desc[MAX_PART_DESC];
    unsigned int qty;
    float cost_each;
    float total_value;
    struct part *next; // ordered doubly linked list
    struct part *prev;
} Part;

extern struct inventory
{
    Part *head;     // pointer to head of doubly linked list
    char *filename; // name of file to read/write
    FILE *output;   // pointer to output, which is a binary file
} *Inventory;

/*
 * Not sure what to do with the trx.
 *
 * I want a jump table of functions that will be called based on the first token
 * of the input string from the main loop.
 *
 *
 */

typedef struct transaction
{
    // type of transaction
    // union of function pointers
    // new, buy, sell, delete, print, print_parts
    union type
    {
        char *type;
        int (*function)(Part *part);
    };
    int (*post_functions[6])(Part *part);
} Transaction;

extern Transaction trx;

static const char *TRX_TYPES[] = {NEW, BUY, SELL, DELETE, PRINT};
/*
 * transactions will be the first token of the input string after program
 * initialization and while in the main loop. The transaction will determine
 * the next action to take.

 * each action will be a function, so the transaction will be a function pointer
 * to the appropriate function.

 * this calls for a jump table!

    * the transaction will be a struct with a type and a union of function
 *    pointers

 */
