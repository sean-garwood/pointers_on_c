#ifndef HEADERS_H
#include "headers.h"
#endif

Part *init_part_zero(void)
{
    /*
     * 1. check if the zero part is already initialized
     *    if inv->zero is not NULL, return it
     *    else, allocate memory for the zero part
     *       if allocation fails, print an error message and exit
     *       else, initialize the zero part
     *
     */

    Part *zero;
    // check if the zero part is already initialized
    if (inv->zero != NULL)
    {
        return inv->zero;
    }
    else
    {
        zero = NEWPART(zero);
        zero->data = (PartData){0, 0, 0.0, 0.0, "HEAD"};
    }

    return zero;
}

int new_part(TrxData *data)
{
    // stub
    return 0;
}
int buy_part(TrxData *data)
{
    // stub
    return 0;
}
int sell_part(TrxData *data)
{
    // stub
    return 0;
}
int delete_part(TrxData *data)
{
    // stub
    return 0;
}
int print_one_part(TrxData *data)
{
    // stub
    return 0;
}
int print_all_parts(TrxData *data)
{
    // stub
    return 0;
}
int total_inventory(TrxData *data)
{
    // stub
    return 0;
}
int quit(TrxData *data)
{
    // stub
    return 0;
}
