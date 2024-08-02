#ifndef HEADERS_H
#include "headers.h"
#endif

int main(int argc, char **argv)
{
    ARGCHECK(argc);

    const char *filename = argv[1];
    FILE *file;
    Inventory *inv = (Inventory *)calloc(1, sizeof(Inventory));
    char buffer[BUFSIZE]; // user input goes here
    char desc[MAXDESC];
    unsigned int qty;
    float unit_cost;
    float unit_price;
    unsigned int part_num;
    const char *all = "all";
    int continue_loop = 1;
    int result = FAILURE;

    if (inv_exists(filename))
        file = fopen(filename, "r+b");
    else if ((file = fopen(filename, "w+b")) == NULL)
    {
        perror("Error opening file");
        return EXIT_FAILURE;
    }
    else
        new_inv(inv, file);

    while (continue_loop)
    {
        printf("Enter command:\n    new name,qty,unit_cost\n    buy part_num,qty,unit_cost\n    sell part_num,qty,unit_price\n    delete part_num\n    print [part_num|all]\n    total\n    end\n");
        if (fgets(buffer, BUFSIZE, stdin) == NULL)
        {
            perror("Error reading input");
            return EXIT_FAILURE;
        }

        switch (buffer[0])
        {
        case 'n':
            sscanf(buffer, "new %s,%u,%f", desc, &qty, &unit_cost);
            result = new_part(inv, desc, qty, unit_cost);
            break;
        case 'b':
            sscanf(buffer, "buy %u,%u,%f", &part_num, &qty, &unit_cost);
            result = buy_part(inv, part_num, qty, unit_cost);
            break;
        case 's':
            sscanf(buffer, "sell %u,%u,%f", &part_num, &qty, &unit_price);
            result = sell_part(inv, part_num, qty, unit_price);
            break;
        case 'd':
            sscanf(buffer, "delete %u", &part_num);
            result = delete_part(inv, part_num);
            break;
        case 'p':
            if (isalpha(buffer[0] && strcmp(desc, all) == 0))
            {
                sscanf(buffer, "print %s", desc);
                update_totals(inv);
                result = print_all(inv);
            }
            else if (isdigit(buffer[0]))
            {
                sscanf(buffer, "print %u", &part_num);
                result = print_part(inv, part_num);
            }
            else
                result = FAILURE;
            break;
        case 't':
            update_totals(inv);
            result = print_totals(inv);
            break;
        case 'e':
            result = SUCCESS;
            continue_loop = 0;
            break;
        default:
            puts("Invalid command");
        }

        if (result == FAILURE)
        {
            puts("Command failed");
        }
        else if (buffer[0] != 't' || buffer[0] != 'p')
            update_totals(inv);
        else
            printf("%s processed\n", buffer);
    }

    return (byebye(inv, filename) == FAILURE) ? EXIT_FAILURE : EXIT_SUCCESS;
}
