/*
 * a company markets a program that handles financial trx and prints reports
 * about them. to broaden the market, the program is sold in several editions,
 * each with various combos of options.
 *
 * Implement the code for certain printing function so that it can be easily
 * compiled to produce the diff vers of the program.
 *
 * the fn will be named `print_ledger`. it takes a single `int` arg, and does
 * not return any value.
 *
 * It should call one or more of the following functions depending on which (if
 * any) symbols are defined when the function is compiled:
 *
 * | if this is defined... | then call this fn |
 * |-----------------------|-------------------|
 * | OPTION_LONG           | print_ledger_long |
 * | OPTION_DETAILED       | print_ledger_detailed |
 *
 * if neither is defined, call `print_ledger_default`.
 */

#include "1.h"

int main(void)
{
    // test
    print_ledger(0);
    return 0;
}

void print_ledger(int option)
{
    /*
     * option codes:
     * 0 - default
     * 1 - detailed
     * 2 - long
     * 3 - detailed and long
     */

    switch (option)
    {
    case 0:
        print_ledger_default(option);
        break;
    case 1:
        print_ledger_detailed(option);
    case 2:
        print_ledger_long(option);
        break;
    }
}
