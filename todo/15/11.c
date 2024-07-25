#include "11.h"

// inventory should be globally accessible to avoid having to pass it as an arg
// to all the fns that need it

Part *totals;
Inventory *inv;

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    puts("welcome!");

    const char *filename = argv[1];
    // check if the file exists
    FILE *file = fopen(argv[1], "rb+");
    if (file == NULL)
    {
        file = fopen(argv[1], "wb+");
        if (file == NULL)
        {
            perror("Error opening file");
            return 1;
        }
    }

    puts("file opened");
    prompt();
    init_inventory(filename);
    inv->record = file;

    // setup is complete
    // enter the main loop where user is prompted for inputs to read/modify
    // inventory and parts
    //      see ./spec.md for details

    char input[MAXLEN];
    int first_letter_of_input;

    // before processing the input, we ought to first parse it to see what is
    // being requested

    // the `input` is the first word in the input, so we can scan input for
    // all the chars until we hit a space or newline

    int repl = 1;
    while (repl) // todo: guard for 'end'
    {
        if (fgets(input, MAXLEN, stdin) == NULL)
        {
            printf("Error reading input\n");
            continue;
        }
        first_letter_of_input = input[0];
        if ((first_letter_of_input) == 'e')
            break;

        switch (first_letter_of_input)
        {
        case ('n'):
            // add a new part to inventory

            // initialize a part
            /*
             * 1. description
             * 2. quantity
             * 3. cost-each
             */

            //
            new_part("description", 0, 0.0);
            break;
        case ('b'):
            // buy a part
            break;
        case ('s'):
            sell(0, 0, 0.0);
            // sell a part
            break;
        case ('d'):
            // delete a part
            break;
        case ('p'):
            // print a part
            break;
        default:
            printf("Invalid input\n");
            break;
        }
    }

    // cleanup
    fwrite(inv->totals, sizeof(Part), 1, inv->record);
    fclose(inv->record);
    free(inv);

    return 0;
}

void new_part(const char *desc, unsigned int qty, float cost)
{
    Part *new_part = NEW_PART;
    if (new_part == NULL)
    {
        perror("Error allocating memory for new part");
        fclose(inv->record);
        exit(EXIT_FAILURE);
    }

    Part *last = find_empty_part() + sizeof(Part);
    new_part->part_number = last->part_number + 1;
    new_part->quantity = qty;
    new_part->cost_each = cost;

    strncpy(new_part->description, desc, MAX_DESC_LEN);

    new_part->cost_each = qty * cost;
}

void buy(unsigned int part_number, unsigned int qty, float cost)
{
    Part *current = inv->totals;
    while (current->part_number != part_number &&
           (current->next) != NULL)
        current = current->next;

    if (current->part_number != part_number)
    {
        printf("Part number %d not found\n", part_number);
    }

    current->quantity += qty;

    current->cost_each = (current->cost_each + (qty * cost)) / current->quantity;
}

void sell(unsigned int part_number, unsigned int qty, float price)
{
    Part *target = find_part(part_number);

    int num_not_found = target->part_number != part_number;
    int qty_not_enough = target->quantity < qty;

    if (num_not_found || qty_not_enough)
    {
        char *msg = num_not_found ? "part number" : "insufficient quantity";
        puts(msg);
    }

    target->quantity -= qty;
    target->cost_each = (target->cost_each - (qty * price)) / target->quantity;
}

void delete(unsigned int part_number)
{
    Part *target = find_part(part_number);
    if (target->part_number != part_number || target == NULL)
        printf("Part number %d not found\n", part_number);

    clear_attrs(target);
}

void print(unsigned int part_number)
{
    Part *target = find_part(part_number);
    if (target->part_number != part_number || target == NULL)
        printf("Part number %d not found\n", part_number);

    printf("Part number: %d\n\
            Description: %s\n\
            Quantity: %d\n\
            Cost each: %.2f\n\
            Total cost: %.2f\n",
           target->part_number, target->description, target->quantity,
           target->cost_each, target->quantity * target->cost_each);
}

void print_all()
{
    Part *current = inv->totals;
    while (current != NULL)
    {
        print(current->part_number);
        current = current->next;
    }
}

Part *find_part(unsigned int part_number)
{
    Part *current = inv->totals;
    while (current->part_number != part_number &&
           (current->next) != NULL)
        current = current->next;

    if (current->part_number != part_number)
    {
        printf("Part number %d not found\n", part_number);
        return NULL;
    }

    return current;
}

Part *find_empty_part()
{
    Part *current = inv->totals;
    while ((current->description != NULL) &&
           (current->next != NULL))
        current = current->next;

    return current;
}

void init_inventory(const char *filename)
{

    inv = (Inventory *)malloc(sizeof(Inventory));
    if (inv == NULL)
    {
        perror("Error allocating memory for inventory");
        exit(EXIT_FAILURE);
    }

    inv->totals = totals;
    inv->filename = filename;
    inv->record = fopen(filename, "rb+");

    init_part_zero();
}

void init_part_zero()
{
    Part *part_zero = NEW_PART;
    if (part_zero == NULL)
    {
        perror("Error allocating memory for part zero");
        fclose(inv->record);
        exit(EXIT_FAILURE);
    }

    part_zero->part_number = 0;
    part_zero->quantity = 0;
    part_zero->cost_each = 0.0;
    part_zero->next = NULL;
    inv->totals = part_zero;
}

void prompt()
{
    printf("Enter input:\n\
            new - new part\n\
            add - add to quantity of an existing part\n\
            buy - buy a part\n\
            sell - sell a part\n\
            delete - delete a part\n\
            print - print a part\n\
            end - exit\n");
}

void clear_attrs(Part *part)
{
    part->part_number = 0;
    part->quantity = 0;
    part->cost_each = 0.0;
}

/*
 * big todo: update the total cost of inventory when buy/sell/delete parts or
 * add new
 *
 * other todo: write data to output file
 */
