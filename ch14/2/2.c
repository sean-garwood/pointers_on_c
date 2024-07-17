/* write a fn that returns a value indicating the type of computer on which it
 * is running. The fn will be used in a prg that runs on a bunch of comps
 *
 * Use conditional compilation to accomplish this 'magic'.
 *
 * Fn should be called `cpu_type` and doesn't take args
 *
 * | if this is defined... | then return this value |
 * |-----------------------|------------------------|
 * | VAX                   | CPU_VAX                |
 * | M68000                | CPU_68000              |
 * | I80386                | CPU_80386              |
 * | M68020                | CPU_68020              |
 * | X6809                 | CPU_6809               |
 * | X6502                 | CPU_6502               |
 * | U3B2                  | CPU_3B2                |
 *
 * when compiled, one of the symbols in the 'defined' col in the table may be
 * defined.
 *
 * Return the corresponding value in the 'then return this value' col.
 *
 * If none of the symbols are defined, return `CPU_UNKNOWN`.
 *
 * If more than one of the symbols was defined, the result is undefined.
 *
 * The symbols in the 'returned value' col will be `#define`d  as various int
 * values in an include file called `cpu_types.h`. */

#include "cpu_types.h"

int cpu_type(void)
{
#if defined(VAX)
    return CPU_VAX;
#elif defined(M68000)
    return CPU_68000;
#elif defined(I80386)
    return CPU_80386;
#elif defined(M68020)
    return CPU_68020;
#elif defined(X6809)
    return CPU_6809;
#elif defined(X6502)
    return CPU_6502;
#elif defined(U3B2)
    return CPU_3B2;
#else
    return CPU_UNKNOWN;
#endif
}
