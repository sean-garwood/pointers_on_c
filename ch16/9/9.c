#include "9.h"

/*
 * what are the odds of 2 students in a class of 30 sharing the same birthday?

 How big would a group of people have to be for the odds of any 2 of them
 sharing a bday to be 50%?

 write a program to determine answers.

 get 30 random ints and take them mod 365 to represent the bdays of the
 students.

 check to see if numbers match

 repeat test 10k times to get estimate for odds

 to answer second question, mod program so it will accept group size as cli. set
 rng with time of day, run program several times.
 */

int main(int argc, char **argv)
{
    if (argc == 1)
        printf("group size set to %d\n", INITGROUP);
    else if (argc == 2)
        printf("group size set to %s\n", argv[1]);
    else
    {
        printf("usage: %s [group size]\n", argv[0]);
        return 1;
    }

    srand(time(NULL));

    int i, j, match, count;
    float odds;
    int group_size = (argc == 2) ? atoi(argv[1]) : INITGROUP;
    int *group = malloc(group_size * sizeof(int));
    if (group == NULL)
    {
        fprintf(stderr, "malloc failed\n");
        return 1;
    }

    count = 0;
    for (i = 0; i < N; ++i)
    {

        match = 0;

        for (j = 0; j < group_size; ++j)
            group[j] = rand() % DAYS;

        for (j = 0; j < group_size; ++j)
        {
            for (int k = j + 1; k < group_size; ++k)
            {
                if (group[j] == group[k])
                {
                    ++match;
                    break;
                }
            }
        }

        if (match > 0)
            ++count;
    }
    odds = (float)count / N;
    printf("odds of 2 students sharing a birthday in a class of %d: %f\n", group_size, odds);

    return 0;
}
