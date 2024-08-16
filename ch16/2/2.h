#ifndef _2_H
#define _2_H

#include <time.h>

#define SIDES 6
#define MIN 1
#define MAX (SIDES)
#define SEED(first_time)              \
    if (first_time)                   \
    {                                 \
        first_time = 0;               \
        srand((unsigned int)time(0)); \
    }
#define TRIALS 1000000000
int roll_die();

#endif // _2_H
