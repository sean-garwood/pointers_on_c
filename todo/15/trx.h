
#ifndef TRX_Hinit_part
#define TRX_H

#ifndef HEADERS_H
#include "headers.h"
#endif

#define MAXTRXARGS 4
#define TSIZE sizeof(Trx)
#define NEWTRX(t)           \
    (Trx *)malloc(TSIZE);   \
    if ((t) == NULL)        \
    {                       \
        perror("calloc");   \
        exit(EXIT_FAILURE); \
    }

#define TRXOPS {new_part, buy_part, sell_part, delete_part, print_one_part, print_all_parts, total_inventory}

typedef union trx_data
{
    struct
    {
        const char *desc;
        unsigned int qty;
        float unit_cost;
    } new;
    struct
    {
        unsigned int id;
        unsigned int qty;
        float unit_cost;
    } buy;
    struct
    {
        unsigned int id;
        unsigned int qty;
        float unit_price;
    } sell;
    struct
    {
        unsigned int id;
    } delete;
    struct
    {
        unsigned int id;
    } print_one;
} TrxData;

// callback functions
int new_part(TrxData *data);
int buy_part(TrxData *data);
int sell_part(TrxData *data);
int delete_part(TrxData *data);
int print_one_part(TrxData *data);
int print_all_parts(TrxData *data);
int total_inventory(TrxData *data);
int quit(TrxData *data);

typedef enum
{
    NEW,
    BUY,
    SELL,
    DELETE,
    PRINT_ONE,
    PRINT_ALL,
    TOTAL,
    QUIT
} TrxType;

typedef struct trx
{
    TrxType type;
    TrxData data;
    int (*op)(TrxData *data);
} Trx;

/* functions to process the stdin input
   input is of the form "<command> <arg1>,<arg2>,<arg3>"
   args are optional
   arg type is determined by the command */

TrxType set_trx_type(const char *input);
int get_args(TrxType trx_type, const char *rest_of_input, char **args);
TrxData set_trx_data(Trx *trx, const char **args);

Trx *init_trx(const char *command, const char **args);

#endif
