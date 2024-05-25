/* write a fn that will store a given value into specified bit positions of an int.*/
#include <stdio.h>
#include <stdlib.h>

#define DEBUG 1
#define NARGS 5

unsigned checkargs(unsigned argc, char *argv[]);
void info();

unsigned mask(unsigned i, unsigned j);
void result(unsigned i, unsigned j, unsigned v_0, unsigned v_t, unsigned v_m);

unsigned mask(unsigned i, unsigned j)
{
    unsigned mask = 0;
    for (unsigned k = i; k <= j; k++)
        mask |= 1 << k;
    return mask;
}

unsigned checkargs(unsigned argc, char *argv[])
{
    if (DEBUG)
    {

        argv[1] = 15;
        argv[2] = 0;
        argv[3] = 0;
        argv[4] = 3;

        printf("============-DEBUG MODE-============\n");
        printf("argv[1]: v_0 set to %d\n", argv[1]);
        printf("argv[2]: v_t set to %d\n", argv[2]);
        printf("argv[3]: i set to %d\n", argv[3]);
        printf("argv[4]: j set to %d\n", argv[4]);
    }
    else if (argc != NARGS)
    {
        info();
        return 1;
    }
    else if (atoi(argv[3]) > atoi(argv[4]))
    {
        printf("i must be less than j\n");
        return 1;
    }
    else if (atoi(argv[3]) < 0 || atoi(argv[4]) > 31)
    {
        printf("i and j must be between 0 and 31\n");
        return 1;
    }
    else
        ;
    return 0;
}

void info()
{
    printf("Usage: ./5.5 <v_0> <v_t> <i> <j>\n");
    printf("    v_0: original value\n");
    printf("    v_t: value to insert\n");
    printf("    i: starting bit\n");
    printf("    j: ending bit\n");
}

void result(unsigned v_0, unsigned v_t, unsigned i, unsigned j, unsigned v_m)
{
    printf("v_0: %d\n", v_0);
    printf("v_t: %d\n", v_t);
    printf("i: %d\n", i);
    printf("j: %d\n", j);
    printf("after shifting v_t%d bits left: %d\n", i, v_t);
    printf("    v_m: %d\n", v_m);
    printf("    v_m in binary: ");
    for (unsigned k = 31; k >= 0; k--)
    {

        printf("%d", (v_m >> k) & 1);
        k == 0 ? printf("\n") : 0;
        k % 4 == 0 ? printf(" ") : 0;
    }
}

int main(unsigned argc, char *argv[])
{
    if (checkargs(argc, *argv))
        return 1;

    unsigned v_0 = atoi(argv[1]);
    unsigned v_t = atoi(argv[2]);
    unsigned i = atoi(argv[3]);
    unsigned j = atoi(argv[4]);

    unsigned v_m;
    v_m = v_0 & ~mask(i, j);
    printf("v_m: %d\n", v_m);
    v_m |= (v_t << i); // shift v_t i bits to the left and OR with
    v_m |= v_0;
    result(v_0, v_t, i, j, v_m);
    return 0;
}
