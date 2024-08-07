#ifndef HEADERS_H
#include "headers.h"
#endif

int main(int argc, const char **argv)
{
    ARGCHECK(argc);

    const char *filename = argv[1];
    FILE *bin; // pointer to bin file from filename
    /***************************************************************************/
    // open the file
    bin = fopen(filename, "wb+");
    if (bin == NULL)
    {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    // fread the inventory from the file
    // we don't know if the file is empty!!!
    // so we need to check for EOF
    // if the file is empty, we need to create a new inventory
    // if the file is not empty, we need to read the inventory

    // check if empty
    make_inv(bin);
    debug();

    return SUCCESS;
}
