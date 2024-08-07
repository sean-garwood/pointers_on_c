#ifndef HEADERS_H
#define HEADERS_H

#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#ifndef PART_H
#include "part.h"
#endif
#ifndef INV_H
#include "inv.h"
#endif
#ifndef TRX_H
#include "trx.h"
#endif

#define ARGCHECK(x)                      \
    if ((x) != 2)                        \
    {                                    \
        puts("Usage: ./inv <filename>"); \
        return EXIT_FAILURE;             \
    }
#define SUCCESS 0
#define FAILURE 1
#define TRUE 1
#define FALSE 0
#define MAXDESC 21
#define MAXINPUT 100 // most stdin will take

void debug(Trx *trx);
#endif
