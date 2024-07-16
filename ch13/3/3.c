/*
 * convert the following program to use a jump table instead of the switch
 * statement shown below
 */

#include "3.h"

int main(void)
{
    return jump_table_procedure();
}

// void switch_statement(void)
// {
//     Node *list;
//     Node *current;
//     Transaction *trx;

//     // ...code...

//     switch (trx->type)
//     {
//     case NEW:
//         add_new_trx(list, trx);
//         break;
//     case DELETE:
//         current = delete_trx(list, current);
//         break;
//     case FORWARD:
//         current = current->next;
//         break;
//     case BACKWARD:
//         current = current->prev;
//         break;
//     case SEARCH:
//         current = search(list, trx);
//         break;
//     case EDIT:
//         edit(current, trx);
//         break;
//     default:
//         printf("illegal\n");
//         break;
//     }
// }

int jump_table_procedure(void)
{
    Node *nodep;
    Transaction *trx;

    /*
     * instead of using if/switch statement, use a jump table
     */

    void (*jump_table[])(void *, void *) = {add_new_trx, delete_trx, forward, backward, search, edit};

    // ...code...
    /*
     * eg, if we want to add a new trx to the list, we can call the function by
     * using the NEW enum value as an index to the jump table

     */

    jump_table[trx->type](nodep, trx);
}

void add_new_trx(void *list, void *trx)
{
    // ...code...
}

Node *delete_trx(void *list, void *current)
{
    // ...code...
}

void forward(void *current, void *trx)
{
    // ...code...
}

void backward(void *current, void *trx)
{
    // ...code...
}

Node *search(void *list, void *trx)
{
    // ...code...
}

void edit(void *current, void *trx)
{
    // ...code...
}
