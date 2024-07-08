#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 10000
#define MAX_LL_LEN 5

void *my_calloc(size_t n, size_t size);
int *get_ints(void);
char *copy_string_to_alloc(void);

typedef struct node
{
    int value;
    struct node *next;
} node;
