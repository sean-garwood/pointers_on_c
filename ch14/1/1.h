#ifndef OPTION_LONG
#ifndef OPTION_DETAILED
#include "print_ledger_default.h"
#endif
#endif

#ifdef OPTION_LONG
#ifndef OPTION_DETAILED
#include "print_ledger_long.h"
#endif
#endif

#ifdef OPTION_DETAILED
#ifndef OPTION_LONG
#include "print_ledger_detailed.h"
#endif
#endif

#ifdef OPTION_LONG
#ifdef OPTION_DETAILED
#include "print_ledger_long.h"
#include "print_ledger_detailed.h"
#endif
#endif

void print_ledger(int option_flag);

typedef enum option_flags
{
    DEFAULT_FLAG = 0,
    DETAILED_FLAG = 1,
    LONG_FLAG = 2,
    BOTH_FLAG = 3
} OptionFlags;
