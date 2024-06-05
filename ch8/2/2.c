#include <stdio.h>
#define CAPS                                      \
    {                                             \
        0.0, 23350.0, 56550.0, 117950.0, 256500.0 \
    }
#define RATES                         \
    {                                 \
        0.15, 0.28, 0.31, 0.36, 0.396 \
    }
#define FLAT                                  \
    {                                         \
        3502.50, 12798.50, 31832.50, 81710.50 \
    }
#define BRACKETS 5

/*
 * the us fed income tax for single ppl in 1995 was computed thus:

 taxable income in range (0..23_350) = 15% of taxable income over 0
    taxable income in range (23_350..56_550) = 3_502.50 + 28% of taxable income
    over 23_350
    taxable income in range (56_550..117_950) = 12_798.50 + 31% of taxable
    income over 56_550
    taxable income in range (117_950..256_500) = 31_832.50 + 36% of taxable
    income over 117_950
    taxable income in range (256_500..) = 81_710.50 + 39.6% of taxable income

 * write the fn
 * `income` is taxable income, and fn returns tax due on it.
 */
float tax_due(float income);

int main(void)
{
    float income;
    printf("Enter taxable income: ");
    scanf("%f", &income);
    printf("Tax due: %.2f\n", tax_due(income));
    return 0;
}

float tax_due(float income)
{

    //  there are five tax brackets. each has:
    //      lo range
    //      hi range
    //      an offset
    //      percentage
    //      cutoff = low range of your bracket
    //  in the spirit of the subject matter, we will use a multidimensional array to
    //  represent this data structure.

    // this has been done in the #define statements above.
    // let's use pointers to these brackets and a loop to find the index we
    // should move to in the brackets array.
    const float caps[BRACKETS] = CAPS;
    const float rates[BRACKETS] = RATES;
    const float flat[BRACKETS] = FLAT;

    for (int b = 0; b < BRACKETS; b++)
    {
        if (income < *(caps + b))
        {
            return *(flat + b) + *(rates + b) * (income - *(caps + b - 1));
        }
    }
}
