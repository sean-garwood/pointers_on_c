#ifndef HEADERS_H
#include "headers.h"
#endif

// user responsible for ensuring t_argv is null-terminated
// format: "%d[ %s,%s,%s]" where enclosed brackets are optional args but
// must appear exactly as shown
// example: "p 1" -> 1
// example: "n a,2,3" -> 3

int get_trx_type(const char *t_argv)
{
    switch (t_argv[0])
    {
    case 'n':
        return NEW;
    case 'b':
        return BUY;
    case 's':
        return SELL;
    case 'd':
        return DELETE;
    case 'p':
        return (strlen(t_argv) > 2) ? PRINT_ONE : PRINT_ALL;
    case 't':
        return TOTAL;
    case 'q':
        return QUIT;
    default:
        return -1;
    }
}

void set_trx_data(Trx *trx, const char *input)
{
    int type = trx->type;
    char *args = malloc(strlen(input) - 1); // skip the command and space
    strcpy(args, input + 2);                // ...
    args[strlen(args) - 1] = '\0';          // remove the newline

    // write the data to the appropriate struct
    switch (type)
    {
    case NEW:
        trx->t_data.new.id = get_id();
        trx->t_data.new.desc = strtok(args, ",");
        trx->t_data.new.qty = atoi(strtok(NULL, ","));
        trx->t_data.new.unit_cost = atof(strtok(NULL, ","));
        break;
    case BUY:
        trx->t_data.buy.id = atoi(strtok(args, ","));
        trx->t_data.buy.qty = atoi(strtok(NULL, ","));
        trx->t_data.buy.unit_cost = atof(strtok(NULL, ","));
        break;
    case SELL:
        trx->t_data.sell.id = atoi(strtok(args, ","));
        trx->t_data.sell.qty = atoi(strtok(NULL, ","));
        trx->t_data.sell.unit_price = atof(strtok(NULL, ","));
        break;
    case DELETE:
        trx->t_data.delete.id = atoi(args);
        break;
    case PRINT_ONE:
        trx->t_data.print_one.id = atoi(args);
        break;
    case PRINT_ALL:
    case TOTAL:
    case QUIT:
        break;
    }
}

int process_trx(Trx *trx, const char *t_args)
{
    // function pointers to callbacks
    static int (*ops[])(Trx *trx) = {new_part, buy_part, sell_part, delete_part, print_one, print_all_parts, total_inventory, quit};

    trx->type = get_trx_type(t_args);
    set_trx_data(trx, t_args);
    trx->op = ops[trx->type];
    return trx->op(trx);
}

/* callbacks/operations */

int new_part(Trx *trx)
{

    unsigned int part_id = trx->t_data.new.id;
    Part *p;
    Part *curr = inv->zero;

    while (curr->next != NULL && curr->data.id != part_id)
    {
        curr = curr->next;
    }

    if (curr->data.id == part_id)
    {
        printf("Part already exists.\nOverwriting data...");
        curr->data.qty = trx->t_data.new.qty;
        curr->data.unit_cost = trx->t_data.new.unit_cost;
        strcpy(curr->data.desc, trx->t_data.new.desc);
        return SUCCESS;
    }

    p = MALLOCPART(p);

    p->data.id = trx->t_data.new.id;
    p->data.qty = trx->t_data.new.qty;
    p->data.unit_cost = trx->t_data.new.unit_cost;
    strcpy(p->data.desc, trx->t_data.new.desc);
    curr->next = p;

    return SUCCESS;
}

int buy_part(Trx *trx)
{

    unsigned int old_qty, id;
    float old_cost;
    id = trx->t_data.buy.id;
    Part *p = find_part(id);

    if (p == NULL)
    {
        printf("Part not found.\n");
        return FAILURE;
    }

    old_qty = p->data.qty;
    old_cost = p->data.unit_cost;
    p->data.qty = trx->t_data.buy.qty + old_qty;
    p->data.unit_cost = (old_qty * old_cost +
                         trx->t_data.buy.qty * trx->t_data.buy.unit_cost) /
                        p->data.qty;
    return SUCCESS;
}

int sell_part(Trx *trx)
{
    unsigned int old_qty, qty_to_sell;
    float old_price, new_price;
    Part *to_sell = find_part(trx->t_data.sell.id);

    old_qty = to_sell->data.qty;
    qty_to_sell = trx->t_data.sell.qty;
    old_price = to_sell->data.unit_price;
    new_price = trx->t_data.sell.unit_price;

    if (to_sell == NULL)
    {
        printf("Part not found.\n");
        return FAILURE;
    }
    else if (old_qty < qty_to_sell)
    {
        printf("Not enough stock.\n");
        return FAILURE;
    }
    else
    {
        to_sell->data.qty -= qty_to_sell;
        to_sell->data.unit_price = (old_qty * old_price + qty_to_sell * new_price) / to_sell->data.qty;
    }
    return SUCCESS;
}

int delete_part(Trx *trx)
{

    unsigned int target_id = trx->t_data.delete.id;
    Part *p = find_part(target_id);

    if (p == NULL)
    {
        printf("Part not found.\n");
        return FAILURE;
    }
    else if (target_id == 0)
    {
        printf("Cannot delete head.\n");
        return FAILURE;
    }
    else
    {
        p->data.desc[0] = '\0';
        p->data.qty = 0;
        p->data.unit_cost = 0;
        p->data.unit_price = 0;
    }
    return SUCCESS;
}

int print_one(Trx *trx)
{

    Part *current = inv->zero;
    while (current != NULL)
    {
        if (current->data.id == trx->t_data.print_one.id)
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
    Part *current = inv->zero->next;

    unsigned int types, qty_oh;
    float cost, price;
    types = qty_oh = 0;
    cost = price = 0.0;
    while (current != NULL && current->data.desc[0] != '\0')
    {
        types++;
        qty_oh += current->data.qty;
        cost += (current->data.unit_cost * current->data.qty);
        price += (current->data.unit_price * current->data.qty);
        current = current->next;
    }
    printf("Total parts: %u\n", types);
    printf("Total quantity: %u\n", qty_oh);
    printf("Total cost: %.2f\n", cost);
    printf("Total price: %.2f\n", price);
    return SUCCESS;
}

int quit(Trx *trx)
{
    return FAILURE; // set result to FAILURE to exit loop
}
