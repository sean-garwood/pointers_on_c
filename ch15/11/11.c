/* Write a program to keep track of an inventory of parts and their value.

 Each part has a description that may be from 1-20 chars in length.

 When a new part is added to the inventory, it is assigned the next available
 part number.

 The first part number is 1

 The program should store the quantity on hand and the total value for each part

 the program should take a single arg from cli: name of inventory file. if it
 doesn't exist, an empty file is created.

 Prompts for trx and processes them one by one

***********************************transactions*********************************

 Following trx are allowed:
 * * * * * * * * * * * * * * * * * new * * * * * * * * * * * * * * * * * * * * *

enters part into system

subcommands: description, quantity, cost-each
 `new description,quantity,cost-each`
 `new` trx enters a new part into the system

 `description` is the part description char[20]

 `quantity` is the number of parts initially placed into inventory; it may not
 be negative. unsigned int

 `cost-each` is the cost of each part. It is not an error for a new part to have
 the same description as an existing part. unsigned float (2 decimal places)

 Compute and save total value of these parts as quantity * cost-each
    ??is casted
    to an int or a float?? Which one?? I think it should be a float. It needs to be
    a float. Will the fact that it's multiplied by quantity (unsigned int) cast
    this to an int? I think it will. I think I need to cast it to a float.

 next available part num is assigned to each new part (global unsigned int)

 nums of deleted parts are reused when new parts are entered.
    queue of deleted numbers to pop off when next new part made, then return to
    standard incrementing.

    might look like:

    if (deleted_parts == NULL) {
        part_num++;
    } else {
        part_num = deleted_parts->part_num;
        deleted_parts = deleted_parts->next;
    }

* * * * * * * * * * * * * * * * * * buy * * * * * * * * * * * * * * * * * * * *

 Adds addl units to an existing part.

 `buy part-number,quantity,cost-each`


 `part-number`: number of the part
 `quantity`: number of parts obtained
 `cost-each`: cost of each part

    should add qty and total value of new parts to the existing inventory
    cost each is updated piecemeal as new parts are added to the inventory.
       no record of trx is kept, just the inventory.


* * * * * * * * * * * * * * * * * * sell * * * * * * * * * * * * * * * * * * * *

Removes units from an existing part in inventory.

`sell part-number,quantity,price-each`


`part-number`: number of the part
`quantity`: number of parts sold
            (cant be more than quantity on hand or negative)
`price-each: price obtained for each of the parts sold.

    should subtract this qty from inv and reduce total value for this part by the
    number sold

    compute profit for the sale as the diff btween the price obtained and the
    inventory value for the parts sold.

* * * * * * * * * * * * * * * * delete  * * * * * * * * * * * * * * * * * * * *

`delete part-number` removes the part from the inventory

    should free the memory for the part and update the total value of the
    inventory.


* * * * * * * * * * * * * * * * print  * * * * * * * * * * * * * * * * * * * *

prints the part number, description, quantity on hand, and

`print part-number`


the total value of all such parts on hand.

`print all` prints all parts in the inventory in tabular form.


* * * * * * * * * * * * * * * unary commands * * * * * * * * * * * * * * * * * *

`total` computes and prints total value of all parts in inventory.
`end` ends the program

 */

#include "11.h"

int main(int argc, char *argv[])
{
    CLI_HELP(argv[0]);

    Transaction trx = {
        .post_functions = {new, buy, sell, delete, print_parts},
    };
    char trx_input[MAX_TRX_LEN]; // hold input from user to determine next trx
    init_inventory(INV_FILE);
    MAIN_LOOP(trx_input)
    {
        // parse trx_input
        // tokenize trx_input by finding first whitespace-delim word
        char *command = strtok(trx_input, " ");
        for (int i = 0; i < NUM_TRX_TYPES; i++)
        {
            if (strcmp(command, TRX_TYPES[i]) == 0)
            {

                // call appropriate function
                int (*trxp)(Part *) = trx.post_functions[i]();
                // jump table

                // print results
            }
        }

        // determine trx
        // call appropriate function
        // print results
    }
    return 0;
}

Part *new(Part *new_part)
{
    // allocate memory for new part
    Part *new_part = malloc(sizeof(Part));
    catch_null(new_part, "malloc");

    // check for empty list
    if (Inventory->head == NULL)
    {
        Inventory->head = new_part;
        return new_part;
    }

    // else, set current part to the head of the list
    Part *current_part = Inventory->head;
    Part *prev_part;
    Part *next_part;

    // find the next available part num and store in part
    new_part->num = next_available_new_part_num();

    // copy description, qty, cost_each, and total_value to new_part
    strncpy(new_part->desc, *desc, MAX_PART_DESC);
    new_part->qty = *qty;
    new_part->cost_each = *cost_each;
    new_part->total_value = *qty * *cost_each;

    // now think about how this impacts linkages
    // at this point, the list is not empty; there is at least one other part
    // therefore, new_part->prev should be find_part(new_part->num - 1)
    new_part->prev = find_part(new_part->num - 1);
    new_part->next = new_part->prev->next; // fine because we can set it to NULL
    return new_part;
}

int buy(Part *part)
{
    Part *part_to_buy = find_part(part);
    // update the following attrs of part_to_buy:
    /*
     * qty
     * cost_each (fn return)
     * total_value = qty * cost_each
     */

    // update qty
    part_to_buy->qty += *qty;
    return POST_SUCCESS;
}

int sell(unsigned int *part_num, unsigned int *qty, float *unit_price)
{
    // stub
    return POST_SUCCESS;
}

Part *delete(unsigned int *part_num)
{
    Part *part = find_part(*part_num);
    if (part == NULL)
    {
        return NULL;
    }
    if (part->prev != NULL)
    {
        part->prev->next = part->next;
    }
    if (part->next != NULL)
    {
        part->next->prev = part->prev;
    }
    free(part);
    return part;
}

void print_parts(unsigned int *part_num, ...)
{
    Part *part;
    unsigned int argc = sizeof(part_num) / sizeof(part_num[0]);

    for (int i = 0; i < argc; i++)
    {
        if (part = find_part(part_num[i]) == NULL)
        {
            printf("Part number %d not found.\n", part_num[i]);
            continue;
        }
        printf("Part number: %d\n", part->num);
        printf("Description: %s\n", part->desc);
        printf("Quantity: %d\n", part->qty);
        printf("Cost each: %.2f\n", part->cost_each);
        printf("Total value: %.2f\n", part->total_value);
    }
}

void init_inventory(const char *filename)
{
    Inventory = malloc(sizeof(Inventory));
    catch_null(Inventory, "malloc");
    Inventory->filename = filename;
    Inventory->output = fopen(filename, "wb");
    catch_null(Inventory->output, "fopen");
}

unsigned int next_avaliable_part_num()
{
    Part *part = Inventory->head;
    unsigned int part_num = part->num;

    // check if less than minimum part number
    if (part_num > FIRST_PART_NUM)
    {
        part_num = FIRST_PART_NUM;
    }
    else
    {
        while (part->next != NULL)
        {
            if (part->num + 1 != part->next->num)
            {
                return part->num + 1;
            }

            part = part->next;
        }
        part_num = part->num + 1;
    }
    return part_num;
    /*  not pretty but it should work     */
}
