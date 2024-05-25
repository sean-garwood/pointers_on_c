/* write a fn that will store a given value into specified bit positions of an int.*/
#include <stdio.h>
#include <stdlib.h>

#define NARGS 5

int checkargs(int argc);
void info();
int get_mask(int i, int j);
int mask_value(int i, int j, int v_0);
int insert_v_t(int i, int v_t, int *v);
int or_v0(int v_0, int *v);
void result(int i, int j, int v_0, int v_t, int v_m);

int get_mask(int i, int j)
{
    int mask = 0;
    for (int k = i; k <= j; k++)
        mask |= 1 << k;
    return mask;
}

int mask_value(int i, int j, int v_0)
{
    return (v_0 & get_mask(i, j));
}

int insert_v_t(int i, int v_t, int *v)
{
    return *v | (v_t << i); // shift v_t i bits to the left and OR with
}

int or_v0(int v_0, int *v)
{
    return (*v | v_0);
}

int checkargs(int argc)
{
    argc != NARGS ? info() : 0;
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

void result(int v_0, int v_t, int i, int j, int v_m)
{
    printf("v_0: %d\n", v_0);
    printf("v_t: %d\n", v_t);
    printf("i: %d\n", i);
    printf("j: %d\n", j);
    printf("after shifting v_t%d bits left: %d\n", i, v_t);
    printf("    v_m: %d\n", v_m);
    printf("    v_m in binary: ");
    for (int k = 31; k >= 0; k--)
    {

        printf("%d", (v_m >> k) & 1);
        k == 0 ? printf("\n") : 0;
        k % 4 == 0 ? printf(" ") : 0;
    }
}

int main(int argc, char *argv[])
{
    if (checkargs(argc)) return 1;

    int v_0 = atoi(argv[1]);
    int v_t = atoi(argv[2]);
    int i = atoi(argv[3]);
    int j = atoi(argv[4]);

    int v_m = mask_value(i, j, v_0);
    v_m = insert_v_t(i, v_t, &v_m);
    v_m = or_v0(v_0, &v_m);
    result(v_0, v_t, i, j, v_m);
    return 0;
}
