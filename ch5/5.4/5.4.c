#include <stdio.h>
#define Z80 8 // for NES microprocessor
/* write functions that implement an array of bits with the following
prototypes:
*/
void set_bit(char bit_array[], unsigned bit_number);
// set specified bit to one
void clear_bit(char bit_array[], unsigned bit_number);
// clears specified bit
void assign_bit(char bit_array[], unsigned bit_number, int value);
// sets bit to 0 if value is zero
int test_bit(char bit_array[], unsigned bit_number);
/* returns 1 if speified bit is nonzero, else returns false.

the first arg in each fn is a char array in which the bits are stored.
       second arg id's the bit to be accessed.
*/
int main(void)
{
    char bit_array[Z80]; // kind of weird to use a char array? why not int?
    unsigned bit_number;
    printf("Hi Mario. Set a bit.\n");
    // set a bit
    set_bit(bit_array, 0);
    // print the bit array
    // printf("ok mario, let's clear it.");
    // clear_bit(bit_array, 0);
    printf("here's the bits from low to high: %d\n", bit_array[0]);
}

void set_bit(char bit_array[], unsigned bit_number)
{
    bit_array[bit_number] = 1;
}

void clear_bit(char bit_array[], unsigned bit_number)
{
    bit_array[bit_number] = 0;
}

void assign_bit(char bit_array[], unsigned bit_number, int value)
{
    bit_array[bit_number] = value;
}

int test_bit(char bit_array[], unsigned bit_number)
{
    return bit_array[bit_number] == 1;
}
