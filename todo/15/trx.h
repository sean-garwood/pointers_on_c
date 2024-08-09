#ifndef TRX_H
#define TRX_H

#ifndef HEADERS_H
#include "headers.h"
#endif

#define MAXTRXARGS 4
#define TSIZE sizeof(Trx)
#define MALLOCTRX(t)        \
    (Trx *)malloc(TSIZE);   \
    if ((t) == NULL)        \
    {                       \
        perror("calloc");   \
        exit(EXIT_FAILURE); \
    }
#define MALLOCTRXDATA(td)               \
    (TrxData *)malloc(sizeof(TrxData)); \
    if ((td) == NULL)                   \
    {                                   \
        perror("calloc");               \
        exit(EXIT_FAILURE);             \
    }

typedef union trx_data
{
    struct
    {
        unsigned int id;
        unsigned int qty;
        float unit_cost;
        const char *desc;
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
    struct
    {
    } print_all;
    struct
    {
    } total;
    struct
    {
    } quit;
} TrxData;

typedef struct trx
{
    char *args; // string of comma-separated args
    enum
    {
        NEW,       // 3 args
        BUY,       // 3 args
        SELL,      // 3 args
        DELETE,    // 1 arg
        PRINT_ONE, // 1 arg
        PRINT_ALL, // 0 args
        TOTAL,     // 0 args
        QUIT       // 0 args
    } type;
    TrxData t_data;
    int (*op)(struct trx *trx);
} Trx;

int get_trx_type(const char *t_args);
void set_trx_data(Trx *trx, const char *input);
Trx *new_trx(const char *t_args);
int process_trx(Trx *trx, const char *t_args);

// callback functions
int new_part(Trx *trx);
int buy_part(Trx *trx);
int sell_part(Trx *trx);
int delete_part(Trx *trx);
int print_one(Trx *trx);
int print_all_parts(Trx *trx);
int total_inventory(Trx *trx);
int quit(Trx *trx);

#define TRXOPS ({new_part, buy_part, sell_part, delete_part, print_one_part, print_all_parts, total_inventory})
#endif
