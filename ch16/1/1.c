
/*
 *
 * A popular joke among nerds is to say, "my age is 29, but i'm not telling you
 * the base of that number!"
 *
 * Write program that takes age as a cli and computes the smallest radix/base
 * in range 2..36 in which the age appears to be a number less than or equal to 29.
 *
 * For example, if user enters 41, the program should say to use base 16, because
 * 41 in base 16 is 29.
 *
 */

#include "../headers.h"

int check_args(int argc, const char **argv)
{

    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <age>\n", argv[0]);
        return 1;
    }
    else if (atoi(argv[1]) < MINAGE)
    {
        fprintf(stderr, "Age must be a positive number\n");
        return 1;
    }
    else if (atoi(argv[1]) > MAXAGE)
    {
        fprintf(stderr, "Age must be less than %d\n", MAXAGE);
        return 1;
    }
    return 0;
}

int main(int argc, const char **argv)
{
    if (check_args(argc, argv))
        return 1;

    int age = atoi(argv[1]);
    int init_min_base = ((age - 9) / 2);
    int min_base = ((init_min_base % 2) == 0) ? init_min_base : init_min_base + 1;

    printf("Age: %d\n", age);
    printf("smallest base: %d\n", min_base);
    printf("%s in base %d: %lu\n",
           TWENTYNINE, min_base, strtoul(TWENTYNINE, NULL, min_base));

    return 0;
}
