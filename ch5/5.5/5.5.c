/* write a fn that will store a given value into specified bit positions of an int.*/
#include <stdio.h>
#include <stdlib.h>

#define NARGS 5

int checkargs(int argc, char *argv[], int debug);
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

int checkargs(int argc, char *argv[], int debug)
{
    if (debug)
    {
        printf("============-DEBUG MODE-============\n");

        argv[1] = "15";
        argv[2] = "0";
        argv[3] = "0";
        argv[4] = "3";

        printf("argv[1]: v_0 set to %s\n", argv[1]);
        printf("argv[2]: v_t set to %s\n", argv[2]);
        printf("argv[3]: i set to %s\n", argv[3]);
        printf("argv[4]: j set to %s\n", argv[4]);
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
    int debug = 1;
    if (checkargs(argc, argv, debug))
        return 1;

    int v_0 = atoi(argv[1]);
    int v_t = atoi(argv[2]);
    int i = atoi(argv[3]);
    int j = atoi(argv[4]);

    int v_m = mask_value(i, j, v_0);
    printf("v_m: %d\n", v_m);
    v_m = insert_v_t(i, v_t, &v_m);
    v_m = or_v0(v_0, &v_m);
    result(v_0, v_t, i, j, v_m);
    return 0;
}
