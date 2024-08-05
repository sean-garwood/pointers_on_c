#ifndef HEADERS_H
#include "headers.h"
#endif

int main(int argc, const char **argv)
{
    ARGCHECK(argc);

    const char *filename = argv[1];
    Part *zero;

    inv = init_inventory(open_file(filename));

    zero = init_part_zero();
    if (inv->zero == NULL)
    {
        inv->zero = zero;
    }
    assert(inv->zero == zero);
    assert(zero != NULL);

    return 0;
}
