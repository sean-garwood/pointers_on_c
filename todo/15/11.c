#include "11.h"

// inventory should be globally accessible to avoid having to pass it as an arg
// to all the fns that need it

Part *totals = NULL;
Inventory *inv = NULL;

int main(int argc, char *argv[])
{

    if (check_args(argc, argv))
        exit(EXIT_FAILURE);

    const char *filename = argv[1];
    char *args[MAXARGS];
    char input[MAXLEN];
    char this_input[MAXLEN];
    int first_letter_of_input;
    unsigned int part_number, qty;
    float cost;
    int repl = 1;

    init_inventory(filename);

    while (repl)
    {
        prompt();
        if (fgets(input, MAXLEN, stdin) == NULL)
        {
            printf("Error reading input\n");
            continue;
        }

        strcpy(this_input, input);

        char *rest_of_input = strchr(this_input, ' ');

        if (rest_of_input != NULL)
        {
            // split the rest of the input by commas
            char *token = strtok(rest_of_input, ",");
            int arg_index = 0;
            while (token != NULL)
            {
                args[arg_index++] = token;
                token = strtok(NULL, ",");
            }
        }

        const char *desc = args[0];
        part_number = atoi(args[0]);
        qty = atoi(args[1]);
        cost = atof(args[2]);
        switch (first_letter_of_input = input[0])
        {
        case ('n'):
            if (desc == NULL || qty == 0 || cost == 0.0)
            {
                printf("Invalid input\n");
                break;
            }
            new_part(desc, qty, cost);
            break;
        case ('b'):
            if (desc == NULL || qty == 0 || cost == 0.0)
            {
                printf("Invalid input\n");
                break;
            }
            buy(part_number, qty, cost);
            break;
        case ('s'):
            if (desc == NULL || qty == 0 || cost == 0.0)
            {
                printf("Invalid input\n");
                break;
            }
            sell(part_number, qty, cost);
            break;
        case ('d'):
            if (desc == NULL)
            {
                printf("Invalid input\n");
                break;
            }
            del(part_number);
            break;
        case ('p'):
            if (desc == NULL)
            {
                printf("Invalid input\n");
                break;
            }
            (strcmp(desc, "all") == 0) ? print_all() : print(part_number);
            break;
        case ('e'):
            repl = 0;
            break;
        case ('t'):
            total();
            break;
        default:
            printf("Invalid input\n");
            break;
        }
    }

    close_inventory();
    puts("Goodbye!");
    return 0;
}

int check_args(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    puts("welcome!");
    return 0;
}

void new_part(const char *desc, unsigned int qty, float cost)
{
    unsigned int new_part_number;
    Part *part_before_new;
    Part *part_after_new;
    Part *new_part = NEW_PART;

    if (new_part == NULL)
    {
        perror("Error allocating memory for new part");
        exit(EXIT_FAILURE);
    }

    part_before_new = (find_empty_part() == NULL) ? inv->totals : find_empty_part();

    new_part_number = part_before_new->part_number + 1;
    part_before_new->next = new_part;
    part_after_new = find_part(new_part_number + 1);
    new_part->next = part_after_new;
    new_part->part_number = new_part_number;
    new_part->quantity = qty;
    new_part->cost_each = cost;

    strncpy(new_part->description, desc, MAX_DESC_LEN - 1);
    new_part->description[MAX_DESC_LEN - 1] = '\0';
}

void buy(unsigned int part_number, unsigned int qty, float cost)
{
    Part *to_buy;

    if ((to_buy = find_part(part_number)) == NULL)
    {
        printf("Part number %d not found\n", part_number);
        return;
    }

    float avg_cost;
    avg_cost = // unit cost times quantity plus new cost times new quantity
        ((to_buy->cost_each * to_buy->quantity) + (cost * qty)) /
        (to_buy->quantity + qty);
    to_buy->cost_each = avg_cost;
    to_buy->quantity += qty;
    // write to output
    printf("Bought %d units of part number %d\n", qty, part_number);
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
        return;
    }

    target->quantity -= qty;
    target->cost_each = (target->cost_each - (qty * price)) / target->quantity;
}

void del(unsigned int part_number)
{
    Part *target = find_part(part_number);
    if (target->part_number != part_number || target == NULL)
        printf("Part number %d not found\n", part_number);
    else
        clear_attrs(target);
}

void print(unsigned int part_number)
{
    Part *target = NEW_PART;
    if (target == NULL)
    {
        perror("Error allocating memory for target");
        exit(EXIT_FAILURE);
    }
    target = find_part(part_number);
    if (target->part_number != part_number || target == NULL)
    {
        printf("Part number %d not found\n", part_number);
        return;
    }

    printf("Part number: %d\n\
            Description: %s\n\
            Quantity: %d\n\
            Cost each: %.2f\n",
           target->part_number, target->description, target->quantity,
           target->cost_each);
}

void print_all()
{
    Part *current = inv->totals;
    while (current != NULL)
    {
        printf("Part number: %d\n\
                Description: %s\n\
                Quantity: %d\n\
                Cost each: %.2f\n\
                Total cost: %.2f\n",
               current->part_number, current->description, current->quantity,
               current->cost_each, current->quantity * current->cost_each);
        current = current->next;
    }
}

Part *find_part(unsigned int part_number)
{
    Part *current = inv->totals;
    while (current != NULL)
    {
        if (current->part_number == part_number)
            return current;
        current = current->next;
    }

    return NULL;
}

Part *find_empty_part()
{
    Part *current = inv->totals;
    while ((current->description[0] != '\0') &&
           (current->next != NULL))
        current = current->next;

    return current;
}

void init_inventory(const char *filename)
{

    FILE *file;

    if ((file = fopen(filename, "rb+")) == NULL) // does the file exist?
    {
        printf("File not found, creating new file\n");
        file = fopen(filename, "wb+"); // if not, create it
        if (file == NULL)
        {
            perror("Error opening file");
            exit(EXIT_FAILURE);
        }
    }
    printf("File %s opened for writing\n", filename);

    inv = (Inventory *)malloc(sizeof(Inventory));
    if (inv == NULL)
    {
        perror("Error allocating memory for inventory");
        exit(EXIT_FAILURE);
    }
    inv->filename = filename;
    inv->record = file;

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
    strcpy(part_zero->description, "Grand Totals\0");
    part_zero->quantity = 0;
    part_zero->cost_each = 0.0;
    part_zero->next = NULL;

    inv->totals = part_zero;
}

void prompt()
{
    printf("Enter input:\n\
            new - new part\n\
            buy - buy a part\n\
            sell - sell a part\n\
            delete - delete a part\n\
            print - print a part\n\
            total - print total quantity and cost\n\
            end - exit\n");
}

void clear_attrs(Part *part)
{
    part->part_number = 0;
    part->description[0] = '\0';
    part->quantity = 0;
    part->cost_each = 0.0;
}

void close_inventory()
{
    Part *current = inv->totals;
    Part *last;
    Part *next;

    size_t part_num = 0;
    while (current != NULL)
    {
        fwrite(current, sizeof(Part), 1, inv->record + part_num++);
        next = current->next;
        last = current;
        free(last); // free memory so safe exit occurs
        current = next;
    }
    fclose(inv->record);
    free(inv);
}

void total()
{
    printf("Total quantity: %d\nTotal cost: %.2f\n",
           total_quantity(), total_cost());
}

float total_cost()
{
    float total = 0.0;

    for (Part *current = inv->totals->next; current != NULL; current = current->next)
    {
        total += current->quantity * current->cost_each;
    }

    return total;
}

unsigned int total_quantity()
{
    unsigned int total = 0;

    for (Part *current = inv->totals->next; current != NULL; current = current->next)
    {
        total += current->quantity;
    }

    return total;
}
