#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int not_print_flag(int ch); // flag for non-printable characters

// jump table of character categories
// the main function will use this table to determine the category of each
// character by looping through it and calling the appropriate function
static int (*compare[])(int) = {
    iscntrl,
    isspace,
    isdigit,
    islower,
    isupper,
    ispunct,
    not_print_flag};

// total number of categories
// needed to cast it to an int in the main function
// this is because the size of the array is a size_t
// any way to do this in the header file?
// I don't think so
#define N_CATEGORIES (sizeof(compare) / sizeof(compare[0]))

// printable category names
char *category_names[] = {
    "control",
    "whitespace",
    "digit",
    "lowercase",
    "uppercase",
    "punctuation",
    "non-printable"};

// count of characters in each category
int count[N_CATEGORIES];
