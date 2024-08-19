#ifndef _HEADERS_H
#include "../headers.h"
#endif // _HEADERS_H
/*
 * the formula for determining the monthly payment for a mortgage is
 *
 * P = A*I / (1 - (1 + I)^-N)
 *
 * A: loan amount
 * I: interest
 * N: num of periods
 *
 * Write the function with the following prototype to compute the monthly payment:
 */

double payment(double amount, double interest, int years);

/*
 * `years` specifies the duration of the loan
 * `amount` is the amount of the loan
 * `interest` is the annual interest rate
 * return value is the monthly payment, rounded to nearest penny.
 */

double payment(double amount, double interest, int years)
{
    double rate = interest / 100 / 12;
    int months = years * 12;

    return amount * rate / (1 - pow(1 + rate, -months));
}

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        fprintf(stderr, "Usage: %s amount interest years\n", argv[0]);
        return 1;
    }

    double amount = atof(argv[1]);
    double interest = atof(argv[2]);
    int years = atoi(argv[3]);
    double payment_amount = payment(amount, interest, years);

    printf("Monthly payment: %.2f\n", payment_amount);

    return 0;
}
