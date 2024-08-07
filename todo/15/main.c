#ifndef HEADERS_H
#include "headers.h"
#endif

int main(int argc, const char **argv)
{
    FILE *bin;
    Part *zero = MALLOCPART(zero);
    inv = MALLOCINV(inv);
    char *input[MAXINPUT];
    int result = SUCCESS;

    init_inv(argv[1], bin, zero);
    while (*input != 'q' && result == SUCCESS)
    {
        prompt();
        fgets(*input, MAXINPUT, stdin);
        Trx *trx = new_trx(*input);
        result = trx->op(&trx->trx_data);
        free(trx);
    }
    assert(write_inv() == SUCCESS);
}

void prompt()
{
    printf("Enter transaction\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n",
           "n <id>,<qty>,<cost>,<price> - new part",
           "b <id>,<qty> - buy part",
           "s <id>,<qty> - sell part",
           "d <id> - delete part",
           "p <id> - print part",
           "p - print all parts",
           "q - quit",
           "t - print totals");
}

void goodbye()
{
    printf("Goodbye\n");
}
