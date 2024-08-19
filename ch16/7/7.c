/*
 * well-designed rng return values that appear to be random, yet are uniform
 * over time.
 *
 * Numbers derived from the random values should also have these properties.
 *
 * For ex: poorly designed rng might return values that appear random but
 * alternate between even and odd.
 *
 * Another faw would be a generator that returned only odd values.
 *
 * Write a program to test the rng on your system. generate 10,000 random
 * numbers and perform two types of test:
 *
 * 1. frequency
 *
 * take each random number modulo 2 and count how man times the result is zero
 * and one. do the same for mods 3 through 10. the results will not be precisely
 * uniform, but there would not be any large peaks or valleys in the frequencies.
 *
 * 2. cyclic frequency
 *
 * Take each random num and the preceding one mod two. Use these remainders as
 * the subscripts of a 2-d array and increment the specified location. repeat
 * for mod 3-10. the results should be uniformly distributed.
 *
 * Modify the program so that you can provide different values to seed the rng,
 * and run tests with several seeds. how good is it?
 */

#include "../headers.h"

const int mods[] = MODS;
int numbers[N];

void generate_10k_numbers()
{
    for (int i = 0; i < N; i++)
    {
        numbers[i] = rand();
    }
}

int main(void)
{
    /*
     * generate 10k random numbers
     *     seed? no, we want to test the rng
     * perform
     *     frequency test
     *          take each random number modulo 2 and count how many times the result is zero and one
     *          repeat for mods 3-10
     *     cyclic frequency test
     */
    int i, j, divisor, remainder, prev_remainder, curr_remainder;
    int freq[MINMOD];
    const int divisors[NTEST] = MODS;
    int cyclic_freq[10][10] = INITARR;

    generate_10k_numbers(numbers);

    for (i = 0; i < NTEST; i++)
    {
        memset(freq, 0, sizeof(freq));
        divisor = divisors[i];
        // check frequency for this mod
        for (j = 0; j < N; j++)
        {
            remainder = numbers[j] % divisor;
            if (remainder > 1 || remainder < 0)
                continue;
            freq[remainder]++;
        }
        printf("Frequency test for mod %d\n", divisor);
        for (j = 0; j < MINMOD; j++)
        {
            printf("remainder %d: %d\n", j, freq[j]);
        }
    }

    for (i = 0; i < NTEST; i++)
    {
        divisor = divisors[i];
        for (j = 1; j < N; j++)
        {
            prev_remainder = numbers[j - 1] % divisor;
            curr_remainder = numbers[j] % divisor;
            cyclic_freq[prev_remainder][curr_remainder] = cyclic_freq[prev_remainder][curr_remainder] + 1;
        }
    }

    for (i = 0; i < NTEST; i++)
    {
        printf("Cyclic frequency test for mod %d\n", divisors[i]);
        for (j = 0; j < NTEST; j++)
        {
            printf("%d ", cyclic_freq[i][j]);
        }
        printf("\n");
    }

    return 0;
}
