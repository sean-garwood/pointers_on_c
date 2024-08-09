#ifndef HEADERS_H
#include "headers.h"
#endif

int main(int argc, const char **argv)
{
    int result = SUCCESS;
    char input[MAXINPUT];
    const char *filename = argv[1];
    Trx *trx = MALLOCTRX(trx);

    init_inv(filename);

    while (result == SUCCESS)
    {
        prompt();
        fgets(input, MAXINPUT, stdin);
        result = process_trx(trx, input);
    }
    assert(write_inv(filename) == SUCCESS);
    return free_memory(trx);
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
