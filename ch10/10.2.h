#include "10.h"

#define SHORTSTR 20
#define LONGSTR 40

typedef struct Customer
{
    char address[LONGSTR];
    char name[SHORTSTR];
    char model[SHORTSTR];
} Customer;

typedef struct Sale
{
    Customer customer;
    float msrp;
    float sale_price;
} Sale;

typedef struct LeaseDetails
{
    int lease_term;
    float down_payment;
    float monthly_payment;
    float security_deposit;
} LeaseDetails;

typedef struct LoanDetails
{
    char lender[SHORTSTR];
    float sales_tax;
    float down_payment;
    float monthly_payment;
    float interest_rate;
    int loan_duration;
} LoanDetails;

typedef union LeaseOrLoan
{
    LeaseDetails lease;
    LoanDetails loan;
} LeaseOrLoan;

typedef enum SaleType
{
    LEASE,
    LOAN
} SaleType;

typedef struct Transaction
{
    Sale sale;
    LeaseOrLoan details;
    SaleType type;
} Transaction;

void print_sale_transaction(Transaction *trx);
void print_lease_details(LeaseDetails *lease_details);
void print_loan_details(LoanDetails *loan_details);
