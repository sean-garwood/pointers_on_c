#ifndef HEADERS_H
#include "headers.h"
#endif

// user responsible for ensuring t_argv is null-terminated
// format: "%d[ %s,%s,%s]" where enclosed brackets are optional args but
// must appear exactly as shown
// example: "p 1" -> 1
// example: "n a,2,3" -> 3
// example: "p" -> 0

// return the number of optional args in t_args
int trx_argc(const char *t_args)
{
    int trx_char = *t_args;
    int trx_len = strlen(t_args); // includes null terminator

    if (trx_char == 'n' || trx_char == 'b' || trx_char == 's')
        return 3;
    else if (trx_char == 'd' || trx_char == 'p')
    {
        if (trx_char == 'd')
            return 1;
        else
            return (trx_len > 2) ? 1 : 0;
    }
    else if (trx_char == 'q' || trx_char == 't')
        return 0;
    else
    {
        printf("bad trx_char: %c\n", trx_char);
        return -1;
    }
}

int get_trx_type(const char *t_args)
{
    int argc = trx_argc(t_args);
    switch (argc)
    {
    case 3:
        switch (*t_args)
        {
        case 'n':
            return NEW;
        case 'b':
            return BUY;
        case 's':
            return SELL;
        default:
        }
    case 1:
        switch (*t_args)
        {
        case 'd':
            return DELETE;
        case 'p':
            return (argc == 1) ? PRINT_ALL : PRINT_ONE;
        default:
        }
    case 0:
        switch (*t_args)
        {
        case 'q':
            return QUIT;
        case 't':
            return TOTAL;
        default:
            printf("bad trx_char: %c\n", *t_args);
            break;
        }
    }

    return -1;
}

void set_trx_data(Trx *trx, const char *input)
{
    // parse the comma-seaparated args in place
    int type = trx->type;
    TrxData *data = &trx->trx_data;
    char *args = input + 2; // skip the command and space

    // write the data to the appropriate struct
    switch (type)
    {
    case NEW:
        data->new.id = get_id();
        data->new.desc = strtok(args, ",");
        data->new.qty = atoi(strtok(NULL, ","));
        data->new.unit_cost = atof(strtok(NULL, ","));
        break;
    case BUY:
        data->buy.id = atoi(strtok(args, ","));
        data->buy.qty = atoi(strtok(NULL, ","));
        data->buy.unit_cost = atof(strtok(NULL, ","));
        break;
    case SELL:
        data->sell.id = atoi(strtok(args, ","));
        data->sell.qty = atoi(strtok(NULL, ","));
        data->sell.unit_price = atof(strtok(NULL, ","));
        break;
    case DELETE:
        data->delete.id = atoi(args);
        break;
    case PRINT_ONE:
        data->print_one.id = atoi(args);
        break;
    case PRINT_ALL:
    case TOTAL:
    case QUIT:
        break;
    }
}

Trx *new_trx(const char *t_args)
{
    static int(*ops[]) = TRXOPS;
    Trx *trx = MALLOCTRX(trx);
    char *command = *t_args;
    trx->type = get_trx_type(t_args);
    set_trx_data(trx->type, t_args);
    trx->op = ops[trx->type];
    return trx;
}

/* callbacks/operations */
int new_part(Trx *trx)
{
    TrxData *t_data = &trx->trx_data;
    Part *p = MALLOCPART(p);

    p->data.id = t_data->new.id;
    p->data.qty = t_data->new.qty;
    p->data.unit_cost = t_data->new.unit_cost;
    strcpy(p->data.desc, t_data->new.desc);
    return SUCCESS;
}

int buy_part(Trx *trx)
{
    TrxData *t_data = &trx->trx_data;
    Part *p = find_part(t_data->buy.id);
    if (p == NULL)
    {
        printf("Part not found.\n");
        return FAILURE;
    }
    unsigned int old_qty = p->data.qty;
    float old_cost = p->data.unit_cost;
    p->data.qty += t_data->buy.qty;
    p->data.unit_cost = (old_qty * old_cost + t_data->buy.qty * t_data->buy.unit_cost) / p->data.qty;
    return SUCCESS;
}

int sell_part(Trx *trx)
{
    TrxData *t_data = &trx->trx_data;
    Part *p = find_part(t_data->sell.id);
    if (p == NULL)
    {
        printf("Part not found.\n");
        return FAILURE;
    }
    else if (p->data.qty < t_data->sell.qty)
    {
        printf("Not enough stock.\n");
        return FAILURE;
    }
    else
    {
        unsigned int old_qty = p->data.qty;
        float old_price = p->data.unit_price;
        p->data.qty -= t_data->sell.qty;
        p->data.unit_price = (old_qty * old_price + t_data->sell.qty * t_data->sell.unit_price) / p->data.qty;
    }
    return SUCCESS;
}

int delete_part(Trx *trx)
{
    TrxData *t_data = &trx->trx_data;
    Part *p = find_part(t_data->delete.id);
    if (p == NULL)
    {
        printf("Part not found.\n");
        return FAILURE;
    }

    p->data.desc[0] = '\0';
    p->data.qty = 0;
    p->data.unit_cost = 0;
    p->data.unit_price = 0;
    return SUCCESS;
}

int print_one_part(Trx *trx)
{
    TrxData *t_data = &trx->trx_data;
    Part *current = inv->zero;
    while (current != NULL)
    {
        if (current->data.id == t_data->print_one.id)
        {
            print_part_data(current);
            return SUCCESS;
        }
        current = current->next;
    }
    return FAILURE;
}

int print_all_parts(Trx *trx)
{
    Part *current = inv->zero;
    while (current != NULL)
    {
        print_part_data(current);
        current = current->next;
    }
    return SUCCESS;
}

int total_inventory(Trx *trx)
{
    unsigned int total_qty = 0;
    float total_cost = 0;
    float total_price = 0;
    Part *current = inv->zero;

    while (current != NULL)
    {
        total_qty += current->data.qty;
        total_cost += current->data.qty * current->data.unit_cost;
        total_price += current->data.qty * current->data.unit_price;
        current = current->next;
    }
    return SUCCESS;
}

int quit(Trx *trx)
{
    return SUCCESS;
}
