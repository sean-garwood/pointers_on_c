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
    int something_random = 2457;
    print_ledger(something_random);
    return 0;
}

void print_ledger(int some_random_int_that_isnt_a_flag)
{
#ifdef DEFAULT
    print_ledger_default(some_random_int_that_isnt_a_flag);
#endif
#ifdef DETAILED
    print_ledger_detailed(some_random_int_that_isnt_a_flag);
#endif
#ifdef LONG
    print_ledger_long(some_random_int_that_isnt_a_flag);
#endif
}

void print_ledger_default(int crap)
{
    puts("DEFAULT LEDGER: ...");
    printf("crap: %d\n", crap);
}

void print_ledger_detailed(int crap)
{
    puts("DETAILED LEDGER: ...\n");
    printf("crap: %d\n", crap);
}

void print_ledger_long(int crap)
{
    puts("LONG LEDGER: ...\n");
    printf("crap: %d\n", crap);
}
