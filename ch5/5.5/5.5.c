/* write a fn that will store a given value into specified bit positions of an int.*/
#include <stdio.h>
#include <stdlib.h>

#define NARGS 5

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
    printf("after shifting v_t %d bits left: %d\n", i, v_t);
    printf("    v_m: %d\n", v_m);
}

int main(unsigned argc, char *argv[])
{
    // print info if not enough args
    if (argc != NARGS)
    {
        info();
        return 1;
    }
    unsigned v_0 = atoi(argv[1]);
    unsigned v_t = atoi(argv[2]);
    unsigned i = atoi(argv[3]);
    unsigned j = atoi(argv[4]);

    unsigned v_m = v_0;
    unsigned m = mask(i, j);

    v_m &= ~m; // zero out digits in range i to j by applying the ones complement of the mask to v_m
    v_t <<= i; // insert the value v_t into the range i to j
    v_t &= m; // mask v_t
    v_m |= v_t; // OR v_t with v_m
    result(v_0, v_t, i, j, v_m);
    return 0;
}
