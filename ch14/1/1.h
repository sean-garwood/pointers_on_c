#include <stdio.h>

#ifndef OPTION_LONG
#ifndef OPTION_DETAILED
#include "print_ledger_default.h"
#endif
#endif

#ifdef OPTION_LONG
#include "print_ledger_long.h"
#endif

#ifdef OPTION_DETAILED
#include "print_ledger_detailed.h"
#endif

void print_ledger(int some_random_int_that_isnt_a_flag);
