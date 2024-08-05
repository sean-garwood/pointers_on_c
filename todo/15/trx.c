#ifndef HEADERS_H
#include "headers.h"
#endif

/*
 * the following tasks are to be done by the functions in this file
 * parse stdin input into separate pieces: command, args
 * assume the stdin is clean and will always follow the form "<command>[
 * <arg1>,<arg2>,<arg3>]", where args are optional
 * determine the type of the command
 */

TrxType set_trx_type(const char *input)
{
    int command_char; // command_char is the first character of the command
    int seventh_char; // seventh_char is the seventh character of the input

    if ((command_char = tolower(*input)) == 'p')
        return ((seventh_char = tolower(*(input + 6))) == 'o') ? PRINT_ONE : PRINT_ALL;

    switch (command_char)
    {
    case 'n':
        return NEW;
    case 'b':
        return BUY;
    case 's':
        return SELL;
    case 'd':
        return DELETE;
    case 't':
        return TOTAL;
    case 'q':
        return QUIT;
    default:
        printf("Invalid command: %c\n***YOU'RE ON YOUR OWN!***", command_char);
        return -1;
    }
}

const char **get_args(TrxType trx_type, const char *rest_of_input)
{
    if (trx_type >= PRINT_ALL)
        return NULL;

    int array_size; // depends on trx_type
                    // todo: make own fn
    char *arg;

    if (trx_type <= SELL)
        array_size = 3;
    else if (trx_type <= DELETE && trx_type >= NEW)
        array_size = 1;

    char *args[array_size];

    for (int i = 0; i < array_size; i++)
    {
        // store the word before the comma into arg
        arg = strtok((char *)rest_of_input, ",");
        args[i] = arg;
    }

    return args; // compiler warning: returns address of local variable
                 // todo: fix this by writing a void fn that modifies an external array
                 // by reference, eg void get_args(TrxType trx_type, const char *rest_of_input, char **args)
}

TrxData set_trx_data(Trx *trx, const char **args)
{
    switch (trx->type)
    {
    case NEW:
        trx->data.new.desc = args[0];
        trx->data.new.qty = atoi(args[1]);
        trx->data.new.unit_cost = atof(args[2]);
        break;
    case BUY:
        trx->data.buy.id = atoi(args[0]);
        trx->data.buy.qty = atoi(args[1]);
        trx->data.buy.unit_cost = atof(args[2]);
        break;
    case SELL:
        trx->data.sell.id = atoi(args[0]);
        trx->data.sell.qty = atoi(args[1]);
        trx->data.sell.unit_price = atof(args[2]);
        break;
    case DELETE:
        trx->data.delete.id = atoi(args[0]);
        break;
    case PRINT_ONE:
        trx->data.print_one.id = atoi(args[0]);
        break;
    default:
        break;
    }

    return trx->data;
}

Trx init_trx(const char *command, const char **args)
{
    // initialize an array of function pointers using TRXOPS
    static int (*trx_ops[])(TrxData *) = TRXOPS;
    Trx *trx = NEWTRX(trx);

    trx->type = set_trx_type(command);
    trx->data = set_trx_data(trx, args);
    trx->op = trx_ops[trx->type];
    return *trx;
}
