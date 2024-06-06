#include <stdio.h>
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
    // get income
    float income;
    printf("Enter taxable income: ");
    scanf("%f", &income);
    printf("Tax due: %.2f\n", tax_due(income));
    return 0;
}

float tax_due(float income)
{
    const float rates[][3] = {
        {0, 0, 0.15}, // flat rate, floor, rate
        {23350, 3502.5, 0.28},
        {56550, 12798.5, 0.31},
        {117950, 31832.5, 0.36},
        {256500, 81710.5, 0.396}};
    const int num_brackets = sizeof(rates) / sizeof(rates[0]);
    float tax = 0.0;

    for (int i = num_brackets - 1; i >= 0; i--)
    {
        if (income > rates[i][0])
        {
            tax = rates[i][1] + (income - rates[i][0]) * rates[i][2];
            break;
        }
    }

    return tax;
}
