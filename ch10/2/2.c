/*
 * write a declaration for an information system that records sales at an auto
 * dealer. the following data must be saved for every sale:
 *
 * * custermer's name (string length 20)
 * * customer's address (string length 40)
 * * model name (string length 20)
 *
 * the maximum length of the string values given does not include space for the
 * terminating NUL byte.
 *
 * Three different types of transactions are possible:
 *
 * 1. all cash sales
 * 2. sales with a loan
 * 3. leases
 *
 * for cash saels, the following info is saved:
 *
 * * MSRP (float)
 * * sale price (float)
 * * sales tax (float)
 * * license fee (float)
 *
 * for leases:
 *
 * * MSRP (float)
 * * sale price (float)
 * * down payment (float)
 * * monthly payment (float)
 * * lease term (in months) (int)
 * * security deposit (float)
 *
 * for sales with a loan:
 *
 * * msrp (float)
 * * sale price (float)
 * * sales tax (float)
 * * license fee (float)
 * * down payment (float)
 * * loan duration (in months) (int)
 * * interest rate (float)
 * * monthly payment (float)
 * * name of lending institution (string length 20)
 */

#include "../10.2.h"

int main(void)
{
    Customer customer = {
        .name = "John Doe",
        .address = "1234 Elm St, Springfield, IL 62701",
        .model = "Toyota Corolla"};

    Sale sale = {
        .customer = customer,
        .msrp = 20000.00,
        .sale_price = 18000.00};

    LoanDetails loan_details = {
        .lender = "Bank of Springfield",
        .loan_duration = 60,
        .sales_tax = 300.00,
        .down_payment = 1000.00,
        .monthly_payment = 5000.00,
        .interest_rate = 0.05};

    Transaction transaction = {
        .sale = sale,
        .details.loan = loan_details, // Correctly assign to the union member
        .type = LOAN};

    print_sale_transaction(&transaction);
    return 0;
}

void print_sale_transaction(Transaction *trx)
{
    printf("Sale Transaction\n");
    printf("Customer: %s\n", trx->sale.customer.name);
    printf("Address: %s\n", trx->sale.customer.address);
    printf("Model: %s\n", trx->sale.customer.model);
    printf("MSRP: %.2f\n", trx->sale.msrp);
    printf("Sale Price: %.2f\n", trx->sale.sale_price);

    switch (trx->type)
    {
    case LEASE:
        print_lease_details(&trx->details.lease);
        break;
    case LOAN:
        print_loan_details(&trx->details.loan);
        break;
    default:
        break;
    }
}

void print_lease_details(LeaseDetails *lease_details)
{
    printf("Lease Details\n");
    printf("Down Payment: %.2f\n", lease_details->down_payment);
    printf("Monthly Payment: %.2f\n", lease_details->monthly_payment);
    printf("Lease Term: %d months\n", lease_details->lease_term);
    printf("Security Deposit: %.2f\n", lease_details->security_deposit);
}

void print_loan_details(LoanDetails *loan_details)
{
    printf("Loan Details\n");
    printf("Down Payment: %.2f\n", loan_details->down_payment);
    printf("Monthly Payment: %.2f\n", loan_details->monthly_payment);
    printf("Interest Rate: %.2f\n", loan_details->interest_rate);
    printf("Loan Duration: %d months\n", loan_details->loan_duration);
    printf("Lender: %s\n", loan_details->lender);
}
