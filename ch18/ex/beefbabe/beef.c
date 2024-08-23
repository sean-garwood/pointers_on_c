/*
 * Check for the following:
 * 1. Check if the constant is defined in the same file
 * 2. Check if the constant is defined in a different file
 * 3. see if enum or #define is used and how they differ
 */
#include "beef.h"

int main(void)
{
    // declare register variables
    register const int cafe = CAFE;
    register const int beef = BEEF;

    register const int babe = BABE;
    register const int dead = DEAD;

    register int bafe_ceef = cafe_beef();
    register int bead_dabe = dead_babe();

    // store the value of the constants in the register variables
    return 0;
}

int cafe_beef()
{
    return CAFE + BEEF;
}

int dead_babe()
{
    return DEAD - BABE;
}
