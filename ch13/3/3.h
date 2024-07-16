#include <stdlib.h>
#include <stdio.h>

typedef struct transaction
{
    // type of transaction
    // will be passed to callback function to determine what to do
    enum
    {
        NEW,
        DELETE,
        FORWARD,
        BACKWARD,
        SEARCH,
        EDIT
    } type;
    int amount;
    char *date;
    char *description;
} Transaction;

/*
 * copi:

 Given the `Transaction` type definition from the selection, it confirms that
 the `type` field is indeed an enumeration with integer values starting from 0
 for `NEW` and incrementing by 1 for each subsequent value. This setup is
 suitable for indexing into a `jump_table` array where each index corresponds to
 a function pointer for handling the specific transaction type.

Therefore, using `trx->type` as an index to access a specific function in a
`jump_table` array is valid and achieves the same goal as the commented-out
`switch` statement, assuming the `jump_table` is correctly set up with function
pointers in the order that matches the enumeration. This allows for a direct
mapping between the transaction type and the function to be executed, enabling
efficient function dispatch based on the transaction type.
 */

// doubly-linked list of pointers to transactions
typedef struct node
{
    struct transaction *trx;
    struct node *next;
    struct node *prev;
} Node;

// called by main to compare the two functions
// void switch_statement(void);
int jump_table_procedure(void);

// callback functions. take args as void pointers to allow for any type of arg
void add_new_trx(void *list, void *trx);
Node *delete_trx(void *list, void *current);
Node *search(void *list, void *trx);
void forward(void *current);
void backward(void *current);
void edit(void *current, void *trx);
