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

    if ((command_char = tolower(*input)) == 'p')
    {
        // check if there are more characters in the command
        if (strlen(input) <= 2 && (*(input + 1) == '\0'))
        {
            return PRINT_ALL;
        }
        else
        {
            return PRINT_ONE;
        }
    }

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

// parse the rest of the input, store in args
int get_args(TrxType trx_type, const char *rest_of_input, char **args)
{
    size_t argc;
    if (trx_type >= PRINT_ALL && trx_type >= NEW)
    {
        args = NULL;
        return SUCCESS;
    }
    else if (trx_type <= SELL)
        argc = 3;
    else if (trx_type <= DELETE)
        argc = 1;
    else
        return FAILURE;

    char *temp = strdup(rest_of_input);
    char *token = strtok(temp, ",");
    for (size_t i = 0; i < argc; i++)
    {
        if (token == NULL)
        {
            break;
        }
        *(args + i) = token;
        token = strtok(NULL, ",");
    }

    return SUCCESS;
}

TrxData set_trx_data(Trx *trx, char **args)
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

Trx *init_trx(TrxType trx_t, char **args)
{
    // initialize an array of function pointers using TRXOPS
    static int (*trx_ops[])(TrxData *) = TRXOPS;
    Trx *trx = NEWTRX(trx);

    trx->type = trx_t;
    trx->data = set_trx_data(trx, args);
    trx->op = trx_ops[trx_t];
    return trx;
}
